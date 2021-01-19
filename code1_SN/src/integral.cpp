/*****************************/
/*                                                      */
/*       Created by Jiawei Guo          */
/*        Shandong University            */
/*                                                      */
/*****************************/

#include <iostream>
#include <fstream>
#include <cmath>

#include "TROOT.h"
#include "TStyle.h"
//#include "TSystem.h"
#include "TString.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TF1.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TLegend.h"
#include "Math/Interpolator.h"

#include "integral.h"
#include "xsection.h"

Integral::Integral(){
}

Integral::~Integral(){
}

void Integral::set_hist(TString hist_name){
    h0 =(TH1D *) fs->Get(hist_name);
    
}


void Integral::set_flux_point(){
    
    int j =1;
    
    for(int k= 0; k<300; k++){
        if(h0->GetBinContent(k) != 0.0){
            flux_point[j] = h0->GetBinContent(k);
            j++;
            if(j==21){break;}
        }
    
    }
}

void Integral::numerical_int(TString hist_name, TFile * root_name){
    
    ROOT::Math::Interpolator * interpolation = new ROOT::Math::Interpolator(E_point, flux_point, ROOT::Math::Interpolation::kLINEAR);
    
    int nbin1 = 1000;//neuE
    int nbin2 = 10000;//recoil
    
    TString flux_neuE_name = hist_name + "_flux";
    TString spectrum_recE_name = hist_name + "_recoil";
    
    TH1D * h_flux_neuE = new TH1D(flux_neuE_name, flux_neuE_name, nbin1, 0.0, 300.0); // unit MeV
    TH1D * h_spectrum_recE = new TH1D(spectrum_recE_name, spectrum_recE_name, nbin2, 1.0e-3, 100.0);//unit keV
    
    h_flux_neuE->SetDirectory(root_name);
    h_spectrum_recE->SetDirectory(root_name);
    
    for(int i=0; i<nbin1; i++){
        
        Double_t x = i * 300.0/nbin1;
        Double_t y = interpolation->Eval(x);
        h_flux_neuE->Fill(x, y);
        
    }
    for(int i=0; i<nbin1; i++){
        h_flux_neuE->SetBinError(i, 0.0);
    }
    
    h_flux_neuE->GetXaxis()->SetTitle("E_{#nu} (MeV)");
    h_flux_neuE->GetYaxis()->SetTitle("Flux (s.MeV)^{-1}(cm)^{-2}");
    
    Double_t xs;
    Double_t neuE_min;
    Double_t recoil_E;
    Double_t neutrino_E;
    Double_t mass_xenon = 131.293 * 1.66e-24 /1.8 * 1e27 * 1e3;//unit: keV
    
    TH1D * temp = new TH1D("temp", "temp", nbin1, 0.0, 300.0);
//    temp->SetDirectory(root_name);
    
    Double_t integral;
    
    for(int i=0; i<nbin2; i++){
        
        recoil_E = i * 100.0/nbin2 + 1.0e-3;//keV
//        recoil_E = 10.0;
        neuE_min = sqrt(mass_xenon * recoil_E / 2)/1000.0;//MeV
    
        for(int j=1; j<nbin1; j++){
            
            neutrino_E = j * (300.0-neuE_min)/nbin1 + neuE_min;//MeV
            
            Xsection* xs_calculation = new Xsection();
            xs = xs_calculation->xs_recE(neutrino_E, recoil_E);
            
            temp->Fill(neutrino_E, interpolation->Eval(neutrino_E) * xs);
            
        }
        
        integral = temp->Integral(temp->GetBin(neuE_min), temp->GetBin(nbin2));
        h_spectrum_recE->Fill(recoil_E, integral*num_Xe_ton/1000.0);
        
        temp->Reset();
    }
    
    for(int i=0; i<nbin2; i++){
        h_spectrum_recE->SetBinError(i, 0.0);
    }
    
    h_spectrum_recE->GetXaxis()->SetTitle("E_{r} (keV)");
    h_spectrum_recE->GetYaxis()->SetTitle("Event rate (ton.s.MeV)^{-1}");
    
    std::cout<<"The recoil energy spectrum is finished."<<std::endl;
    
}



