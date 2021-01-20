/*****************************/
/*                                                      */
/*       Created by Jiawei Guo          */
/*        Shandong University            */
/*                                                      */
/*****************************/

#include <cmath>
#include "TFile.h"
#include "TH1D.h"
#include "TString.h"


int main(){
    
    TString loadpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code1_SN/build/";
    TFile *fs = new TFile(loadpath + "recE_spec_total.root", "r");
    
    TH1D * h3003 = (TH1D *) fs->Get("3003_total_recoil");
    
    int bin_num_left = h3003->GetBin(0.0);
    int bin_num_right = h3003->GetBin(100.0);
    
    double num_of_events;
    
    num_of_events = h3003->Integral(bin_num_left, bin_num_right);
    
    std::cout<<"The number of events in the first second is "<<num_of_events<<std::endl;
    
    return 1;
}
