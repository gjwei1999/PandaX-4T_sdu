#include "integral.h"


int main(){
    
    TString path2 = "/Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code1/build/";
    TString root_recE_spec = path2 + "recE_spec.root";
    
    TFile * fs1 = new TFile(root_recE_spec.Data(), "RECREATE");
    
    Integral * int_1301e = new Integral();
    
    int_1301e->set_hist("1301electron");
    int_1301e->set_flux_point();
    int_1301e->numerical_int("1301electron", fs1);
    
    fs1->Write();
    
    return 1;
}
