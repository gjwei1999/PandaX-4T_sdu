/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#ifndef EFF_FAR_H
#define EFF_FAR_H

#include "TH1D.h"
#include "TH2D.h"
#include "TMath.h"
#include "TFile.h"

class Eff_far{
    
private:
    
    int nbin = 1000;
    
    double Tsn_min = 0.01;
    double Tsn_max = 2.0; 
    
    double rate_sn_min = 0.0;
    double rate_sn_max = 15;
    
public:
    
    Eff_far();
    virtual ~Eff_far();
    
    double trigger_effeciency(int num_thr, double time_sn, double rate_sn, double rate_bkg);
    double false_alert_rate(int num_thr, double time_sn, double rate_bkg);
  
    double Erlang_integral(int num_thr, double time_sn, double rate_sn);
    double Possion(int k, double time, double rate);
    double Average_prob1(int num_thr, double time_sn, double rate_sn);
    double Average_prob2(int num_thr, double time_sn, double rate_sn);
    
    double trigger_eff_min(int num_thr, double time_sn, double rate_sn, double rate_bkg);
    //Double_t term34_func(Double_t *x, Double_t *par);
//    void eff_vs_Tsn(int num_thr, double rate_sn, TFile * root_file);
//    void eff_vs_rate(int num_thr, double time_sn, TFile * root_file);
    
};


#endif
