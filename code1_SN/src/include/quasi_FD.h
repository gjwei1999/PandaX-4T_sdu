/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#include "TMath.h"


double fitf(double *x,double *par) {
    
    double fitval = par[1] * x[0] * x[0] / (TMath::Exp(x[0]/par[0]) + 1);
    
    return fitval;
}
