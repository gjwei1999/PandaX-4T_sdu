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
    
    Spec * class_spectrum = new Spec();
    
    TString file = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code4/output/trig_distance.root";
    TFile * fs = new TFile(file.Data(), "RECREATE");
    
    int nbin = 10;
    double d_min= 10.0;//start from 10kpc
    double d_max = 20.0;
    double d_step = 0.5;
    int i = 0;
    double a[21] = {0.0};
    
    TH1D * h_trig_distance = new TH1D("trig_distance", "trig_distance", nbin, d_min, d_max);
    
    while(d_min <= d_max){
    
    class_spectrum->generate_spec(d_min);
    class_spectrum->num_integral();
    class_spectrum->cal_events();
    
    int events_in_20s = 0;
    double trigger_eff = 0.0;
    
    int num_of_simu = 1000;
    double T_sn = 1.0;
    double t_refresh = 0.1;
    int N_thr = 100;
    
    Signal_mc * SNmc_3003 = new Signal_mc();
    TString para_file = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code4/parameters/SN_3003.json";
    
    events_in_20s = class_spectrum->get_3003();
    
    SNmc_3003->set_num_simu(num_of_simu);
    SNmc_3003->run_mc(para_file, num_of_simu, events_in_20s);
    trigger_eff = SNmc_3003->time_window(3003, T_sn, t_refresh, N_thr);
    
    h_trig_distance->Fill(d_min, trigger_eff);
    a[i] = trigger_eff;
    
    std::cout<<"Now distance: "<<d_min<<std::endl;
    d_min += d_step;
    i++;
    }
    
    h_trig_distance->SetDirectory(fs);
    fs->Write();
    
    delete class_spectrum;
    
    return 1;
}
