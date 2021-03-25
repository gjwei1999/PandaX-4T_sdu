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
    
    double rate_bkg = (7558.48 + 9.20852 + 0.00874182) / 24.0 / 60.0 / 60.0;
public:
    
    Eff_far();
    virtual ~Eff_far();
    
    double trigger_effeciency(int num_thr, double time_sn, double rate_sn);
    double false_alert_rate(int num_thr, double time_sn);
    
    void eff_vs_Tsn(int num_thr, double rate_sn, TFile * root_file);
    void eff_vs_rate(int num_thr, double time_sn, TFile * root_file);
    
};


#endif
