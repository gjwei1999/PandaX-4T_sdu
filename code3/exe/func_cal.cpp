/*****************************/
/*                                                      */
/*       Created by Jiawei Guo          */
/*        Shandong University            */
/*                                                      */
/*****************************/

#include <iostream>

#include "TMath.h"
#include "TH1D.h"

double trigger_effeciency(int num_thr, double time_sn, double rate_sn);

int main(){
    
    double ans;
    ans = trigger_effeciency(2, 0.1, 10.0);
    
    std::cout<<"f(2, 0.1 ,10.0) = "<< ans <<std::endl;
    
    return 1;
}


double trigger_effeciency(int num_thr, double time_sn, double rate_sn){
    
    double item = 0;
    double effeciency = 0;
    for(int i=0; i < num_thr; i++){
        
        item = TMath::Exp(-1.0 * rate_sn * time_sn) * TMath::Power(rate_sn * time_sn, i) / TMath::Factorial(i);
        effeciency += item;
        
    }
    
    effeciency = 1.0 - effeciency;
    
    return effeciency;
}
