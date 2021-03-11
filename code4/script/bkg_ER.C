/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#include <iostream>
#include <fstream>
#include <cmath>

#include "TString.h"
#include "TFile.h"
#include "TH1.h"
#include "TH1D.h"
#include "Math/Interpolator.h"


int main(){
    
    TString ER = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code4/ER.dat";
    
    double ER_e_tmp;
    double ER_r_tmp;
    int n_ER = 127;
    
    std::vector<double> ER_energy;
    std::vector<double> ER_rate;
    std::ifstream infile(ER);
    
    for(int i=0; i<n_ER; i++){
        
        infile >> ER_e_tmp >> ER_r_tmp;
        
        ER_energy.push_back(ER_e_tmp);
        ER_rate.push_back(ER_r_tmp);
    
    }
    infile.close();
    
    ROOT::Math::Interpolator * interpolation = new ROOT::Math::Interpolator(ER_energy, ER_rate, ROOT::Math::Interpolation::kLINEAR);
    
    int nbin = 1000;
    TH1D * ER_bkg = new TH1D("ER_bkg", "ER_bkg", nbin, 0.0, 2690.0); 
    
    for(int i=0; i<nbin; i++){
        
        Double_t x = i * 2690.0/nbin;
        Double_t y = interpolation->Eval(x);
        ER_bkg->SetBinContent(i,y);
        
    }
    
    double integral;
    
    integral = ER_bkg->Integral("width");//unit: 1e-3 day-1 kg-1(day-1 t-1)
    //for pandax-4T
    integral = integral * 4.0;//unit: day-1
    
    std::cout<<"!!!!!!!!!"<<std::endl;
    std::cout<<"the ER bkg rate for PandaX-4T is "<<integral<<" per day."<<std::endl;
    
    
    return 1;
}
