/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#ifndef SPECTRUM_SN_H
#define SPECTRUM_SN_H

#include "integral.hpp"
#include "spectrum.hpp"
#include "xsection.hpp"

class Spec{

private:
    
    double result_cal[4][3]={0.0};
    
public:

    Spec();
    virtual ~Spec();
    
    void generate_spec(double input_distance);
    void num_integral();
    void int_get_total(TFile * root_name1, TFile * root_name2, TString hist_name_total, TString hist_name_electron, TString hist_name_antielectron, TString hist_name_x);
    
    void cal_events();
    
    int get_1301();
    int get_1302();
    int get_1303();
    
    int get_2001();
    int get_2002();
    int get_2003();
    
    int get_3001();
    int get_3002();
    int get_3003();
    
    int get_5001();
    int get_5002();
    int get_5003();
    
};





#endif
