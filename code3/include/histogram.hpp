/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "branches.hpp"

#include "TH1D.h"
#include "TH2D.h"

class Histogram{
    
private:
    
    int nbin_event_time;
    
    TH1D * h_event_time;// = new TH1D();
    TH1D * h_detected_event_time;// = new TH1D();
    
    TH2D * h_logs2s1_s1= new TH2D("logs2s1_s1", "", 100, 0.0, 150.0, 100, 1.0, 10.0);
    
public:
    
    Histogram();
    virtual ~Histogram();
    
    void Set_h_event_time(int nbin);
    void Set_h_detected_event_time(int nbin);
    
    void Fill_event_time(Branches * branch);
    void Fill_detected_event_time(Branches * branch);
    
    void Fill_logs2s1_s1(Branches * branch);
    
    void Set_h_error();
    
    void Write(TFile *rootfile);
    
};


#endif
