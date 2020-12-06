#include <iostream>
#include <fstream>
#include <cmath>

#include "TROOT.h"
#include "TStyle.h"
//#include "TSystem.h"
#include "TString.h"
#include "TRandom.h"
#include "TRandom3.h"
#include "TGenPhaseSpace.h"
#include "TLorentzVector.h"
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


Spectrum::Spectrum(){
}

Spectrum::~Spectrum(){
}

void Spectrum::time_spectrum(TString filename, TFile *rootfile){
    
    TString hist_name1(filename(4,4)); //get 
    
    TString hist_time_name_e = hist_name1 + "e";
    TString hist_time_name_antie = hist_name1 + "antie";
    TString hist_time_name_x = hist_name1 + "x";
    
    
    TH1D* h_time_e = new TH1D(hist_time_name_e, hist_time_name_e, 500, tmin, tmax);
    TH1D* h_time_antie = new TH1D(hist_time_name_antie, hist_time_name_antie, 500, tmin, tmax);
    TH1D* h_time_x = new TH1D(hist_time_name_x, hist_time_name_x, 500, tmin, tmax);
    
    
    h_time_e->SetDirectory(rootfile);
    h_time_antie->SetDirectory(rootfile);
    h_time_x->SetDirectory(rootfile);
    
    TString file = path1 + filename;
     std::ifstream infile(file);
     
     double time, neu_energy0, neu_energy1, dN_dE_e, dN_dE_antie, dN_dE_x, temp;
     int k=0;
     Xsection* xs_calculation = new Xsection();
     double xs;
     double N_time[3]={0}; // 0: electron_neutrino; 1: anti-electron neutrino; 2: x neutrino
     
     while(infile >> time)
     {
         
         for(int i = 1; i <21; i++)
         {
             infile >> neu_energy0 >> neu_energy1 >> dN_dE_e >> dN_dE_antie >> dN_dE_x >> temp >> temp >> temp;
             
             xs = xs_calculation->cross_section(neu_energy1);
             
             N_time[0] = N_time[0] + xs * (neu_energy1 - neu_energy0) *dN_dE_e;
             N_time[1] = N_time[1] + xs * (neu_energy1 - neu_energy0) *dN_dE_antie;
             N_time[2] = N_time[2] + xs * (neu_energy1 - neu_energy0) *dN_dE_x;
             
        }
        
        h_time_e->Fill(time, N_time[0]);
        h_time_antie->Fill(time, N_time[1]);
        h_time_x->Fill(time, N_time[2]);
        
        if(k%50==0){std::cout<<"k == "<<k<<std::endl;}
        k++;
    }
    
    infile.close();
    
    
}
/*
void Spectrum::time_spec_histogram(TFile * rootfile, TString filename){
    
    TString hist_name1(filename(4,4)); //get 
    
    TString hist_time_name_e = hist_name1 + "e";
    TString hist_time_name_antie = hist_name1 + "antie";
    TString hist_time_name_x = hist_name1 + "x";
    
    h_time_e->SetNameTitle(hist_time_name_e, hist_time_name_e);
    h_time_antie->SetNameTitle(hist_time_name_antie, hist_time_name_antie);
    h_time_x->SetNameTitle(hist_time_name_x, hist_time_name_x);
    
    h_time_e->SetDirectory(rootfile);
    h_time_antie->SetDirectory(rootfile);
    h_time_x->SetDirectory(rootfile);
}
*/

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
    
    infile.close();
    
}
