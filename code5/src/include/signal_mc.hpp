/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#ifndef SIGNAL_MC_H
#define SIGNAL_MC_H

#include "det-sim.hpp"
#include "pandax-quanta.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <TFile.h>
#include <TGraph.h>
#include <TTree.h>
#include <TKey.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TF1.h>
#include <TRandom.h>
#include "TString.h"

#include "json.hpp"

class Signal_mc {
    
private:
    
    TTree * tree_sorted;
    
    TString loadpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code5/output/sorted_tree/simu_result.root";
    TString outpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code5/output/event_time_hist/analysis_result.root";
    
    int num_of_simu;
    
public:
    Signal_mc();
    virtual ~Signal_mc();

    
    void run_mc(TString para_file, int num_of_simulation, int events_in_20s);
    //void sort(TTree *tree, TFile *fout);
    void set_num_simu(int input_num_of_simu);
    double time_window(double T_sn, double t_refresh, int N_thr);
    
};



#endif
