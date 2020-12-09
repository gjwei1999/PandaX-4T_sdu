#include <iostream>
#include <fstream>
#include <cmath>

#include "integral.h"


int main(){
    
    TString path2 = "/Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code1/build/";
    TString root_recE_spec = path2 + "recE_spec.root";
    
    TFile * fs1 = new TFile(root_recE_spec.Data(), "RECREATE");
    
    Integral * int_1301e = new Integral();
    Integral * int_1301antie = new Integral();
    Integral * int_1301x = new Integral();
    
    int name[12] = {1301, 1302, 1303, 2001, 2002, 2003, 3001, 3002, 3003, 5001, 5002, 5003};
    
    for(int i=0; i<12; i++){
        
        int number = name[i];
        
        std::string hist_name_electron = Form("%delectron", number);
        std::string hist_name_antielectron = Form("%danti-electron", number);
        std::string hist_name_x = Form("%dx", number);
    
    int_1301e->set_hist(hist_name_electron.c_str());
    int_1301e->set_flux_point();
    int_1301e->numerical_int(hist_name_electron.c_str(), fs1);
    
    int_1301antie->set_hist(hist_name_antielectron.c_str());
    int_1301antie->set_flux_point();
    int_1301antie->numerical_int(hist_name_antielectron.c_str(), fs1);
    
    int_1301x->set_hist(hist_name_x.c_str());
    int_1301x->set_flux_point();
    int_1301x->numerical_int(hist_name_x.c_str(), fs1);
    
    std::cout<<"----------------------------"<<std::endl;
    std::cout<<number<<" is finished."<<std::endl;
    std::cout<<"----------------------------"<<std::endl;
    
    }
    
    fs1->Write();
    
    return 1;
}
