/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

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
    TString path1 = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/SN_database/";
    
    double tmin =  -2.0e-1; //unit of second
    double tmax = 20.0;
    double neu_Emin = 0.0;
    double neu_Emax = 300.0;
    
    int nbin= 5000;
    
    double D; //= 10.0 * 1000.0 * 206264.8 * 1.49598e11 * 100; //D is the distance between Earth and the SN
                       //10kpc = 10 * 1k * 206264.8 * 1.49598e11 * 100 cm
    
    //number of Xenon nuclei in 1 ton
    double num_Xe_ton = 1.0e6/131.29 * 6.02e23;
    
public:
    void time_spectrum(TString filename, TFile *rootfile, TFile *rootfile2); // Y: eventrate(number of events/ ton / s)    X: time (s)
    void flux_time(TString filename, TFile *rootfile);//, TFile *rootfile_spectrum_inter);
    
    void energy_spectrum(TString filename, TFile *rootfile); // Y: eventrate(number of events/ ton / MeV)    X: neu_energy (MeV)
    
    void flux_neuE(TString filename, TFile *rootfile); //in the first 1 second, Y: (number of neutrinos /cm^2/MeV) X: neu_energy(MeV)
    
    void set_distance(double input_distance);//unit kpc
};

#endif        

