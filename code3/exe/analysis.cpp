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
    
    //std::cout<<"the number of events is "<<num_of_events<<std::endl;
    
    Branches * branch1 = new Branches();
    branch1->init(t1);
    
    for (int current_event = 0; current_event < num_of_events; current_event++) {
        
        // Get current event
        t1->GetEntry(current_event);
        
        std::cout<<"current event energy is "<<branch1->get_nQuanta()<<std::endl;
        
        
    }
    return 1;
}
