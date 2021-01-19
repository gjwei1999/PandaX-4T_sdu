//#ifndef _INTEGRAL_H
//#define _INTEGRAL_H

#include "TString.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"

class Integral{
    
public: 
    //constructor
     Integral();
    
public:
    //destructor
    virtual ~ Integral(); 

private:
    TH1D * h0;
    
    TString loadpath = "/Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code1_SN/build/flux_neuE.root";
    TFile *fs = new TFile(loadpath, "r");
    
    //number of Xenon nuclei in 1 ton
    Double_t num_Xe_ton = 1.0e6/131.29 * 6.02e23;
    
    std::vector<Double_t> E_point = {
 //   Double_t E_point[20] ={
        0.0,
        1.00E+00,
        2.50E+00,
        4.50E+00,
        7.00E+00,
        1.00E+01,
        1.40E+01,
        1.90E+01,
        2.50E+01,
        3.20E+01,
        4.00E+01,
        4.80E+01,
        5.80E+01,
        6.80E+01,
        8.00E+01,
        9.50E+01,
        1.15E+02,
        1.45E+02,
        1.85E+02,
        2.35E+02,
        3.00E+02
    };
    
    std::vector<Double_t> flux_point = {
//    Double_t flux_point[20] = {
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0
    };
    
    
    
public:
    void set_hist(TString hist_name);
    void set_flux_point();
    
    void numerical_int(TString hist_name, TFile * root_name);
    
    
};


