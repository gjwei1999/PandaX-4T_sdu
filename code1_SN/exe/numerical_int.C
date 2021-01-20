/*****************************/
/*                                                      */
/*       Created by Jiawei Guo          */
/*        Shandong University            */
/*                                                      */
/*****************************/

#include <iostream>
#include <fstream>
#include <cmath>

#include "integral.h"

void get_total(TFile * root_name1, TFile * root_name2, TString hist_name_total, TString hist_name_electron, TString hist_name_antielectron, TString hist_name_x);

int main(){
    
    TString path2 = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code1_SN/build/";
    TString root_recE_spec = path2 + "recE_spec.root";
    TString root_recE_spec_total = path2 + "recE_spec_total.root";
    
    TFile * fs1 = new TFile(root_recE_spec.Data(), "RECREATE");
    TFile * fs2 = new TFile(root_recE_spec_total.Data(), "RECREATE");
    
    Integral * int_1301e = new Integral();
    Integral * int_1301antie = new Integral();
    Integral * int_1301x = new Integral();
    
    int name[12] = {1301, 1302, 1303, 2001, 2002, 2003, 3001, 3002, 3003, 5001, 5002, 5003};
    
    for(int i=0; i<12; i++){
        
        int number = name[i];
        
        std::string hist_name_electron = Form("%delectron", number);
        std::string hist_name_antielectron = Form("%danti-electron", number);
        std::string hist_name_x = Form("%dx", number);
    
    int_1301e->set_hist(hist_name_electron.c_str());
    int_1301e->set_flux_point();
    int_1301e->numerical_int(hist_name_electron.c_str(), fs1);
    
    int_1301antie->set_hist(hist_name_antielectron.c_str());
    int_1301antie->set_flux_point();
    int_1301antie->numerical_int(hist_name_antielectron.c_str(), fs1);
    
    int_1301x->set_hist(hist_name_x.c_str());
    int_1301x->set_flux_point();
    int_1301x->numerical_int(hist_name_x.c_str(), fs1);
    
    std::cout<<"----------------------------"<<std::endl;
    std::cout<<number<<" is finished."<<std::endl;
    std::cout<<"----------------------------"<<std::endl;
    
    std::string hist_name_total = Form("%d_total", number);
    
    get_total(fs1, fs2, hist_name_total.c_str(), hist_name_electron.c_str(), hist_name_antielectron.c_str(), hist_name_x.c_str());
        
    }
    
    fs1->Write();
    fs2->Write();
    
    return 1;
}

//get histogram from root_name1
//write the histogram of the total rate to root_name2
void get_total(TFile * root_name1, TFile * root_name2, TString hist_name_total, TString hist_name_electron, TString hist_name_antielectron, TString hist_name_x){
    
    TString spectrum_recE_name = hist_name_total + "_recoil";
    
    int nbin2 = 10000;//the value should be equal to "nbin2" of "Integral::numerical_int" in src/integral.cpp
    TH1D * h_spectrum_recE_total = new TH1D(spectrum_recE_name, spectrum_recE_name, nbin2, 1.0e-3, 100.0);//unit keV
    
    TString hist_name_electron_1 = hist_name_electron + "_recoil";
    TString hist_name_antielectron_1 = hist_name_antielectron + "_recoil";
    TString hist_name_x_1 = hist_name_x + "_recoil";
    
    TH1D * hist_ele = (TH1D *) root_name1->Get(hist_name_electron_1);
    TH1D * hist_antie = (TH1D *) root_name1->Get(hist_name_antielectron_1);
    TH1D * hist_x = (TH1D *) root_name1->Get(hist_name_x_1);
    
    h_spectrum_recE_total->Add(hist_ele, hist_antie);
    h_spectrum_recE_total->Add(hist_x, 4);
    
    h_spectrum_recE_total->Scale(0.001);//convert the unit from MeV^{-1} to keV^{-1}
    
    h_spectrum_recE_total->SetDirectory(root_name2);
}
