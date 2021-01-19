/*****************************/
/*                                                      */
/*       Created by Jiawei Guo          */
/*        Shandong University            */
/*                                                      */
/*****************************/

#include "branches.hpp"

int main(int argc, char* argv[]){
    
    //to run the code
    // ./analysis input_file
    
    if(argc != 2){
        std::cout<<"Error. The input parameters are wrong."<<std::endl;
        std::cout<<"Usage: "<<argv[0]<<" input_root_file"<<std::endl;
    }
    
    std::string input = argv[1];
    
    auto chain = std::make_shared<TChain>("qmc_tree");
    chain->Add(input.c_str());
    
    int num_of_events;
    num_of_events = (int)chain->GetEntries();
    
    auto data = std::make_shared<Branches>(chain);
    
    
    for (int current_event = 0; current_event < num_of_events; current_event++) {
        
        // Get current event
        chain->GetEntry(current_event);        
        
        
        
    }
    return 1;
}
