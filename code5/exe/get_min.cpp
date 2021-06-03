/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#include <iostream>

#include "TFile.h"
#include "TMath.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TGraph.h"
#include "TLatex.h"
#include "TF1.h"
#include "TF2.h"
//#include "TROOT.h"

Double_t term3_func(Double_t *x, Double_t *par);
Double_t term4_func(Double_t *x, Double_t *par);
Double_t term34_func(Double_t *x, Double_t *par);
Double_t term34_2Dfunc(Double_t *x, Double_t *par);

double Possion(int k, double time, double rate);
double Erlang_integral(int num_thr, double time_sn, double rate_sn);


int main(){
    
    TString path = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code5/output/";
    
    TFile *fs = new TFile(path+"get_min.root", "recreate");
    
    int num_thr = 15;
    double time_sn = 1.0;
    
    TF1 *f1 = new TF1("term3",term3_func, 0.0, 1.0, 2);
    f1->SetParameters(num_thr, time_sn);
    f1->SetParNames("N_thr","T_sn");
    
    TF1 *f2 = new TF1("term4",term4_func, 0.0, 1.0, 2);
    f2->SetParameters(num_thr, time_sn);
    f2->SetParNames("N_thr","T_sn");

    TF1 *f3 = new TF1("term34",term34_func, 0.0, 1.0, 2);
    f3->SetParameters(num_thr, time_sn);
    f3->SetParNames("N_thr","T_sn");

    f1->Write();
    f2->Write();
    f3->Write();
    
    TF2 *f1_2 = new TF2("2Dterm34", term34_2Dfunc, 0.0, 1.0, 2.0, 18.0, 0, 2);
    f1_2->GetXaxis()->SetTitle("t_{0} (s)");
    f1_2->GetYaxis()->SetTitle("N_{thr}");
    f1_2->Draw("SURF2");
    f1_2->Write();
    
    fs->Write();
    
    double minX = 0.0;
    
    for(int j=2; j<19; j++){
        
        f3->SetParameters(j, time_sn);
        minX = f3->GetMinimumX(0.0, 1.0);
        std::cout<<"minX for nthr = "<<j<<" is "<< minX<<std::endl;
    }
    
    double d=0.1;
    for(int k=0; k<20; k++){
        time_sn = 1.0 + k*d;
        TF1 *f3 = new TF1("term34",term34_func, 0.0, time_sn, 2);
        f3->SetParameters(14, time_sn);
        minX = f3->GetMinimumX(0.0, time_sn);
        std::cout<<"minX for time_sn = "<<time_sn<<" is "<< minX<<std::endl;
        
    }
    
}


Double_t term3_func(Double_t *x, Double_t *par){
   Float_t t0 =x[0];
   int num_thr = par[0];
   double time_sn = par[1];
   
   double rate_sn = 12.0;
   
   double item = 0.0;
   Double_t f = 0.0;
   
   for(int i=0; i < num_thr-1; i++){
        
        item = TMath::Exp(-1.0 * rate_sn * (time_sn-t0)) * TMath::Power(rate_sn * (time_sn-t0), i) / TMath::Factorial(i);
        f += item;
        
    }
    f = 1.0 - f;
   
   return f;
}


Double_t term4_func(Double_t *x, Double_t *par){
    
    Float_t t0 =x[0];
    int num_thr = par[0];
    double time_sn = par[1];
    double rate_sn = 12.0;
    
    Double_t f = 0.0;
    
    for(int j=0; j<num_thr-1; j++){
        f += Possion(j, time_sn - t0, rate_sn) * Erlang_integral(num_thr-j-1, time_sn, rate_sn);
    }
    
    return f;
}
    
Double_t term34_func(Double_t *x, Double_t *par){
    
    Float_t t0 =x[0];
    int num_thr = par[0];
    double time_sn = par[1];
    double rate_sn = 12.0;
    
    double item = 0.0;
    Double_t f1 = 0.0;
    Double_t f2 = 0.0;
    
    for(int i=0; i < num_thr-1; i++){
        
        item = TMath::Exp(-1.0 * rate_sn * (time_sn-t0)) * TMath::Power(rate_sn * (time_sn-t0), i) / TMath::Factorial(i);
        f1 += item;
        
    }
    f1 = 1.0 - f1;
    
    for(int j=0; j<num_thr-1; j++){
        f2 += Possion(j, time_sn - t0, rate_sn) * Erlang_integral(num_thr-j-1, time_sn, rate_sn);
    }
    
    
    
    Double_t f_total = f1 + f2;
    
    return f_total;
}


    
double Possion(int k, double time, double rate){
    
    double possion;
    possion = TMath::Power(rate * time, k) / TMath::Factorial(k) * TMath::Exp(-1.0 * rate * time);
    
    return possion;
}

double Erlang_integral(int num_thr, double time_sn, double rate_sn){
    
    double item = 0;
    double result = 0;
    for(int i=0; i < num_thr; i++){
        
        item = TMath::Exp(-1.0 * rate_sn * time_sn) * TMath::Power(rate_sn * time_sn, i) / TMath::Factorial(i);
        result += item;
        
    }
    result = 1.0 - result;
    
    return result;
}
    
Double_t term34_2Dfunc(Double_t *x, Double_t *par){
    
    Float_t t0 =x[0];
    int num_thr = x[1];
    
    double time_sn = 1.0;
    double rate_sn = 12.0;
    
    double item = 0.0;
    Double_t f1 = 0.0;
    Double_t f2 = 0.0;
    
    for(int i=0; i < num_thr-1; i++){
        
        item = TMath::Exp(-1.0 * rate_sn * (time_sn-t0)) * TMath::Power(rate_sn * (time_sn-t0), i) / TMath::Factorial(i);
        f1 += item;
        
    }
    f1 = 1.0 - f1;
    
    for(int j=0; j<num_thr-1; j++){
        f2 += Possion(j, time_sn - t0, rate_sn) * Erlang_integral(num_thr-j-1, time_sn, rate_sn);
    }
    
    
    
    Double_t f_total = f1 + f2;
    
    return f_total;
}

    
