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
    
    TString NR_neu = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code4/NR_neutrino.dat";
    
    double NR_neu_e_tmp;
    double NR_neu_r_tmp;
    int n_NR_neu = 41;
    
    std::vector<double> NR_neu_energy;
    std::vector<double> NR_neu_rate;
    std::ifstream infile(NR_neu);
    
    for(int i=0; i<n_NR_neu; i++){
        
        infile >> NR_neu_e_tmp >> NR_neu_r_tmp;
        
        NR_neu_energy.push_back(NR_neu_e_tmp);
        NR_neu_rate.push_back(NR_neu_r_tmp);
    
    }
    infile.close();
    
    ROOT::Math::Interpolator * interpolation = new ROOT::Math::Interpolator(NR_neu_energy, NR_neu_rate, ROOT::Math::Interpolation::kLINEAR);
    
    int nbin = 1000;
    TH1D * NR_neu_bkg = new TH1D("NR_neu_bkg", "NR_neu_bkg", nbin, 0.0, 88.0); 
    
    for(int i=0; i<nbin; i++){
        
        Double_t x = i * 88.0/nbin;
        Double_t y = interpolation->Eval(x);
        NR_neu_bkg->SetBinContent(i,y);
        
    }
    
    double integral;
    
    integral = NR_neu_bkg->Integral("width");//unit: day-1 t-1)
    //for pandax-4T
    integral = integral * 4.0;//unit: day-1
    
    std::cout<<"!!!!!!!!!"<<std::endl;
    std::cout<<"the NR_neu bkg rate for PandaX-4T is "<<integral<<" per day."<<std::endl;
    
    return 1;
}
