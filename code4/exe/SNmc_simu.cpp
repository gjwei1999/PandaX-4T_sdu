/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#include <iostream>
#include <fstream>
#include <cmath>

#include "branches.hpp"
#include "signal_mc.hpp"

#include "TString.h"
#include "TFile.h"
#include "TMath.h"
#include "TH1D.h"
#include "TH2D.h"


int main(int argc, char* argv[]){
    
    int num_of_simu = 4000;
    double T_sn = 1.0;
    double t_refresh = 0.1;
    int N_thr = 100;
    
    Signal_mc * SNmc_3003 = new Signal_mc();
    TString para_file = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code4/parameters/SN_3003.json";
    
    SNmc_3003->set_num_simu(num_of_simu);
    SNmc_3003->run_mc(para_file, num_of_simu);
    SNmc_3003->time_window(3003, T_sn, t_refresh, N_thr);
    /*
    
    //to run the code
    // ./analysis input_file
    if(argc != 3){
        std::cout<<"Error. The input parameters are wrong."<<std::endl;
        std::cout<<"Usage: "<<argv[0]<<" input_root_file   output_root_file_name"<<std::endl;
        
        return 1;
    }
    
    TString path1 = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/output/";
    TString result_root = path1 + argv[2] + ".root";
    
    
    TFile *fs1 = new TFile(result_root.Data(), "RECREATE");
    
    
    std::string input = argv[1];
    TFile *fs = new TFile(input.c_str(), "r");//input data
    TTree *t1 = (TTree*)fs->Get("qmc_tree");
    
    int num_of_events;
    num_of_events = (int)t1->GetEntries();

    
    Branches * branch1 = new Branches();
    branch1->init(t1);
    
    double total_time_simu;//get the total_time of the simulation
    t1->GetEntry(0);
    total_time_simu = branch1->get_total_time();
    
    TH1D * h_event_time = new TH1D("event_time", "event_time", total_time_simu, 0.0, total_time_simu);
    TH1D * h_detected_event_time =new  TH1D("detected_event_time", "detected_event_time", total_time_simu, 0.0, total_time_simu);
    
    TH2D * h_logs2s1_s1= new TH2D("logs2s1_s1", "", 100, 0.0, 150.0, 100, 1.0, 10.0);
    
    
    int n_s1d = 0;
    int n_s2d = 0;
    int n_s1d_s2d = 0;
    
    for (int current_event = 0; current_event < num_of_events; current_event++) {
        
        // Get current event
        t1->GetEntry(current_event);
        
        
        if(branch1->get_S1d() > 0.0){
            n_s1d++;
        }
        
        if(branch1->get_S2d() > 0.0){
            n_s2d++;
        }
        
        if( (branch1->get_S2d() > 0.0) && (branch1->get_S2d() > 0.0)){
            n_s1d_s2d++;
        }
        
        //fill histogram
        h_event_time->Fill(branch1->get_event_time());
        
        if((branch1->get_S1d() > 0.0) && (branch1->get_S2d() > 0.0)){
            h_detected_event_time->Fill(branch1->get_event_time());
        }
        
        double temp;
        temp = TMath::Log(branch1->get_S2d()/branch1->get_S1d());
        h_logs2s1_s1->Fill(branch1->get_S1d(), temp);
        
        //std::cout<<"current event energy is "<<branch1->get_nQuanta()<<std::endl;
    }
    
    //set bin error to 0
        for(int i; i<total_time_simu; i++){
            h_event_time->SetBinError(i, 0.0);
            h_detected_event_time->SetBinError(i, 0.0);
        }
        
    h_event_time->SetDirectory(fs1);
    h_detected_event_time->SetDirectory(fs1);
    h_logs2s1_s1->SetDirectory(fs1);
    
    fs1->Write();
 
    
    std::cout<<"input "<< num_of_events <<" events "<<std::endl;
    //std::cout<<"detected "<< n_s1d <<" S1 signal "<<std::endl;
    //std::cout<<"detected "<< n_s2d <<" S2 signal "<<std::endl;
    std::cout<<"detected "<< n_s1d_s2d <<" S1&S2 signal "<<std::endl;
    std::cout<<"The average rate of detected events is "<< n_s1d_s2d/total_time_simu <<std::endl; 
    
    */
    return 1;
}

