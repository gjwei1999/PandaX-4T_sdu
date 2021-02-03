/*****************************/
/*                                                      */
/*       Created by Jiawei Guo          */
/*        Shandong University            */
/*                                                      */
/*****************************/

#include "TFile.h"
#include "TMath.h"
#include "TH1D.h"

#include "eff_far.hpp"

int main(){
    
    TString path1 = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/output/";
    TString eff_root = path1+ "eff.root";
    
    TFile *fs1 = new TFile(eff_root.Data(), "RECREATE");
    
    Eff_far * eff_far1 = new Eff_far();
    
    eff_far1->eff_vs_Tsn(2, 2.0, fs1);
    eff_far1->eff_vs_Tsn(2, 4.0, fs1);
    eff_far1->eff_vs_Tsn(2, 6.0, fs1);
    eff_far1->eff_vs_Tsn(2, 8.0, fs1);
    eff_far1->eff_vs_Tsn(2, 10.0, fs1);
    
    eff_far1->eff_vs_rate(2, 1.0, fs1);
    eff_far1->eff_vs_rate(3, 1.0, fs1);
    eff_far1->eff_vs_rate(4, 1.0, fs1);
    eff_far1->eff_vs_rate(5, 1.0, fs1);
    
    fs1->Write();
    
    
    return 1;
}
