/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#ifndef _XSECTION_H
#define _XSECTION_H


class Xsection{
    
public:
    //constructor
    Xsection();
    
public:
    //destructor
    virtual ~Xsection();
    
private:
    double G_f = 1.1663787e-11;// MeV^{-2},Fermi coupling constant
    int Z = 54;
    double sin2theta = 0.23867;
    double N = 131.293 - 54.0;
    double mass_xenon = 131.293 * 1.66e-24 /1.8 * 1e27;//unit: MeV
    
public:
    double cross_section(double neu_energy);
    double xs_recE(double neu_energy, double recoil_energy);
    double form_factor(double recoil_energy);

};


#endif
