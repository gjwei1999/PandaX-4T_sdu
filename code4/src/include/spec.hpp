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
    
    
    

public:

    Spec();
    virtual ~Spec();
    
    void generate_spec(double input_distance);
    void num_integral();
    void int_get_total(TFile * root_name1, TFile * root_name2, TString hist_name_total, TString hist_name_electron, TString hist_name_antielectron, TString hist_name_x);
    
    
};






#endif
