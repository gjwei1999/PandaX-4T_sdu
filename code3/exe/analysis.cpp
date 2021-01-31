/*****************************/
/*                                                      */
/*       Created by Jiawei Guo          */
/*        Shandong University            */
/*                                                      */
/*****************************/

#include "TFile.h"
#include "branches.hpp"

int main(int argc, char* argv[]){
    
    //to run the code
    // ./analysis input_file

    if(argc != 2){
        std::cout<<"Error. The input parameters are wrong."<<std::endl;
        std::cout<<"Usage: "<<argv[0]<<" input_root_file"<<std::endl;
    }
    
    std::string input = argv[1];
    
    TFile *fs = new TFile(input.c_str(), "r");
    TTree *t1 = (TTree*)fs->Get("qmc_tree");
    
    int num_of_events;
    num_of_events = (int)t1->GetEntries();

    
    Branches * branch1 = new Branches();
    branch1->init(t1);
    
    
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
        
        //std::cout<<"current event energy is "<<branch1->get_nQuanta()<<std::endl;
        
        
    }
    
    std::cout<<"input "<< num_of_events <<" events "<<std::endl;
    std::cout<<"detected "<< n_s1d <<" S1 signal "<<std::endl;
    std::cout<<"detected "<< n_s2d <<" S2 signal "<<std::endl;
    std::cout<<"detected "<< n_s1d_s2d <<" S1 S2 signal "<<std::endl;
    
    return 1;
}
