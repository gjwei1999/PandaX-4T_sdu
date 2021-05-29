/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#include "Math/Functor.h"
#include "Math/WrappedTF1.h"
#include "Math/GSLIntegrator.h"
#include "Math/Interpolator.h"
#include "Math/WrappedParamFunction.h"
#include "Math/Integrator.h"
#include "Math/IntegratorMultiDim.h"
#include "Math/AllIntegrationTypes.h"
#include "Math/SpecFuncMathCore.h"

#include "xsection.hpp"

Xsection::Xsection(){
    
}

Xsection::~Xsection(){
    
}

double Xsection::cross_section(double neu_energy){
    //neu_energy should be in MeV 
    
    double xsection_neuE = G_f*G_f * ( Z*(4.0*sin2theta-1.0)+N )*( Z*(4.0*sin2theta-1.0)+N ) * neu_energy * neu_energy /8.0/M_PI;
                 //unit: MeV^{-2}
    //convert MeV^{-2} to cm^2
    xsection_neuE = xsection_neuE * 0.197e-10 * 0.197e-10;
    
    return xsection_neuE;
}

double Xsection::xs_recE(double neu_energy, double recoil_energy){//neu_energy in MeV, recoil_energy in keV
    
    double xs_recE = G_f*G_f * ( Z*(4.0*sin2theta-1.0)+N )*( Z*(4.0*sin2theta-1.0)+N ) * mass_xenon * (1-(mass_xenon*recoil_energy/2.0/1000.0/neu_energy/neu_energy))/4.0/M_PI;
    //unit: MeV^{-3}
    
    //convert MeV^{-2} to cm^2
    xs_recE = xs_recE * 0.197e-10 * 0.197e-10 * form_factor(recoil_energy)* form_factor(recoil_energy);
    //unit: cm^2/MeV
    
    return xs_recE;

}

double Xsection::form_factor(double recoil_energy){//recoil_energy in keV
    
    double q2 = 2 * mass_xenon * recoil_energy / 1000.0;//MeV*MeV
    double q = TMath::Sqrt(q2);//MeV
    
    double a = 0.52;//fm
    double c = 1.23*TMath::Power(131.293, 1.0/3.0) - 0.6;//fm
    double s = 0.9;//fm
    
    double rn2 = c*c +7.0/3.0*M_PI*M_PI*a*a- 5*s*s;//fm*fm
    double rn = TMath::Sqrt(rn2);//fm
    
    double qrn = q*rn * 1.0e-9 / 1.97e-7;
    
    double j1 = TMath::Sin(qrn)/(qrn)/(qrn) - TMath::Cos(qrn)/(qrn);
    double qs = q*s * 1.0e-9 / 1.97e-7;
    
    double ffacotr = 3 * j1 / (qrn) * TMath::Exp(-(qs)*(qs)/2.0);
    
    return ffacotr;
}


