/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#include <iostream>

#include "TFile.h"
#include "TMath.h"
#include "TH1D.h"

int main(int argc, char* argv[]){
    
//    if(argc != 2){
//        std::cout<<"Error. The input parameters are wrong."<<std::endl;
//        std::cout<<"Usage: "<<argv[0]<<" input_root_file"<<std::endl;
//        
//        return 1;
//    }
    
    TString loadpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/output/";
    //TString loadfile = argv[1];
    
    TFile *fs = new TFile(loadpath + "3003_result.root", "r");
    
    TH1D * h = (TH1D *) fs->Get("detected_event_time");
    
    int n = 0;
    int num_nthr2 = 0;//number of sending alert with N_thr=2
    int num_nthr3 = 0;//number of sending alert with N_thr=3
    int num_nthr4 = 0;//number of sending alert with N_thr=4
    
    for(int i = 1;i<1e4+1;i++){
        
        n = h->GetBinContent(i);    
        if(n>=2){num_nthr2++;}
        if(n>=3){num_nthr3++;}
        if(n>=4){num_nthr4++;}

    }

    std::cout<<num_nthr2<<" alerts are sent if N_the = 2"<<std::endl;
    std::cout<<"The trigger efficiency is "<<num_nthr2/1e4<<std::endl;
    
    std::cout<<num_nthr3<<" alerts are sent if N_the = 3"<<std::endl;
    std::cout<<"The trigger efficiency is "<<num_nthr3/1e4<<std::endl;
    
    std::cout<<num_nthr3<<" alerts are sent if N_the = 3"<<std::endl;
    std::cout<<"The trigger efficiency is "<<num_nthr4/1e4<<std::endl;
    
    return 1;
}
