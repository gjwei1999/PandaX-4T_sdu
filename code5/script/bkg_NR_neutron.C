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
    
    TString NR_neutron = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code4/NR_neutron.dat";
    
    double NR_neutron_e_tmp;
    double NR_neutron_r_tmp;
    int n_NR_neutron = 65;
    
    std::vector<double> NR_neutron_energy;
    std::vector<double> NR_neutron_rate;
    std::ifstream infile(NR_neutron);
    
    for(int i=0; i<n_NR_neutron; i++){
        
        infile >> NR_neutron_e_tmp >> NR_neutron_r_tmp;
        
        NR_neutron_energy.push_back(NR_neutron_e_tmp);
        NR_neutron_rate.push_back(NR_neutron_r_tmp);
    
    }
    infile.close();
    
    ROOT::Math::Interpolator * interpolation = new ROOT::Math::Interpolator(NR_neutron_energy, NR_neutron_rate, ROOT::Math::Interpolation::kLINEAR);
    
    int nbin = 1000;
    TH1D * NR_neutron_bkg = new TH1D("NR_neutron_bkg", "NR_neutron_bkg", nbin, 0.0, 59.5); 
    
    for(int i=0; i<nbin; i++){
        
        Double_t x = i * 59.5/nbin;
        Double_t y = interpolation->Eval(x);
        NR_neutron_bkg->SetBinContent(i,y);
        
    }
    
    double integral;
    
    integral = NR_neutron_bkg->Integral("width");//unit: day-1 t-1)
    //for pandax-4T
    integral = integral * 4.0;//unit: day-1
    
    std::cout<<"!!!!!!!!!"<<std::endl;
    std::cout<<"the NR_neutron bkg rate for PandaX-4T is "<<integral<<" per day."<<std::endl;
    
    return 1;
}
