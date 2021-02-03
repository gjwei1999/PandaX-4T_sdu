/*****************************/
/*                                                      */
/*       Created by Jiawei Guo          */
/*        Shandong University            */
/*                                                      */
/*****************************/

#ifndef BKG_H
#define BKG_H

#include <iostream>

class Bkg{
    
private:
    
//    std::vector<double_t> E_ER;//unit keV
//    std::vector<double_t> rate_ER;//unit 10-3 day-1 kg-1 keV-1
    
//    std::vector<double_t> E_NR_neutron;//unit t-1 day-1 keV-1
//    std::vector<double_t> rate_NR_neutron;//unit keV
    
//    std::vector<double_t> E_NR_neutrino;//unit keV
//    std::vector<double_t> rate_NR_neutrino;//unit t-1 day-1 keV-1
    
public:
    
    Bkg();
    virtual ~Bkg();
    
    void Set_ER_data();
    void Set_NR_neutron();
    void Set_NR_neutrino();
    
    
};

#endif
