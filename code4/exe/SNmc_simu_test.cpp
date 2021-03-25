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
    Signal_mc * SNmc = new Signal_mc();
    TString para_file = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code4/parameters/SN_simu_para.json";
    
    int num_of_simu = 1000;
    double T_sn = 1.0;
    double t_refresh = 0.01;
    int N_thr = 5;
    
    double dis_min = 10.0;
    double dis_max = 80.0;
    double d_step = 1.0;
    
    int events_in_20s;
    double trigger_eff = 0.0;
    
    std::ofstream outfile;
    outfile.open("/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code4/output/trig_eff.dat");
    
    
    double D = dis_min;
    
    while(D < dis_max){
    
        class_spectrum->generate_spec(D, type_of_sn);
        class_spectrum->num_integral();
        class_spectrum->cal_events();

        events_in_20s = class_spectrum->get_events();
        
        SNmc->set_num_simu(num_of_simu);
        SNmc->run_mc(para_file, num_of_simu, events_in_20s);
        trigger_eff = SNmc->time_window(T_sn, t_refresh, N_thr);
        
        std::cout<<std::endl;
        std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
        std::cout<<"The trigger efficiency: "<<trigger_eff<<std::endl;
        
        outfile << D << " " << trigger_eff << std::endl;
        
        D += d_step;
    }
    
    outfile.close();
    
    delete class_spectrum;
    delete SNmc;
    
    return 1;
}
