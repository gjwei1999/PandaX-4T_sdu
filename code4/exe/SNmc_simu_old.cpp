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
    
    int num_of_simu = 1000;
    double T_sn = 1.0;
    double t_refresh = 0.1;
    int N_thr = 100;
    
    
    
    
    
    Signal_mc * SNmc_3003 = new Signal_mc();
    TString para_file = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code4/parameters/SN_3003_old.json";
    
    SNmc_3003->set_num_simu(num_of_simu);
    SNmc_3003->run_mc(para_file, num_of_simu);
    SNmc_3003->time_window(3003, T_sn, t_refresh, N_thr);
    
   
    return 1;
}

