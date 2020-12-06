#ifndef _SPECTRUM_H
#define _SPECTRUM_H

#include "TString.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TFile.h"

class Spectrum{


public: 
    //constructor
    Spectrum();
    
public:
    //destructor
    virtual ~Spectrum();

private:
    //path of data
    TString path1 = "/Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/SN_database/";
    
    double tmin =  -5.0e-2; //unit of second
    double tmax = 20.0;
    double neu_Emin = 0.0;
    double neu_Emax = 300.0;
    
public:
    void time_spectrum(TString filename, TFile *rootfile);
    
    
public:
    void energy_spectrum(TString filename, TFile *rootfile);
    

};



#endif        

