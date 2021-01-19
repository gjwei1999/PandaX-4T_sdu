/*****************************/
/*                                                      */
/*       Created by Jiawei Guo          */
/*        Shandong University            */
/*                                                      */
/*****************************/

#include <iostream>
#include <fstream>
#include <cmath>

#include "TROOT.h"
#include "TStyle.h"
//#include "TSystem.h"
#include "TString.h"
#include "TFile.h"
//#include "TTree.h"
#include "TF1.h"
#include "Math/Functor.h"
#include "Math/WrappedTF1.h"
#include "Math/GSLIntegrator.h"
#include "Math/Interpolator.h"
#include "Math/WrappedParamFunction.h"
#include "Math/Integrator.h"
#include "Math/IntegratorMultiDim.h"
#include "Math/AllIntegrationTypes.h"
#include "Math/SpecFuncMathCore.h"
#include "TCanvas.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TLegend.h"
#include "TMath.h"

Double_t fitf(Double_t *x, Double_t *par) {
    
    Double_t fitval = par[0] / (TMath::Exp(x[0]/par[1]) + 1) ;
    
    return fitval;
}

int main(){

    gStyle->SetPalette(53);

    TString loadpath = "/Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code1_SN/build/";
        
    TFile *fs = new TFile(loadpath + "flux_neuE.root", "r");
    TH1D * h0 = (TH1D *) fs->Get("1301electron");

    TF1 *func = new TF1("fit", fitf, 0.0, 250.0, 2);
    
    func->SetParameters(1e4, 2);
    h0->Scale(1/1e6);
    
    h0->Fit("fit");
    
    TCanvas * c0 = new TCanvas("c0", "", 800, 600);
    h0->Draw();
    

return 1;
}
