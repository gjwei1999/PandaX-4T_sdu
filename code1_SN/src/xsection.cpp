/*****************************/
/*                                                      */
/*       Created by Jiawei Guo          */
/*        Shandong University            */
/*                                                      */
/*****************************/

#include "Math/Functor.h"
#include "Math/WrappedTF1.h"
#include "Math/GSLIntegrator.h"
#include "Math/Interpolator.h"
#include "Math/WrappedParamFunction.h"
#include "Math/Integrator.h"
#include "Math/IntegratorMultiDim.h"
#include "Math/AllIntegrationTypes.h"
#include "Math/SpecFuncMathCore.h"

#include "xsection.h"

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
    
    //convert MeV^{-2} to cm^2
    xs_recE = xs_recE * 0.197e-10 * 0.197e-10;
    
    return xs_recE;

}




