/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#include "TMath.h"
#include "TFile.h"

#include "histogram.hpp"

Histogram::Histogram(){};
Histogram::~Histogram(){};

void Histogram::Set_h_event_time(int nbin){
    
    nbin_event_time = nbin;
    h_event_time = new TH1D("event_time", "event_time", nbin, 0.0, nbin);
}

void Histogram::Set_h_detected_event_time(int nbin){
    
    h_detected_event_time = new TH1D("detected_event_time", "detected_event_time", nbin, 0.0, nbin);
}


void Histogram::Fill_event_time(Branches * branch){
    h_event_time->Fill(branch->get_event_time());
}

void Histogram::Fill_detected_event_time(Branches * branch){
    
    if((branch->get_S1d() > 0.0) && (branch->get_S2d() > 0.0)){
        h_detected_event_time->Fill(branch->get_event_time());
    }
    
}

void Histogram::Fill_logs2s1_s1(Branches * branch){
    
    double temp;
    temp = TMath::Log(branch->get_S2d()/branch->get_S1d());
    h_logs2s1_s1->Fill(branch->get_S1d(), temp);
    
}

void Histogram::Set_h_error(){
    
    for(int i; i<nbin_event_time; i++){
        h_event_time->SetBinError(i, 0.0);
        h_detected_event_time->SetBinError(i, 0.0);
    }
    
}

void Histogram::Write(TFile *rootfile){
    h_event_time->SetDirectory(rootfile);
    h_detected_event_time->SetDirectory(rootfile);
    h_logs2s1_s1->SetDirectory(rootfile);
}
