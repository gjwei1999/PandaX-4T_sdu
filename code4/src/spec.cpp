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


void Spec::generate_spec(double input_distance){
    
    //define path of root
     TString path2 = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code4/output/spectrum/";
     
     //define root file name
     TString root_time_spec = path2 + "time_spec.root";
     TString root_time_spec_total = path2 + "time_spec_total.root";
     TString root_energy_spec = path2 + "energy_spec.root";
     TString root_flux_neuE = path2 + "flux_neuE.root";
     TString root_flux_time = path2 + "flux.root";
     
     //files for time and energy spec
     TFile * fs1 = new TFile(root_time_spec.Data(), "RECREATE");
     TFile * fs1_1 = new TFile(root_time_spec_total.Data(), "RECREATE");
     
     TFile * fs2 = new TFile(root_energy_spec.Data(), "RECREATE");
     TFile * fs3 = new TFile(root_flux_neuE.Data(), "RECREATE");
     TFile * fs4 = new TFile(root_flux_time.Data(), "RECREATE");
     //TFile * fs5 = new TFile(root_time_spec_inter.Data(), "RECREATE");
     
     //define class for every dataset
     Spectrum* Spec_1301 = new Spectrum();
     Spectrum* Spec_1302 = new Spectrum();
     Spectrum* Spec_1303 = new Spectrum();
     Spectrum* Spec_2001 = new Spectrum();
     Spectrum* Spec_2002 = new Spectrum();
     Spectrum* Spec_2003 = new Spectrum();
     Spectrum* Spec_3001 = new Spectrum();
     Spectrum* Spec_3002 = new Spectrum();
     Spectrum* Spec_3003 = new Spectrum();
     Spectrum* Spec_5001 = new Spectrum();
     Spectrum* Spec_5002 = new Spectrum();
     Spectrum* Spec_5003 = new Spectrum();
     
     
     
     Spec_1301->set_distance(input_distance);
     Spec_1302->set_distance(input_distance);
     Spec_1303->set_distance(input_distance);
     Spec_2001->set_distance(input_distance);
     Spec_2002->set_distance(input_distance);
     Spec_2003->set_distance(input_distance);
     Spec_3001->set_distance(input_distance);
     Spec_3002->set_distance(input_distance);
     Spec_3003->set_distance(input_distance);
     Spec_5001->set_distance(input_distance);
     Spec_5001->set_distance(input_distance);
     Spec_5001->set_distance(input_distance);
     
     
     // time-related data
     //define filename_time
     TString filename_time_1301 = "intp1301.data";
     TString filename_time_1302 = "intp1302.data";
     TString filename_time_1303 = "intp1303.data";
     
     TString filename_time_2001 = "intp2001.data";
     TString filename_time_2002 = "intp2002.data";
     TString filename_time_2003 = "intp2003.data";
     
     TString filename_time_3001 = "intp3001.data";
     TString filename_time_3002 = "intp3002.data";
     TString filename_time_3003 = "intp3003.data";
     
     TString filename_time_5001 = "intp5001.data";
     TString filename_time_5002 = "intp5002.data";
     TString filename_time_5003 = "intp5003.data";
     
     Spec_1301->time_spectrum(filename_time_1301, fs1, fs1_1);
     Spec_1302->time_spectrum(filename_time_1302, fs1, fs1_1);
     Spec_1303->time_spectrum(filename_time_1303, fs1, fs1_1);
     Spec_2001->time_spectrum(filename_time_2001, fs1, fs1_1);
     Spec_2002->time_spectrum(filename_time_2002, fs1, fs1_1);
     Spec_2003->time_spectrum(filename_time_2003, fs1, fs1_1);
     Spec_3001->time_spectrum(filename_time_3001, fs1, fs1_1);
     Spec_3002->time_spectrum(filename_time_3002, fs1, fs1_1);
     Spec_3003->time_spectrum(filename_time_3003, fs1, fs1_1);
     Spec_5001->time_spectrum(filename_time_5001, fs1, fs1_1);
     Spec_5002->time_spectrum(filename_time_5002, fs1, fs1_1);
     Spec_5003->time_spectrum(filename_time_5003, fs1, fs1_1);
     
     fs1->Write();
     fs1_1->Write();
  
     
     Spec_1301->flux_time(filename_time_1301, fs4);//, fs5);
     Spec_1302->flux_time(filename_time_1302, fs4);//, fs5);
     Spec_1303->flux_time(filename_time_1303, fs4);//, fs5);
     Spec_2001->flux_time(filename_time_2001, fs4);//, fs5);
     Spec_2002->flux_time(filename_time_2002, fs4);//, fs5);
     Spec_2003->flux_time(filename_time_2003, fs4);//, fs5);
     Spec_3001->flux_time(filename_time_3001, fs4);//, fs5);
     Spec_3002->flux_time(filename_time_3002, fs4);//, fs5);
     Spec_3003->flux_time(filename_time_3003, fs4);//, fs5);
     Spec_5001->flux_time(filename_time_5001, fs4);//, fs5);
     Spec_5002->flux_time(filename_time_5002, fs4);//, fs5);
     Spec_5003->flux_time(filename_time_5003, fs4);//, fs5);
     
     
     fs4->Write();
     //fs5->Write();
     
     
     // energy-realted data
     //define filename energy
     TString filename_energy_1301 = "integ1301.data";
     TString filename_energy_1302 = "integ1302.data";
     TString filename_energy_1303 = "integ1303.data";
     
     TString filename_energy_2001 = "integ2001.data";
     TString filename_energy_2002 = "integ2002.data";
     TString filename_energy_2003 = "integ2003.data";
     
     TString filename_energy_3001 = "integ3001.data";
     TString filename_energy_3002 = "integ3002.data";
     TString filename_energy_3003 = "integ3003.data";
     
     TString filename_energy_5001 = "integ5001.data";
     TString filename_energy_5002 = "integ5002.data";
     TString filename_energy_5003 = "integ5003.data";
     
     
     Spec_1301->energy_spectrum(filename_energy_1301, fs2);
     Spec_1302->energy_spectrum(filename_energy_1302, fs2);
     Spec_1303->energy_spectrum(filename_energy_1303, fs2);
     Spec_2001->energy_spectrum(filename_energy_2001, fs2);
     Spec_2002->energy_spectrum(filename_energy_2002, fs2);
     Spec_2003->energy_spectrum(filename_energy_2003, fs2);
     Spec_3001->energy_spectrum(filename_energy_3001, fs2);
     Spec_3002->energy_spectrum(filename_energy_3002, fs2);
     Spec_3003->energy_spectrum(filename_energy_3003, fs2);
     Spec_5001->energy_spectrum(filename_energy_5001, fs2);
     Spec_5002->energy_spectrum(filename_energy_5002, fs2);
     
     
     
     Spec_5003->energy_spectrum(filename_energy_5003, fs2);
     
      fs2->Write();
      
      
      Spec_1301->flux_neuE(filename_time_1301, fs3);
      Spec_1302->flux_neuE(filename_time_1302, fs3);
      Spec_1303->flux_neuE(filename_time_1303, fs3);
      Spec_2001->flux_neuE(filename_time_2001, fs3);
      Spec_2002->flux_neuE(filename_time_2002, fs3);
      Spec_2003->flux_neuE(filename_time_2003, fs3);
      Spec_3001->flux_neuE(filename_time_3001, fs3);
      Spec_3002->flux_neuE(filename_time_3002, fs3);
      Spec_3003->flux_neuE(filename_time_3003, fs3);
      Spec_5001->flux_neuE(filename_time_5001, fs3);
      Spec_5002->flux_neuE(filename_time_5002, fs3);
      Spec_5003->flux_neuE(filename_time_5003, fs3);
      
      fs3->Write();
    
}


void Spec::num_integral(){
    
    TString path2 = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code4/output/spectrum/";
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
        
        //for the 1st second
        std::string hist_name_electron = Form("%delectron", number);
        std::string hist_name_antielectron = Form("%danti-electron", number);
        std::string hist_name_x = Form("%dx", number);
    
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
    std::cout<<number<<" is finished."<<std::endl;
    std::cout<<"----------------------------"<<std::endl;
    
    std::string hist_name_total = Form("%d_total", number);
    
    int_get_total(fs1, fs2, hist_name_total.c_str(), hist_name_electron.c_str(), hist_name_antielectron.c_str(), hist_name_x.c_str());
        
    }
    
    fs1->Write();
    fs2->Write();
    
    
}


void Spec::int_get_total(TFile * root_name1, TFile * root_name2, TString hist_name_total, TString hist_name_electron, TString hist_name_antielectron, TString hist_name_x){
    
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
    h_spectrum_recE_total->Add(hist_x, 4.0);
    
    //h_spectrum_recE_total->Scale(0.001);//convert the unit from MeV^{-1} to keV^{-1}
    
    h_spectrum_recE_total->SetDirectory(root_name2);
    
}




