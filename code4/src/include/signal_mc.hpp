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
    
    
public:
    Signal_mc();
    virtual ~Signal_mc();
    
    TTree * tree_sorted;
    
    void run_mc(TString para_file, int num_of_simulation);
    //void sort(TTree *tree, TFile *fout);
    
};



#endif
