/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#include "eff_far.hpp"

Eff_far::Eff_far(){}
Eff_far::~Eff_far(){}

double Eff_far::trigger_effeciency(int num_thr, double time_sn, double rate_sn){
    
    double item = 0;
    double effeciency = 0;
    for(int i=0; i < num_thr; i++){
        
        item = TMath::Exp(-1.0 * rate_sn * time_sn) * TMath::Power(rate_sn * time_sn, i) / TMath::Factorial(i);
        effeciency += item;
        
    }
    effeciency = 1.0 - effeciency;
    
    return effeciency;
}

double Eff_far::false_alert_rate(int num_thr, double time_sn){
    
    double far = 0.0;
    far = rate_bkg*3600.0*24.0*7.0*trigger_effeciency(num_thr, time_sn, rate_bkg);
    
    return far;
}

void Eff_far::eff_vs_Tsn(int num_thr, double rate_sn, TFile * root_file){
    
    std::string hist_name = Form("eff_Tsn_n%d_r%.2f", num_thr, rate_sn);
    
    TH1D * h_eff_Tsn = new TH1D(hist_name.c_str(), "", nbin, Tsn_min, Tsn_max);
    
    double h = (Tsn_max -Tsn_min)/nbin;//step size
    double t = 0;
    
    for(int i=0; i<nbin; i++){
        
        t = Tsn_min + i * h;
        h_eff_Tsn->SetBinContent(i, trigger_effeciency(num_thr, t, rate_sn));
        h_eff_Tsn->SetBinError(i, 0.0);
    }
    
    h_eff_Tsn->SetDirectory(root_file);
    
}

void Eff_far::eff_vs_rate(int num_thr, double time_sn, TFile * root_file){
    
    std::string hist_name = Form("eff_rate_n%d_Tsn%.1f", num_thr, time_sn);
    
    TH1D * h_eff_Rsn = new TH1D(hist_name.c_str(), "", nbin, rate_sn_min, rate_sn_max);
    
    double h = (rate_sn_max - rate_sn_min)/nbin;//step size
    double r = 0;
    
    for(int i=0; i<nbin; i++){
        
        r = rate_sn_min + i *h;
        h_eff_Rsn->SetBinContent(i, trigger_effeciency(num_thr, time_sn, r));
    }
    
    h_eff_Rsn->SetDirectory(root_file);
}


