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
    double G_f = 1.1663787e-11;// MeV^{-2},Fermi coupling constant
    int Z = 54;
    double sin2theta = 0.23867;
    double N = 131.293;
    
    double xsection_neuE = G_f*G_f * ( Z*(4.0*sin2theta-1.0)+N )*( Z*(4.0*sin2theta-1.0)+N ) * neu_energy * neu_energy /8.0/M_PI;

    return xsection_neuE;
}
