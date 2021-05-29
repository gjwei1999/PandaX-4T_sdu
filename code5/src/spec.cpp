/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#include <iostream>
#include <fstream>

#include "spec.hpp"

Spec::Spec(){}
Spec::~Spec(){}


void Spec::generate_spec(double input_distance, int type_of_sn){
    
    
    
    TString path2 = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code5/output/spectrum/";
     
    //define root file name
    TString root_time_spec = path2 + "time_spec.root";
    TString root_time_spec_total = path2 + "time_spec_total.root";
    TString root_flux_neuE = path2 + "flux_neuE.root";

     
    //files for time and energy spec
    TFile * fs1 = new TFile(root_time_spec.Data(), "RECREATE");
    TFile * fs1_1 = new TFile(root_time_spec_total.Data(), "RECREATE");
    TFile * fs3 = new TFile(root_flux_neuE.Data(), "RECREATE");
     
    //define class for every dataset
    Spectrum* Spec = new Spectrum();
     
    // time-related data
    //define filename_time
    TString filename_time;
     
    if(type_of_sn == 1301){
         filename_time = "intp1301.data";
    }
    else if(type_of_sn == 1302){
         filename_time = "intp1302.data";
    }
    else if(type_of_sn == 1303){
        filename_time = "intp1303.data";
    }
    else if(type_of_sn == 2001){
        filename_time = "intp2001.data";
    }
    else if(type_of_sn == 2002){
        filename_time = "intp2002.data";
    }
    else if(type_of_sn == 2003){
        filename_time = "intp2003.data";
    }
    else if(type_of_sn == 3001){
        filename_time = "intp3001.data";
    }
    else if(type_of_sn == 3002){
        filename_time = "intp3002.data";
    }
    else if(type_of_sn == 3003){
        filename_time = "intp3003.data";
    }
    else if(type_of_sn == 5001){
        filename_time = "intp5001.data";
    }
    else if(type_of_sn == 5002){
        filename_time = "intp5002.data";
    }
    else if(type_of_sn == 5003){
        filename_time = "intp5003.data";
    }
    else{
        std::cout<<"'type_of_sn' is wrong!!!"<<std::endl;
    }
     
        
     Spec->time_spectrum(filename_time, fs1, fs1_1, input_distance);

     fs1->Write();
     fs1_1->Write();
     
     Spec->flux_neuE(filename_time, fs3, input_distance);
     
     fs3->Write();
     
     fs1->Close();
     fs1_1->Close();
     fs3->Close();
        
     delete Spec;

}


void Spec::num_integral(){
    
    TString path2 = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code5/output/spectrum/";
    TString root_recE_spec = path2 + "recE_spec.root";
    TString root_recE_spec_total = path2 + "recE_spec_total.root";
    
    TFile * fs1 = new TFile(root_recE_spec.Data(), "RECREATE");
    TFile * fs2 = new TFile(root_recE_spec_total.Data(), "RECREATE");
    
    Integral * int_1301e = new Integral();
    Integral * int_1301antie = new Integral();
    Integral * int_1301x = new Integral();
    
    /*
    int name[12] = {1301, 1302, 1303, 2001, 2002, 2003, 3001, 3002, 3003, 5001, 5002, 5003};
    
    for(int i=0; i<12; i++){
       */
    //int name[1] = {3003};
    
    //for(int i=0; i<1; i++){
        
        //int number = name[i];
        
    std::string hist_name_electron = "electron";
    std::string hist_name_antielectron = "anti-electron";
    std::string hist_name_x = "x";
    
        //for 20-second average
        //std::string hist_name_electron = Form("%de", number);
        //std::string hist_name_antielectron = Form("%dantie", number);
        //std::string hist_name_x = Form("%dx", number);
        
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
    std::cout<<"recoil energy spectrum  is finished."<<std::endl;
    std::cout<<"----------------------------"<<std::endl;
    
    int_get_total(fs1, fs2);
        
    //}
    
    fs1->Write();
    fs2->Write();
    
    fs1->Close();
    fs2->Close();
    
    int_1301e->close_file();
    int_1301antie->close_file();
    int_1301x->close_file();
    
    delete int_1301e;
    delete int_1301antie;
    delete int_1301x;
    
}


void Spec::int_get_total(TFile * root_name1, TFile * root_name2){
    
    TString spectrum_recE_name = "total_recoil";
    
    int nbin2 = 10000;//the value should be equal to "nbin2" of "Integral::numerical_int" in src/integral.cpp
    TH1D * h_spectrum_recE_total = new TH1D(spectrum_recE_name, spectrum_recE_name, nbin2, 1.0e-3, 100.0);//unit keV
    
    TString hist_name_electron_1 = "electron_recoil";
    TString hist_name_antielectron_1 = + "anti-electron_recoil";
    TString hist_name_x_1 = "x_recoil";
    
    TH1D * hist_ele = (TH1D *) root_name1->Get(hist_name_electron_1);
    TH1D * hist_antie = (TH1D *) root_name1->Get(hist_name_antielectron_1);
    TH1D * hist_x = (TH1D *) root_name1->Get(hist_name_x_1);
    
    h_spectrum_recE_total->Add(hist_ele, hist_antie);
    h_spectrum_recE_total->Add(hist_x, 4.0);
    
    //h_spectrum_recE_total->Scale(0.001);//convert the unit from MeV^{-1} to keV^{-1}
    
    h_spectrum_recE_total->SetDirectory(root_name2);
    
}


void Spec::cal_events(){
    
    TString loadpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code5/output/spectrum/";
    TFile *fs = new TFile(loadpath + "recE_spec_total.root", "r");
    
    int bin_num_left;
    int bin_num_right;
    double num_of_events;
    

    TH1D * h3003 = (TH1D *) fs->Get("total_recoil");
    num_of_events = h3003->Integral("width");
    
    result_cal = 4*num_of_events;
    
    fs->Close();

    
}

int Spec::get_events(){
    return int(result_cal + 0.5);
}


