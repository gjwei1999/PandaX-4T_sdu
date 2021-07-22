/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#include <iostream>

#include "TF1.h"

#include "eff_far.hpp"

Eff_far::Eff_far(){}
Eff_far::~Eff_far(){}


Double_t term34_func(Double_t *x, Double_t *par);

double Eff_far::trigger_effeciency(int num_thr, double time_sn, double rate_sn, double rate_bkg){
    
    double efficiency;
    
    double item1 = Possion(0, time_sn, rate_bkg) * Erlang_integral(num_thr, time_sn, rate_sn);
    
    double item2 = 0.0;
    for(int j=1; j<num_thr; j++){
        item2 += Possion(j, time_sn, rate_sn) * Erlang_integral(num_thr-j, time_sn, rate_sn);
    }
    item2 *= Possion(0, time_sn, rate_bkg);
     
    double item3 = (1 - Possion(0, time_sn, rate_bkg)) * Average_prob1(num_thr, time_sn, rate_sn);
    
    double item4 = (1 - Possion(0, time_sn, rate_bkg)) * Average_prob2(num_thr, time_sn, rate_sn);
    
//     double term34 = 0;
//     
//     TF1 *f34 = new TF1("term34",term34_func, 0.0, time_sn, 2);
//     f34->SetParameters(num_thr, time_sn);
//     term34 = f34->Integral(0.2, time_sn-0.2);
//     
//     term34 = (1 - Possion(0, time_sn, rate_bkg)) * term34 / time_sn;
//    
//     efficiency = item1 + item2 + term34;
    
    efficiency = item1 + item2 + item3 + item4;
    
    
//     std::cout<<"**************"<<std::endl;
//     std::cout<<"item1 = "<<item1<<std::endl;
//     std::cout<<"item2 = "<<item2<<std::endl;
//     std::cout<<"item3 = "<<item3<<std::endl;
//     std::cout<<"item4 = "<<item4<<std::endl;
//     std::cout<<"The efficiency = "<<efficiency<<std::endl;
    
    return efficiency;
}


double Eff_far::Erlang_integral(int num_thr, double time_sn, double rate_sn){
    
    double item = 0;
    double result = 0;
    for(int i=0; i < num_thr; i++){
        
        item = TMath::Exp(-1.0 * rate_sn * time_sn) * TMath::Power(rate_sn * time_sn, i) / TMath::Factorial(i);
        result += item;
        
    }
    result = 1.0 - result;
    
    return result;
}


double Eff_far::Possion(int k, double time, double rate){
    
    double possion;
    possion = TMath::Power(rate * time, k) / TMath::Factorial(k) * TMath::Exp(-1.0 * rate * time);
    
    return possion;
}

double Eff_far::Average_prob1(int num_thr, double time_sn, double rate_sn){
    
    double t0 = 0.0;
    double d = time_sn/500.0;
    double total = 0.0;
    
    //while(t0 <= time_sn){
    //    total += Erlang_integral(num_thr-1, time_sn - t0, rate_sn) * d;
    //    t0 += d;
    //}
    
    while(t0 < time_sn){
        t0 += d;
        total += Erlang_integral(num_thr-1, time_sn - t0, rate_sn);
    }
    total += 0.5*Erlang_integral(num_thr-1, time_sn, rate_sn) + 0.5*Erlang_integral(num_thr-1, 0.0, rate_sn);;
    total *= d;
    
    total /= time_sn;
    
    return total;
}

double Eff_far::Average_prob2(int num_thr, double time_sn, double rate_sn){
    
    double t0;
    double d = time_sn/500.0;
    double integral;
    double total = 0.0;
    
    for(int j=0; j<num_thr-1; j++){
        
        t0 = 0.0;
        integral = 0.0;
        
        //while(t0 <= time_sn){
        //    integral += Possion(j, time_sn - t0, rate_sn) * Erlang_integral(num_thr-j-1, time_sn, rate_sn)*d;
        //    t0 += d;
        //}
        //std::cout<<"integral = "<<integral<<std::endl;
        while(t0 < time_sn){
            t0 += d;
            integral += Possion(j, time_sn - t0, rate_sn);
        }
        integral += 0.5*Possion(j, time_sn, rate_sn) + 0.5*Possion(j, 0.0, rate_sn);
        integral *= d*Erlang_integral(num_thr-j-1, time_sn, rate_sn);
        
        total += integral;
    }
        
    total /= time_sn;
    
    return total;
}


double Eff_far::false_alert_rate(int num_thr, double time_sn, double rate_bkg){
    
    double far = 0.0;
    far = Erlang_integral(num_thr, time_sn, rate_bkg);
    
    for(int j=1; j<num_thr; j++){
        far += Possion(j, time_sn, rate_bkg) * Erlang_integral(num_thr-j, time_sn, rate_bkg);
    }
    
    far *= rate_bkg*3600.0*24.0*7.0;//unit in per week
    
    return far;
}


double Eff_far::trigger_eff_min(int num_thr, double time_sn, double rate_sn, double rate_bkg){
    
    double eff_min;
    
    double item1 = Possion(0, time_sn, rate_bkg) * Erlang_integral(num_thr, time_sn, rate_sn);
    
    double item2 = 0.0;
    for(int j=1; j<num_thr; j++){
        item2 += Possion(j, time_sn, rate_sn) * Erlang_integral(num_thr-j, time_sn, rate_sn);
    }
    item2 *= Possion(0, time_sn, rate_bkg);
     
    double t0_min;
    TF1 *f34 = new TF1("term34",term34_func, 0.0, time_sn, 2);
    f34->SetParameters(num_thr, time_sn);
    t0_min = f34->GetMinimumX(0.0, time_sn);
    
    
    double item3 = (1 - Possion(0, time_sn, rate_bkg)) * Erlang_integral(num_thr-1, time_sn-t0_min, rate_sn);
    
    double item4 = 0.0;
    for(int j=0; j<num_thr-1; j++){
        item4 += Possion(j, time_sn-t0_min, rate_sn)*Erlang_integral(num_thr-j-1, time_sn, rate_sn);
    }
    item4 *= (1 - Possion(0, time_sn, rate_bkg));
    
    
    eff_min = item1 + item2 + item3 + item4;
    
    return eff_min;
}


Double_t term34_func(Double_t *x, Double_t *par){
    
    Float_t t0 =x[0];
    int num_thr = par[0];
    double time_sn = par[1];
    double rate_sn = 12.0;
    
    Eff_far * eff_func = new Eff_far();
    
    double item = 0.0;
    Double_t f1 = 0.0;
    Double_t f2 = 0.0;
    
    for(int i=0; i < num_thr-1; i++){
        
        item = TMath::Exp(-1.0 * rate_sn * (time_sn-t0)) * TMath::Power(rate_sn * (time_sn-t0), i) / TMath::Factorial(i);
        f1 += item;
        
    }
    f1 = 1.0 - f1;
    
    for(int j=0; j<num_thr-1; j++){
        f2 += eff_func->Possion(j, time_sn - t0, rate_sn) * eff_func->Erlang_integral(num_thr-j-1, time_sn, rate_sn);
    }
    
    Double_t f_total = f1 + f2;
    
    
    delete eff_func;
    
    return f_total;
}

// void Eff_far::eff_vs_Tsn(int num_thr, double rate_sn, TFile * root_file){
//     
//     std::string hist_name = Form("eff_Tsn_n%d_r%.2f", num_thr, rate_sn);
//     
//     TH1D * h_eff_Tsn = new TH1D(hist_name.c_str(), "", nbin, Tsn_min, Tsn_max);
//     
//     double h = (Tsn_max -Tsn_min)/nbin;//step size
//     double t = 0;
//     
//     for(int i=0; i<nbin; i++){
//         
//         t = Tsn_min + i * h;
//         h_eff_Tsn->SetBinContent(i, trigger_effeciency(num_thr, t, rate_sn));
//         h_eff_Tsn->SetBinError(i, 0.0);
//     }
//     
//     h_eff_Tsn->SetDirectory(root_file);
//     
// }
// 
// void Eff_far::eff_vs_rate(int num_thr, double time_sn, TFile * root_file){
//     
//     std::string hist_name = Form("eff_rate_n%d_Tsn%.1f", num_thr, time_sn);
//     
//     TH1D * h_eff_Rsn = new TH1D(hist_name.c_str(), "", nbin, rate_sn_min, rate_sn_max);
//     
//     double h = (rate_sn_max - rate_sn_min)/nbin;//step size
//     double r = 0;
//     
//     for(int i=0; i<nbin; i++){
//         
//         r = rate_sn_min + i *h;
//         h_eff_Rsn->SetBinContent(i, trigger_effeciency(num_thr, time_sn, r));
//     }
//     
//     h_eff_Rsn->SetDirectory(root_file);
// }

