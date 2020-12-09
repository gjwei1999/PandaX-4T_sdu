#include <iostream>
#include <fstream>
#include <cmath>

#include "TROOT.h"
#include "TStyle.h"
//#include "TSystem.h"
#include "TString.h"
#include "TFile.h"
//#include "TTree.h"
#include "TF1.h"
#include "Math/Functor.h"
#include "Math/WrappedTF1.h"
#include "Math/GSLIntegrator.h"
#include "Math/Interpolator.h"
#include "Math/WrappedParamFunction.h"
#include "Math/Integrator.h"
#include "Math/IntegratorMultiDim.h"
#include "Math/AllIntegrationTypes.h"
#include "Math/SpecFuncMathCore.h"
#include "TCanvas.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TLegend.h"

#include "spectrum.h"
#include "xsection.h"
#include "quasi_FD.h"

Spectrum::Spectrum(){
}

Spectrum::~Spectrum(){
}

void Spectrum::time_spectrum(TString filename, TFile *rootfile){
    
    TString hist_name1(filename(4,4)); //get 
    
    TString hist_time_name_e = hist_name1 + "e";
    TString hist_time_name_antie = hist_name1 + "antie";
    TString hist_time_name_x = hist_name1 + "x";
    
//    TString hist_time_energy_name_e = hist_name1 + "T-E-" + "e";
//    TString hist_time_energy_name_antie = hist_name1 + "T-E-" + "antie";
//    TString hist_time_energy_name_x = hist_name1 + "T-E-" + "x";
    
    TH1D* h_time_e = new TH1D(hist_time_name_e, hist_time_name_e, nbin, tmin, tmax);
    TH1D* h_time_antie = new TH1D(hist_time_name_antie, hist_time_name_antie, nbin, tmin, tmax);
    TH1D* h_time_x = new TH1D(hist_time_name_x, hist_time_name_x, nbin, tmin, tmax);
    
//    TH2D * h_time_energy_e = new TH2D(hist_time_energy_name_e, hist_time_energy_name_e, 500, tmin, tmax, 50, neu_Emin, neu_Emax); 
//    TH2D * h_time_energy_antie = new TH2D(hist_time_energy_name_e, hist_time_energy_name_e, 500, tmin, tmax, 50, neu_Emin, neu_Emax); 
//    TH2D * h_time_energy_x = new TH2D(hist_time_energy_name_e, hist_time_energy_name_e, 500, tmin, tmax, 50, neu_Emin, neu_Emax); 
    
    h_time_e->SetDirectory(rootfile);
    h_time_antie->SetDirectory(rootfile);
    h_time_x->SetDirectory(rootfile);
    
//    h_time_energy_e->SetDirectory(rootfile);
//    h_time_energy_antie->SetDirectory(rootfile);
//    h_time_energy_x->SetDirectory(rootfile);
    
    TString file = path1 + filename;
     std::ifstream infile(file);
     
     double time, neu_energy0, neu_energy1, dN_dE_e, dN_dE_antie, dN_dE_x, temp;
     int k=0;
     Xsection* xs_calculation = new Xsection();
     double xs;
     double N_time[3]={0.0}; // 0: electron_neutrino; 1: anti-electron neutrino; 2: x neutrino
     
     while(infile >> time)
     {
         
         for(int i = 1; i <21; i++)
         {
             infile >> neu_energy0 >> neu_energy1 >> dN_dE_e >> dN_dE_antie >> dN_dE_x >> temp >> temp >> temp;
             
             xs = xs_calculation->cross_section(neu_energy1);
             
             N_time[0] = N_time[0] + xs * (neu_energy1 - neu_energy0) *dN_dE_e;
             N_time[1] = N_time[1] + xs * (neu_energy1 - neu_energy0) *dN_dE_antie;
             N_time[2] = N_time[2] + xs * (neu_energy1 - neu_energy0) *dN_dE_x;
             
//             h_time_energy_e->Fill(time, neu_energy1, dN_dE_e * xs);
//             h_time_energy_antie->Fill(time, neu_energy1, dN_dE_antie * xs);
//             h_time_energy_x->Fill(time, neu_energy1, dN_dE_x * xs);
             
        }
        
        h_time_e->Fill(time, N_time[0]);
        h_time_antie->Fill(time, N_time[1]);
        h_time_x->Fill(time, N_time[2]);
        
        N_time[0] = 0.0;
        N_time[1] = 0.0;
        N_time[2] = 0.0;
        
        if(k%50==0){std::cout<<"k == "<<k<<std::endl;}
        k++;
    }
    
    h_time_e->Scale(1/4.0/M_PI/D/D);
    h_time_antie->Scale(1/4.0/M_PI/D/D);
    h_time_x->Scale(1/4.0/M_PI/D/D);
    
//    h_time_energy_e->Scale(1/4.0/M_PI/D/D);
//   h_time_energy_antie->Scale(1/4.0/M_PI/D/D);
//    h_time_energy_x->Scale(1/4.0/M_PI/D/D);
    
    h_time_e->Scale(num_Xe_ton);
    h_time_antie->Scale(num_Xe_ton);
    h_time_x->Scale(num_Xe_ton);
    
    for(int i=0; i<nbin; i++){
        h_time_e->SetBinError(i, 0.0);
        h_time_antie->SetBinError(i, 0.0);
        h_time_x->SetBinError(i, 0.0);
    }
//    h_time_energy_e->Scale(num_Xe_ton);
//    h_time_energy_antie->Scale(num_Xe_ton);
//    h_time_energy_x->Scale(num_Xe_ton);
    
    h_time_e->GetXaxis()->SetTitle("Time (s)");
    h_time_antie->GetXaxis()->SetTitle("Time (s)");
    h_time_x->GetXaxis()->SetTitle("Time (s)");
    
    h_time_e->GetYaxis()->SetTitle("Event rate (ton.s)^{-1}");
    h_time_antie->GetYaxis()->SetTitle("Event rate (ton.s)^{-1}");
    h_time_x->GetYaxis()->SetTitle("Event rate (ton.s)^{-1}");
    
    
    infile.close();
    
    
}





void Spectrum::flux_time(TString filename, TFile *rootfile){//_flux, TFile *rootfile_spectrum_inter){
    TString hist_name1(filename(4,4)); //get 
    
    TString hist_flux_T_name_e = hist_name1 + "inter-" + "elec";
    TString hist_flux_T_name_antie = hist_name1 + "inter-" + "anti-elec";
    TString hist_flux_T_name_x = hist_name1 + "inter-" + "x-type";
    
    TString hist_flux_T_inter_e = hist_name1 + "elec";
    TString hist_flux_T_inter_antie = hist_name1 + "anti-elec";
    TString hist_flux_T_inter_x = hist_name1 + "x-type";
    
    TH1D * h_flux_T_e = new TH1D(hist_flux_T_name_e, hist_flux_T_name_e, nbin, tmin, tmax);
    TH1D * h_flux_T_antie = new TH1D(hist_flux_T_name_antie, hist_flux_T_name_antie, nbin, tmin, tmax);
    TH1D * h_flux_T_x = new TH1D(hist_flux_T_name_x, hist_flux_T_name_x, nbin, tmin, tmax);
   
//    //flux_time of linear interpolation
//    TH1D* h_flux_T_inter_e = new TH1D(hist_flux_T_inter_e, hist_flux_T_inter_e, 500, tmin, tmax);
//    TH1D* h_flux_T_inter_antie = new TH1D(hist_flux_T_inter_antie, hist_flux_T_inter_antie, 500, tmin, tmax);
 //   TH1D* h_flux_T_inter_x = new TH1D(hist_flux_T_inter_antie, hist_flux_T_inter_antie, 500, tmin, tmax);
    
//    //spectrum of linear interpolation 
//    TH1D* h_time_inter_e = new TH1D(hist_flux_T_inter_e, hist_flux_T_inter_e, 500, tmin, tmax);
//    TH1D* h_time_inter_antie = new TH1D(hist_flux_T_inter_antie, hist_flux_T_inter_antie, 500, tmin, tmax);
//    TH1D* h_time_inter_x = new TH1D(hist_flux_T_inter_antie, hist_flux_T_inter_antie, 500, tmin, tmax);
    
    
    h_flux_T_e->SetDirectory(rootfile);
    h_flux_T_antie->SetDirectory(rootfile);
    h_flux_T_x->SetDirectory(rootfile);
    
    TString file = path1 + filename;
     std::ifstream infile(file);
     
     double time, neu_energy0, neu_energy1, dN_dE_e, dN_dE_antie, dN_dE_x, temp;
     int k=0;
     
     double N_time[3]={0.0}; // 0: electron_neutrino; 1: anti-electron neutrino; 2: x neutrino
     
     double point1[3] = {0.0};
     double point2[3] = {0.0};
     
     double time0 = 0.0;
     double a[3], b[3];
     
     while(infile >> time)
     {
         
         for(int i = 1; i <21; i++)
         {
             infile >> neu_energy0 >> neu_energy1 >> dN_dE_e >> dN_dE_antie >> dN_dE_x >> temp >> temp >> temp;
             
             N_time[0] = N_time[0] + (neu_energy1 - neu_energy0) *dN_dE_e;
             N_time[1] = N_time[1] + (neu_energy1 - neu_energy0) *dN_dE_antie;
             N_time[2] = N_time[2] + (neu_energy1 - neu_energy0) *dN_dE_x;
             
        }
        
        h_flux_T_e->Fill(time, N_time[0]);
        h_flux_T_antie->Fill(time, N_time[1]);
        h_flux_T_x->Fill(time, N_time[2]);
        
        
//        //linear interpolation
//        point2[0] = N_time[0];
//        point2[1] = N_time[1];        
 //       point2[2] = N_time[2];
        
//        if(time != 0.0){           
//            a[0] = (point2[0] - point1[0])/(time - time0);
//            a[1] = (point2[0] - point1[0])/(time - time0);
//            a[2] = (point2[0] - point1[0])/(time - time0);            
//        }
        
//        //reset the value
//        time0 = time;
//        point1[0] = point2[0];
//        point1[1] = point2[0];
//        point1[2] = point2[0];
        
        
        N_time[0] = 0.0;
        N_time[1] = 0.0;
        N_time[2] = 0.0;
        
        if(k%50==0){std::cout<<"k == "<<k<<std::endl;}
        k++;
    }
    
    h_flux_T_e->Scale(1/4.0/M_PI/D/D);
    h_flux_T_antie->Scale(1/4.0/M_PI/D/D);
    h_flux_T_x->Scale(1/4.0/M_PI/D/D);

    infile.close();

    
    for(int i=0; i<nbin; i++){
        h_flux_T_e->SetBinError(i, 0.0);
        h_flux_T_antie->SetBinError(i, 0.0);
        h_flux_T_x->SetBinError(i, 0.0);
    }
/*
    std::vector<Double_t> time_point_e = {-0.2};
    std::vector<Double_t> flux_point_e = {0.0};
    std::vector<Double_t> time_point_antie = {-0.2};
    std::vector<Double_t> flux_point_antie = {0.0};
    std::vector<Double_t> time_point_x = {-0.2};
    std::vector<Double_t> flux_point_x = {0.0};
    
    for(int i=0; i<nbin; i++){
        
        if(h_flux_T_e->GetBinContent(i)>0.0){
            time_point_e.push_back(-0.2 + i*(1.5+0.2)/nbin);
            flux_point_e.push_back(h_flux_T_e->GetBinContent(i));
            
            std::cout<<"the value of i is "<<i<<std::endl;
            std::cout<<"the value of Time is "<<-0.2 + i*(1.5+0.2)/nbin<<std::endl;
            std::cout<<"the value of Flux is "<<h_flux_T_e->GetBinContent(i)<<std::endl;
        }
        
    if(h_flux_T_antie->GetBinContent(i)>0){
            time_point_antie.push_back(-0.2 + i*(1.5+0.2)/nbin);
            flux_point_antie.push_back(h_flux_T_e->GetBinContent(i));
        }
        
    if(h_flux_T_x->GetBinContent(i)>0){
            time_point_x.push_back(-0.2 + i*(1.5+0.2)/nbin);
            flux_point_x.push_back(h_flux_T_e->GetBinContent(i));
        }
        
    }
    
    h_flux_T_e->Reset();
    h_flux_T_antie->Reset();
    h_flux_T_x->Reset();
    
    ROOT::Math::Interpolator * interpolation_e = new ROOT::Math::Interpolator(time_point_e, flux_point_e, ROOT::Math::Interpolation::kLINEAR);
    ROOT::Math::Interpolator * interpolation_antie = new ROOT::Math::Interpolator(time_point_antie, flux_point_antie, ROOT::Math::Interpolation::kLINEAR);
    ROOT::Math::Interpolator * interpolation_x = new ROOT::Math::Interpolator(time_point_x, flux_point_x, ROOT::Math::Interpolation::kLINEAR);
    
    Double_t x;
    Double_t y;
    
    for(int i=0; i<nbin; i++){
        x = i * (1.5+0.2)/nbin;
        y = interpolation_e->Eval(x);
        h_flux_T_e->Fill(x, y);

        x = i * (1.5+0.2)/nbin;
        y = interpolation_antie->Eval(x);
        h_flux_T_antie->Fill(x, y);
        
        x = i * (1.5+0.2)/nbin;
        y = interpolation_x->Eval(x);
        h_flux_T_x->Fill(x, y);
    }
    
    for(int i=0; i<nbin; i++){
        h_flux_T_e->SetBinError(i, 0.0);
        h_flux_T_antie->SetBinError(i, 0.0);
        h_flux_T_x->SetBinError(i, 0.0);
    }
    
*/
}






void Spectrum::energy_spectrum(TString filename, TFile *rootfile){
    
    TString hist_name2(filename(5,4)); //get 
    
    TString hist_energy_name_e = hist_name2 + "e";
    TString hist_energy_name_antie = hist_name2 + "antie";
    TString hist_energy_name_x = hist_name2 + "x";
    
    TH1D* h_energy_e = new TH1D(hist_energy_name_e, hist_energy_name_e, 50, neu_Emin, neu_Emax);
    TH1D* h_energy_antie = new TH1D(hist_energy_name_antie, hist_energy_name_antie, 50, neu_Emin, neu_Emax);
    TH1D* h_energy_x = new TH1D(hist_energy_name_x, hist_energy_name_x, 50, neu_Emin, neu_Emax);
    
    h_energy_e->SetDirectory(rootfile);
    h_energy_antie->SetDirectory(rootfile);
    h_energy_x->SetDirectory(rootfile);
    
    
    TString file = path1 + filename;
     std::ifstream infile(file);
     
     double time, neu_energy0, neu_energy1, dN_dE_e, dN_dE_antie, dN_dE_x, temp;
     Xsection* xs_calculation = new Xsection();
     double xs;
     double N_energy[3]={0}; // 0: electron_neutrino; 1: anti-electron neutrino; 2: x neutrino
     
     while(infile >> temp >> temp >> temp >> temp >> temp >>temp)
     {
         
         for(int i = 1; i <21; i++)
         {
             infile >> neu_energy0 >> neu_energy1 >> dN_dE_e >> dN_dE_antie >> dN_dE_x >> temp >> temp >> temp;
             
             xs = xs_calculation->cross_section(neu_energy1);
             
             N_energy[0] =  xs *dN_dE_e;
             N_energy[1] =  xs *dN_dE_antie;
             N_energy[2] =  xs *dN_dE_x;
             
             h_energy_e->Fill(neu_energy1, N_energy[0]);
             h_energy_antie->Fill(neu_energy1, N_energy[1]);
             h_energy_x->Fill(neu_energy1, N_energy[2]);
         
             
        }
        
    }
    
    h_energy_e->Scale(1/4.0/M_PI/D/D);
    h_energy_antie->Scale(1/4.0/M_PI/D/D);
    h_energy_x->Scale(1/4.0/M_PI/D/D);
    
    h_energy_e->Scale(num_Xe_ton);
    h_energy_antie->Scale(num_Xe_ton);
    h_energy_x->Scale(num_Xe_ton);
    
    h_energy_e->GetXaxis()->SetTitle("E_{#nu} (MeV)");
    h_energy_antie->GetXaxis()->SetTitle("E_{#nu} (MeV)");
    h_energy_x->GetXaxis()->SetTitle("E_{#nu} (MeV)");
    
    h_energy_e->GetYaxis()->SetTitle("Event rate (ton.MeV)^{-1}");
    h_energy_antie->GetYaxis()->SetTitle("Event rate (ton.MeV)^{-1}");
    h_energy_x->GetYaxis()->SetTitle("Event rate (ton.MeV)^{-1}");
    
    infile.close();
    
}

//get "neutrino flux vs neutrino energy" and fit the curve with Fermi-Dirac distribution
void Spectrum::flux_neuE(TString filename, TFile *rootfile){
    
    
    TString hist_name2(filename(4,4)); //get 
    
    TString hist_flux_neuE_name_e = hist_name2 + "electron";
    TString hist_flux_neuE_name_antie = hist_name2 + "anti-electron";
    TString hist_flux_neuE_name_x = hist_name2 + "x";
    
    TH1D* h_flux_neuE_e = new TH1D(hist_flux_neuE_name_e, hist_flux_neuE_name_e, 300, neu_Emin, neu_Emax);
    TH1D* h_flux_neuE_antie = new TH1D(hist_flux_neuE_name_antie, hist_flux_neuE_name_antie, 300, neu_Emin, neu_Emax);
    TH1D* h_flux_neuE_x = new TH1D(hist_flux_neuE_name_x, hist_flux_neuE_name_x, 30, neu_Emin, neu_Emax);
    
    h_flux_neuE_e->SetDirectory(rootfile);
    h_flux_neuE_antie->SetDirectory(rootfile);
    h_flux_neuE_x->SetDirectory(rootfile);
    
    
    TString file = path1 + filename;
     std::ifstream infile(file);
     
     double time, neu_energy0, neu_energy1, dN_dE_e, dN_dE_antie, dN_dE_x, temp;
     int k=0;
     Xsection* xs_calculation = new Xsection();
     double xs;
     
     double time0 = 0.0;
     
     while(infile >> time)
     {
         if(time<1.0){
             
            for(int i = 1; i <21; i++)
            {
                infile >> neu_energy0 >> neu_energy1 >> dN_dE_e >> dN_dE_antie >> dN_dE_x >> temp >> temp >> temp;
             
                if(time >= 0.0){
                    
                    h_flux_neuE_e->Fill( neu_energy1, dN_dE_e * (time - time0) );
                    h_flux_neuE_antie->Fill( neu_energy1, dN_dE_antie * (time - time0) );
                    h_flux_neuE_x->Fill( neu_energy1, dN_dE_x * (time - time0) );
                    
                }
             
            }
        
            time0 =time;
            
            
            if(k%50==0){std::cout<<"k == "<<k<<std::endl;}
            k++;
         }
         else{break;}
    }
    
    h_flux_neuE_e->Scale(1/4.0/M_PI/D/D);
    h_flux_neuE_antie->Scale(1/4.0/M_PI/D/D);
    h_flux_neuE_x->Scale(1/4.0/M_PI/D/D);
    
    
    infile.close();
    
    h_flux_neuE_e->GetXaxis()->SetTitle("E_{#nu} (MeV)");
    h_flux_neuE_antie->GetXaxis()->SetTitle("E_{#nu} (MeV)");
    h_flux_neuE_x->GetXaxis()->SetTitle("E_{#nu} (MeV)");
    
    h_flux_neuE_e->GetYaxis()->SetTitle("Flux (s.MeV)^{-1}(cm)^{-2}");
    h_flux_neuE_antie->GetYaxis()->SetTitle("Flux (s.MeV)^{-1}(cm)^{-2}");
    h_flux_neuE_x->GetYaxis()->SetTitle("Flux (s.MeV)^{-1}(cm)^{-2}");
    
    
//    TF1 *func = new TF1("fit",fitf, neu_Emin, neu_Emax, 2);
    
//    h_flux_neuE_e->Fit("fit");
    
//    TCanvas * c0 = new TCanvas("c0", "", 800, 600);
//    h_flux_neuE_e->Draw();
//    TString savepath = "/Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code1/plots/";
//    c0->Print(savepath + "test.pdf","pdf");//
}
