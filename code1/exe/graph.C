#include <iostream>
#include <fstream>
#include <cmath>

#include "TROOT.h"
#include "TStyle.h"
//#include "TSystem.h"
#include "TString.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TF1.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TLegend.h"


int main(const int argc, const char * argv[]){
    
    if (argc < 2) {
        
        std::cout << "./plotter <opt> " << std::endl;
        return 1;
        
    }
    
    gStyle->SetPalette(1);
    
    const int opt = atoi(argv[1]);
    
    TString loadpath = "/Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code1/build/";
    TString savepath = "/Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code1/plots/";
    
    //energy spectrum
    if(opt == 1){
        
        TFile *fs = new TFile(loadpath + "energy_spec.root", "r");
        TH1D * h0 = (TH1D *) fs->Get("1301e");
        
        
        TGraph * g0 = new TGraph(h0);
        
        TCanvas * c0 = new TCanvas("c0", "", 800, 600);
        g0->Draw("AC*");
        c0->Print(savepath + "test.pdf","pdf");//
    }
    
    if(opt == 2){
        
        TFile *fs = new TFile(loadpath + "time_spec.root", "r");
        TH2D * h20 = (TH2D *) fs->Get("1301T-E-e");
        
        
        TGraph2D * g20 = new TGraph2D(h20);
        
        TCanvas * c0 = new TCanvas("c0", "", 800, 600);
        g20->Draw("surf1");
        c0->Print(savepath + "test.pdf","pdf");//
        
        
    }
    
    if(opt == 3){
        
        TFile *fs = new TFile(loadpath + "recE_spec.root", "r");
        TH1D * h0 = (TH1D *) fs->Get("1301electron_flux");
        
        
        TGraph * g0 = new TGraph(h0);
        
        TCanvas * c0 = new TCanvas("c0", "", 800, 600);
        g0->Draw("AC*");
        c0->Print(savepath + "test.pdf","pdf");//
        
        
    }

}
