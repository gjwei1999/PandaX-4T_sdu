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
    
    double result_cal=0.0;
    
public:

    Spec();
    virtual ~Spec();
    
    void generate_spec(double input_distance, int type_of_sn);
    void num_integral();
    void int_get_total(TFile * root_name1, TFile * root_name2);
    
    void cal_events();
    
    int get_events();
    
};





#endif
