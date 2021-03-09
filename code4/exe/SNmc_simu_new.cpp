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
#include "spec.hpp"

#include "TString.h"
#include "TFile.h"
#include "TMath.h"
#include "TH1D.h"
#include "TH2D.h"


int main(int argc, char* argv[]){
    
    if(argc != 2){
        std::cerr<<"Usage: "<<argv[0]<<" 'type_of_sn'"<<std::endl;
        return 1;
    }
    
    int type_of_sn = atoi(argv[1]);
    
    Spec * class_spectrum = new Spec();
    

    //double d_min= 10.0;//start from 10kpc
    //double d_max = 20.0;
    
    //double distance[5] = {10.0, 15.0, 20.0, 25.0, 0.0};
    //double distance[5] = {30.0, 35.0, 40.0, 45.0, 0.0};
    //double distance[5] = {50.0, 52.0, 54.0, 56.0, 0.0};
    //double distance[5] = {58.0, 60.0, 62.0, 64.0, 0.0};
    //double distance[20] = {10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 46.0, 48.0, 42.0, 44.0, 50.0, 52.0, 54.0, 56.0, 58.0, 60.0, 62.0, 0.0};
    double distance[2] = {10.0, 0.0};
    
    double trigger_eff[20] = {0};
    //double d_step = 0.1;
    int i = 0;
    
    double D = distance[0];
    
    while(D != 0.0){
    
        class_spectrum->generate_spec(D, type_of_sn);
        class_spectrum->num_integral();
        class_spectrum->cal_events();

        int events_in_20s = class_spectrum->get_events();
        
        int num_of_simu = 1000;
        double T_sn = 1.0;
        double t_refresh = 0.1;
        int N_thr = 5;
        
        
        Signal_mc * SNmc_3003 = new Signal_mc();
        TString para_file = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code4/parameters/SN_simu_para.json";
        
        
        
        SNmc_3003->set_num_simu(num_of_simu);
        SNmc_3003->run_mc(para_file, num_of_simu, events_in_20s);
        trigger_eff[i] = SNmc_3003->time_window(T_sn, t_refresh, N_thr);
        
        
        i++;
        D = distance[i];
    }
    
    for(int i =0; i<20; i++){
        
        std::cout<<std::endl;
        std::cout<<"********Summary**********"<<std::endl;
        std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
        std::cout<<"The trigger efficiency: "<<trigger_eff[i]<<std::endl;
    
        
    }
    
    delete class_spectrum;
    
    return 1;
}
