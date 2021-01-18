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
    
    //flux vs time
    if(opt == 1){
        
        TFile *fs = new TFile(loadpath + "flux.root", "r");
        
        TH1D * h1301e = (TH1D *) fs->Get("1301inter-elec");
        TH1D * h1301antie = (TH1D *) fs->Get("1301inter-anti-elec");
        TH1D * h1301x = (TH1D *) fs->Get("1301inter-x-type");
        TH1D * h1302e = (TH1D *) fs->Get("1302inter-elec");
        TH1D * h1302antie = (TH1D *) fs->Get("1302inter-anti-elec");
        TH1D * h1302x = (TH1D *) fs->Get("1302inter-x-type");
        TH1D * h1303e = (TH1D *) fs->Get("1303inter-elec");
        TH1D * h1303antie = (TH1D *) fs->Get("1303inter-anti-elec");
        TH1D * h1303x = (TH1D *) fs->Get("1303inter-x-type");
        
        TH1D * h2001e = (TH1D *) fs->Get("2001inter-elec");
        TH1D * h2001antie = (TH1D *) fs->Get("2001inter-anti-elec");
        TH1D * h2001x = (TH1D *) fs->Get("2001inter-x-type");
        TH1D * h2002e = (TH1D *) fs->Get("2002inter-elec");
        TH1D * h2002antie = (TH1D *) fs->Get("2002inter-anti-elec");
        TH1D * h2002x = (TH1D *) fs->Get("2002inter-x-type");
        TH1D * h2003e = (TH1D *) fs->Get("2003inter-elec");
        TH1D * h2003antie = (TH1D *) fs->Get("2003inter-anti-elec");
        TH1D * h2003x = (TH1D *) fs->Get("2003inter-x-type");
        
        TH1D * h3001e = (TH1D *) fs->Get("3001inter-elec");
        TH1D * h3001antie = (TH1D *) fs->Get("3001inter-anti-elec");
        TH1D * h3001x = (TH1D *) fs->Get("3001inter-x-type");
        TH1D * h3002e = (TH1D *) fs->Get("3002inter-elec");
        TH1D * h3002antie = (TH1D *) fs->Get("3002inter-anti-elec");
        TH1D * h3002x = (TH1D *) fs->Get("3002inter-x-type");
        TH1D * h3003e = (TH1D *) fs->Get("3003inter-elec");
        TH1D * h3003antie = (TH1D *) fs->Get("3003inter-anti-elec");
        TH1D * h3003x = (TH1D *) fs->Get("3003inter-x-type");
        
        TH1D * h5001e = (TH1D *) fs->Get("5001inter-elec");
        TH1D * h5001antie = (TH1D *) fs->Get("5001inter-anti-elec");
        TH1D * h5001x = (TH1D *) fs->Get("5001inter-x-type");
        TH1D * h5002e = (TH1D *) fs->Get("5002inter-elec");
        TH1D * h5002antie = (TH1D *) fs->Get("5002inter-anti-elec");
        TH1D * h5002x = (TH1D *) fs->Get("5002inter-x-type");
        TH1D * h5003e = (TH1D *) fs->Get("5003inter-elec");
        TH1D * h5003antie = (TH1D *) fs->Get("5003inter-anti-elec");
        TH1D * h5003x = (TH1D *) fs->Get("5003inter-x-type");
        
        h1301e->SetLineColor(3); h1301antie->SetLineColor(4); h1301x->SetLineColor(2);
        h1302e->SetLineColor(3); h1302antie->SetLineColor(4); h1302x->SetLineColor(2);
        h1303e->SetLineColor(3); h1303antie->SetLineColor(4); h1303x->SetLineColor(2);
        h3001e->SetLineColor(3); h3001antie->SetLineColor(4); h3001x->SetLineColor(2);
        h3002e->SetLineColor(3); h3002antie->SetLineColor(4); h3002x->SetLineColor(2);
        h3003e->SetLineColor(3); h3003antie->SetLineColor(4); h3003x->SetLineColor(2);
        h2001e->SetLineColor(3); h2001antie->SetLineColor(4); h2001x->SetLineColor(2);
        h2002e->SetLineColor(3); h2002antie->SetLineColor(4); h2002x->SetLineColor(2);
        h2003e->SetLineColor(3); h2003antie->SetLineColor(4); h2003x->SetLineColor(2);
        h5001e->SetLineColor(3); h5001antie->SetLineColor(4); h5001x->SetLineColor(2);
        h5002e->SetLineColor(3); h5002antie->SetLineColor(4); h5002x->SetLineColor(2);
        h5003e->SetLineColor(3); h5003antie->SetLineColor(4); h5003x->SetLineColor(2);
        
        TLegend * leg = new TLegend(0.6, 0.7, 0.9, 0.9);
        leg->AddEntry(h1301e, "#nu_{e}", "l");
        leg->AddEntry(h1301antie, "#bar{#nu_{e}}", "l");
        leg->AddEntry(h1301x, "#nu_{x}", "l");
        
        
        TCanvas * c0 = new TCanvas("c0", "", 800, 600);
        h1301e->GetXaxis()->SetTitle("Time (s)");
        h1301e->GetYaxis()->SetTitle("Flux  (s^{-1}cm^{-2}) ");
        h1301e->SetTitle("13M_{#odot} , Z=0.02, t_{revive}=100ms");
        h1301e->SetMaximum(3.6e12);
        h1301e->DrawClone("same");
        h1301antie->DrawClone("same");
        h1301x->DrawClone("same");
        leg->DrawClone("same");
        c0->Print(savepath + "flux.pdf(","pdf");//
        TCanvas * c1 = new TCanvas("c1", "", 800, 600);
        h1302e->GetXaxis()->SetTitle("Time (s)");
        h1302e->GetYaxis()->SetTitle("Flux  (s^{-1}cm^{-2}) ");
        h1302e->SetTitle("13M_{#odot} , Z=0.02, t_{revive}=200ms");
        h1302e->SetMaximum(3.6e12);
        h1302e->DrawClone("same");
        h1302antie->DrawClone("same");
        h1302x->DrawClone("same");
        leg->DrawClone("same");
        c1->Print(savepath + "flux.pdf","pdf");//
        TCanvas * c2 = new TCanvas("c2", "", 800, 600);
        h1303e->GetXaxis()->SetTitle("Time (s)");
        h1303e->GetYaxis()->SetTitle("Flux  (s^{-1}cm^{-2}) ");
        h1303e->SetTitle("13M_{#odot} , Z=0.02, t_{revive}=300ms");
        h1303e->SetMaximum(3.6e12);
        h1303e->DrawClone("same");
        h1303antie->DrawClone("same");
        h1303x->DrawClone("same");
        leg->DrawClone("same");
        c2->Print(savepath + "flux.pdf","pdf");//
        TCanvas * c3 = new TCanvas("c3", "", 800, 600);
        h2001e->GetXaxis()->SetTitle("Time (s)");
        h2001e->GetYaxis()->SetTitle("Flux  (s^{-1}cm^{-2}) ");
        h2001e->SetTitle("20M_{#odot} , Z=0.02, t_{revive}=100ms");
        h2001e->SetMaximum(3.6e12);
        h2001e->DrawClone("same");
        h2001antie->DrawClone("same");
        h2001x->DrawClone("same");
        leg->DrawClone("same");
        c3->Print(savepath + "flux.pdf","pdf");//
        TCanvas * c4 = new TCanvas("c4", "", 800, 600);
        h2002e->GetXaxis()->SetTitle("Time (s)");
        h2002e->GetYaxis()->SetTitle("Flux  (s^{-1}cm^{-2}) ");
        h2002e->SetTitle("20M_{#odot} , Z=0.02, t_{revive}=200ms");
        h2002e->SetMaximum(3.6e12);
        h2002e->DrawClone("same");
        h2002antie->DrawClone("same");
        h2002x->DrawClone("same");
        leg->DrawClone("same");
        c4->Print(savepath + "flux.pdf","pdf");//
        TCanvas * c5 = new TCanvas("c5", "", 800, 600);
        h2003e->GetXaxis()->SetTitle("Time (s)");
        h2003e->GetYaxis()->SetTitle("Flux  (s^{-1}cm^{-2}) ");
        h2003e->SetTitle("20M_{#odot} , Z=0.02, t_{revive}=300ms");
        h2003e->SetMaximum(3.6e12);
        h2003e->DrawClone("same");
        h2003antie->DrawClone("same");
        h2003x->DrawClone("same");
        leg->DrawClone("same");
        c5->Print(savepath + "flux.pdf","pdf");//
        TCanvas * c6 = new TCanvas("c6", "", 800, 600);
        h3001e->GetXaxis()->SetTitle("Time (s)");
        h3001e->GetYaxis()->SetTitle("Flux  (s^{-1}cm^{-2}) ");
        h3001e->SetTitle("30M_{#odot} , Z=0.02, t_{revive}=100ms");
        h3001e->SetMaximum(3.6e12);
        h3001e->DrawClone("same");
        h3001antie->DrawClone("same");
        h3001x->DrawClone("same");
        leg->DrawClone("same");
        c6->Print(savepath + "flux.pdf","pdf");//
        TCanvas * c7 = new TCanvas("c7", "", 800, 600);
        h3002e->GetXaxis()->SetTitle("Time (s)");
        h3002e->GetYaxis()->SetTitle("Flux  (s^{-1}cm^{-2}) ");
        h3002e->SetTitle("30M_{#odot} , Z=0.02, t_{revive}=200ms");
        h3002e->SetMaximum(3.6e12);
        h3002e->DrawClone("same");
        h3002antie->DrawClone("same");
        h3002x->DrawClone("same");
        leg->DrawClone("same");
        c7->Print(savepath + "flux.pdf","pdf");//
        TCanvas * c8 = new TCanvas("c8", "", 800, 600);
        h3003e->GetXaxis()->SetTitle("Time (s)");
        h3003e->GetYaxis()->SetTitle("Flux  (s^{-1}cm^{-2}) ");
        h3003e->SetTitle("30M_{#odot} , Z=0.02, t_{revive}=300ms");
        h3003e->SetMaximum(3.6e12);
        h3003e->DrawClone("same");
        h3003antie->DrawClone("same");
        h3003x->DrawClone("same");
        leg->DrawClone("same");
        c8->Print(savepath + "flux.pdf","pdf");//
        TCanvas * c9 = new TCanvas("c9", "", 800, 600);
        h5001e->GetXaxis()->SetTitle("Time (s)");
        h5001e->GetYaxis()->SetTitle("Flux  (s^{-1}cm^{-2}) ");
        h5001e->SetTitle("50M_{#odot} , Z=0.02, t_{revive}=100ms");
        h5001e->SetMaximum(3.6e12);
        h5001e->DrawClone("same");
        h5001antie->DrawClone("same");
        h5001x->DrawClone("same");
        leg->DrawClone("same");
        c9->Print(savepath + "flux.pdf","pdf");//
        h5002e->GetXaxis()->SetTitle("Time (s)");
        h5002e->GetYaxis()->SetTitle("Flux  (s^{-1}cm^{-2}) ");
        TCanvas * c10 = new TCanvas("c10", "", 800, 600);
        h5002e->SetTitle("50M_{#odot} , Z=0.02, t_{revive}=200ms");
        h5002e->SetMaximum(3.6e12);
        h5002e->DrawClone("same");
        h5002antie->DrawClone("same");
        h5002x->DrawClone("same");
        leg->DrawClone("same");
        c10->Print(savepath + "flux.pdf","pdf");//
        TCanvas * c11 = new TCanvas("c11", "", 800, 600);
        h5003e->GetXaxis()->SetTitle("Time (s)");
        h5003e->GetYaxis()->SetTitle("Flux  (s^{-1}cm^{-2}) ");
        h5003e->SetTitle("50M_{#odot} , Z=0.02, t_{revive}=300ms");
        h5003e->SetMaximum(3.6e12);
        h5003e->DrawClone("same");
        h5003antie->DrawClone("same");
        h5003x->DrawClone("same");
        leg->DrawClone("same");
        c11->Print(savepath + "flux.pdf)","pdf");//
    }
    
    
    //events rate vs time
    if(opt == 2){
        
        TFile *fs = new TFile(loadpath + "time_spec.root", "r");
        
        TH1D * h1301e = (TH1D *) fs->Get("1301e");
        TH1D * h1301antie = (TH1D *) fs->Get("1301antie");
        TH1D * h1301x = (TH1D *) fs->Get("1301x");
        TH1D * h1302e = (TH1D *) fs->Get("1302e");
        TH1D * h1302antie = (TH1D *) fs->Get("1302antie");
        TH1D * h1302x = (TH1D *) fs->Get("1302x");
        TH1D * h1303e = (TH1D *) fs->Get("1303e");
        TH1D * h1303antie = (TH1D *) fs->Get("1303antie");
        TH1D * h1303x = (TH1D *) fs->Get("1303x");
        
        TH1D * h2001e = (TH1D *) fs->Get("2001e");
        TH1D * h2001antie = (TH1D *) fs->Get("2001antie");
        TH1D * h2001x = (TH1D *) fs->Get("2001x");
        TH1D * h2002e = (TH1D *) fs->Get("2002e");
        TH1D * h2002antie = (TH1D *) fs->Get("2002antie");
        TH1D * h2002x = (TH1D *) fs->Get("2002x");
        TH1D * h2003e = (TH1D *) fs->Get("2003e");
        TH1D * h2003antie = (TH1D *) fs->Get("2003antie");
        TH1D * h2003x = (TH1D *) fs->Get("2003x");
        
        TH1D * h3001e = (TH1D *) fs->Get("3001e");
        TH1D * h3001antie = (TH1D *) fs->Get("3001antie");
        TH1D * h3001x = (TH1D *) fs->Get("3001x");
        TH1D * h3002e = (TH1D *) fs->Get("3002e");
        TH1D * h3002antie = (TH1D *) fs->Get("3002antie");
        TH1D * h3002x = (TH1D *) fs->Get("3002x");
        TH1D * h3003e = (TH1D *) fs->Get("3003e");
        TH1D * h3003antie = (TH1D *) fs->Get("3003antie");
        TH1D * h3003x = (TH1D *) fs->Get("3003x");
        
        TH1D * h5001e = (TH1D *) fs->Get("5001e");
        TH1D * h5001antie = (TH1D *) fs->Get("5001antie");
        TH1D * h5001x = (TH1D *) fs->Get("5001x");
        TH1D * h5002e = (TH1D *) fs->Get("5002e");
        TH1D * h5002antie = (TH1D *) fs->Get("5002antie");
        TH1D * h5002x = (TH1D *) fs->Get("5002x");
        TH1D * h5003e = (TH1D *) fs->Get("5003e");
        TH1D * h5003antie = (TH1D *) fs->Get("5003antie");
        TH1D * h5003x = (TH1D *) fs->Get("5003x");
        
        h1301e->SetLineColor(3); h1301antie->SetLineColor(4); h1301x->SetLineColor(2);
        h1302e->SetLineColor(3); h1302antie->SetLineColor(4); h1302x->SetLineColor(2);
        h1303e->SetLineColor(3); h1303antie->SetLineColor(4); h1303x->SetLineColor(2);
        h3001e->SetLineColor(3); h3001antie->SetLineColor(4); h3001x->SetLineColor(2);
        h3002e->SetLineColor(3); h3002antie->SetLineColor(4); h3002x->SetLineColor(2);
        h3003e->SetLineColor(3); h3003antie->SetLineColor(4); h3003x->SetLineColor(2);
        h2001e->SetLineColor(3); h2001antie->SetLineColor(4); h2001x->SetLineColor(2);
        h2002e->SetLineColor(3); h2002antie->SetLineColor(4); h2002x->SetLineColor(2);
        h2003e->SetLineColor(3); h2003antie->SetLineColor(4); h2003x->SetLineColor(2);
        h5001e->SetLineColor(3); h5001antie->SetLineColor(4); h5001x->SetLineColor(2);
        h5002e->SetLineColor(3); h5002antie->SetLineColor(4); h5002x->SetLineColor(2);
        h5003e->SetLineColor(3); h5003antie->SetLineColor(4); h5003x->SetLineColor(2);
        
        TLegend * leg = new TLegend(0.6, 0.7, 0.9, 0.9);
        leg->AddEntry(h1301e, "#nu_{e}", "l");
        leg->AddEntry(h1301antie, "#bar{#nu_{e}}", "l");
        leg->AddEntry(h1301x, "#nu_{x}", "l");
        
        
        TCanvas * c0 = new TCanvas("c0", "", 800, 600);
        h1301e->GetXaxis()->SetTitle("Time (s)");
        h1301e->GetYaxis()->SetTitle("Event rate(ton^{-1}s^{-1}) ");
        h1301e->SetTitle("13M_{#odot} , Z=0.02, t_{revive}=100ms");
        h1301e->SetMaximum(165.0);
        h1301e->DrawClone("same");
        h1301antie->DrawClone("same");
        h1301x->DrawClone("same");
        leg->DrawClone("same");
        c0->Print(savepath + "eventrate_time.pdf(","pdf");//
        TCanvas * c1 = new TCanvas("c1", "", 800, 600);
        h1302e->GetXaxis()->SetTitle("Time (s)");
        h1302e->GetYaxis()->SetTitle("Event rate(ton^{-1}s^{-1}) ");
        h1302e->SetTitle("13M_{#odot} , Z=0.02, t_{revive}=200ms");
        h1302e->SetMaximum(165.0);
        h1302e->DrawClone("same");
        h1302antie->DrawClone("same");
        h1302x->DrawClone("same");
        leg->DrawClone("same");
        c1->Print(savepath + "eventrate_time.pdf","pdf");//
        TCanvas * c2 = new TCanvas("c2", "", 800, 600);
        h1303e->GetXaxis()->SetTitle("Time (s)");
        h1303e->GetYaxis()->SetTitle("Event rate(ton^{-1}s^{-1}) ");
        h1303e->SetTitle("13M_{#odot} , Z=0.02, t_{revive}=300ms");
        h1303e->SetMaximum(165.0);
        h1303e->DrawClone("same");
        h1303antie->DrawClone("same");
        h1303x->DrawClone("same");
        leg->DrawClone("same");
        c2->Print(savepath + "eventrate_time.pdf","pdf");//
        TCanvas * c3 = new TCanvas("c3", "", 800, 600);
        h2001e->GetXaxis()->SetTitle("Time (s)");
        h2001e->GetYaxis()->SetTitle("Event rate(ton^{-1}s^{-1}) ");
        h2001e->SetTitle("20M_{#odot} , Z=0.02, t_{revive}=100ms");
        h2001e->SetMaximum(165.0);
        h2001e->DrawClone("same");
        h2001antie->DrawClone("same");
        h2001x->DrawClone("same");
        leg->DrawClone("same");
        c3->Print(savepath + "eventrate_time.pdf","pdf");//
        TCanvas * c4 = new TCanvas("c4", "", 800, 600);
        h2002e->GetXaxis()->SetTitle("Time (s)");
        h2002e->GetYaxis()->SetTitle("Event rate(ton^{-1}s^{-1}) ");
        h2002e->SetTitle("20M_{#odot} , Z=0.02, t_{revive}=200ms");
        h2002e->SetMaximum(165.0);
        h2002e->DrawClone("same");
        h2002antie->DrawClone("same");
        h2002x->DrawClone("same");
        leg->DrawClone("same");
        c4->Print(savepath + "eventrate_time.pdf","pdf");//
        TCanvas * c5 = new TCanvas("c5", "", 800, 600);
        h2003e->GetXaxis()->SetTitle("Time (s)");
        h2003e->GetYaxis()->SetTitle("Event rate(ton^{-1}s^{-1}) ");
        h2003e->SetTitle("20M_{#odot} , Z=0.02, t_{revive}=300ms");
        h2003e->SetMaximum(165.0);
        h2003e->DrawClone("same");
        h2003antie->DrawClone("same");
        h2003x->DrawClone("same");
        leg->DrawClone("same");
        c5->Print(savepath + "eventrate_time.pdf","pdf");//
        TCanvas * c6 = new TCanvas("c6", "", 800, 600);
        h3001e->GetXaxis()->SetTitle("Time (s)");
        h3001e->GetYaxis()->SetTitle("Event rate(ton^{-1}s^{-1}) ");
        h3001e->SetTitle("30M_{#odot} , Z=0.02, t_{revive}=100ms");
        h3001e->SetMaximum(165.0);
        h3001e->DrawClone("same");
        h3001antie->DrawClone("same");
        h3001x->DrawClone("same");
        leg->DrawClone("same");
        c6->Print(savepath + "eventrate_time.pdf","pdf");//
        TCanvas * c7 = new TCanvas("c7", "", 800, 600);
        h3002e->GetXaxis()->SetTitle("Time (s)");
        h3002e->GetYaxis()->SetTitle("Event rate(ton^{-1}s^{-1}) ");
        h3002e->SetTitle("30M_{#odot} , Z=0.02, t_{revive}=200ms");
        h3002e->SetMaximum(165.0);
        h3002e->DrawClone("same");
        h3002antie->DrawClone("same");
        h3002x->DrawClone("same");
        leg->DrawClone("same");
        c7->Print(savepath + "eventrate_time.pdf","pdf");//
        TCanvas * c8 = new TCanvas("c8", "", 800, 600);
        h3003e->GetXaxis()->SetTitle("Time (s)");
        h3003e->GetYaxis()->SetTitle("Event rate(ton^{-1}s^{-1}) ");
        h3003e->SetTitle("30M_{#odot} , Z=0.02, t_{revive}=300ms");
        h3003e->SetMaximum(165.0);
        h3003e->DrawClone("same");
        h3003antie->DrawClone("same");
        h3003x->DrawClone("same");
        leg->DrawClone("same");
        c8->Print(savepath + "eventrate_time.pdf","pdf");//
        TCanvas * c9 = new TCanvas("c9", "", 800, 600);
        h5001e->GetXaxis()->SetTitle("Time (s)");
        h5001e->GetYaxis()->SetTitle("Event rate(ton^{-1}s^{-1}) ");
        h5001e->SetTitle("50M_{#odot} , Z=0.02, t_{revive}=100ms");
        h5001e->SetMaximum(165.0);
        h5001e->DrawClone("same");
        h5001antie->DrawClone("same");
        h5001x->DrawClone("same");
        leg->DrawClone("same");
        c9->Print(savepath + "eventrate_time.pdf","pdf");//
        h5002e->GetXaxis()->SetTitle("Time (s)");
        h5002e->GetYaxis()->SetTitle("Event rate(ton^{-1}s^{-1}) ");
        TCanvas * c10 = new TCanvas("c10", "", 800, 600);
        h5002e->SetTitle("50M_{#odot} , Z=0.02, t_{revive}=200ms");
        h5002e->SetMaximum(165.0);
        h5002e->DrawClone("same");
        h5002antie->DrawClone("same");
        h5002x->DrawClone("same");
        leg->DrawClone("same");
        c10->Print(savepath + "eventrate_time.pdf","pdf");//
        TCanvas * c11 = new TCanvas("c11", "", 800, 600);
        h5003e->GetXaxis()->SetTitle("Time (s)");
        h5003e->GetYaxis()->SetTitle("Event rate(ton^{-1}s^{-1}) ");
        h5003e->SetTitle("50M_{#odot} , Z=0.02, t_{revive}=300ms");
        h5003e->SetMaximum(165.0);
        h5003e->DrawClone("same");
        h5003antie->DrawClone("same");
        h5003x->DrawClone("same");
        leg->DrawClone("same");
        c11->Print(savepath + "eventrate_time.pdf)","pdf");//
        
    }
    
    //flux_neuEnergy with interpolation
    if(opt == 3){
        
        TFile *fs = new TFile(loadpath + "recE_spec.root", "r");
        
        TH1D * h1301e = (TH1D *) fs->Get("1301electron_flux");
        TH1D * h1301antie = (TH1D *) fs->Get("1301anti-electron_flux");
        TH1D * h1301x = (TH1D *) fs->Get("1301x_flux");
        TH1D * h1302e = (TH1D *) fs->Get("1302electron_flux");
        TH1D * h1302antie = (TH1D *) fs->Get("1302anti-electron_flux");
        TH1D * h1302x = (TH1D *) fs->Get("1302x_flux");
        TH1D * h1303e = (TH1D *) fs->Get("1303electron_flux");
        TH1D * h1303antie = (TH1D *) fs->Get("1303anti-electron_flux");
        TH1D * h1303x = (TH1D *) fs->Get("1303x_flux");
        
        TH1D * h2001e = (TH1D *) fs->Get("2001electron_flux");
        TH1D * h2001antie = (TH1D *) fs->Get("2001anti-electron_flux");
        TH1D * h2001x = (TH1D *) fs->Get("2001x_flux");
        TH1D * h2002e = (TH1D *) fs->Get("2002electron_flux");
        TH1D * h2002antie = (TH1D *) fs->Get("2002anti-electron_flux");
        TH1D * h2002x = (TH1D *) fs->Get("2002x_flux");
        TH1D * h2003e = (TH1D *) fs->Get("2003electron_flux");
        TH1D * h2003antie = (TH1D *) fs->Get("2003anti-electron_flux");
        TH1D * h2003x = (TH1D *) fs->Get("2003x_flux");
        
        TH1D * h3001e = (TH1D *) fs->Get("3001electron_flux");
        TH1D * h3001antie = (TH1D *) fs->Get("3001anti-electron_flux");
        TH1D * h3001x = (TH1D *) fs->Get("3001x_flux");
        TH1D * h3002e = (TH1D *) fs->Get("3002electron_flux");
        TH1D * h3002antie = (TH1D *) fs->Get("3002anti-electron_flux");
        TH1D * h3002x = (TH1D *) fs->Get("3002x_flux");
        TH1D * h3003e = (TH1D *) fs->Get("3003electron_flux");
        TH1D * h3003antie = (TH1D *) fs->Get("3003anti-electron_flux");
        TH1D * h3003x = (TH1D *) fs->Get("3003x_flux");
        
        TH1D * h5001e = (TH1D *) fs->Get("5001electron_flux");
        TH1D * h5001antie = (TH1D *) fs->Get("5001anti-electron_flux");
        TH1D * h5001x = (TH1D *) fs->Get("5001x_flux");
        TH1D * h5002e = (TH1D *) fs->Get("5002electron_flux");
        TH1D * h5002antie = (TH1D *) fs->Get("5002anti-electron_flux");
        TH1D * h5002x = (TH1D *) fs->Get("5002x_flux");
        TH1D * h5003e = (TH1D *) fs->Get("5003electron_flux");
        TH1D * h5003antie = (TH1D *) fs->Get("5003anti-electron_flux");
        TH1D * h5003x = (TH1D *) fs->Get("5003x_flux");
        
        h1301e->SetLineColor(3); h1301antie->SetLineColor(4); h1301x->SetLineColor(2);
        h1302e->SetLineColor(3); h1302antie->SetLineColor(4); h1302x->SetLineColor(2);
        h1303e->SetLineColor(3); h1303antie->SetLineColor(4); h1303x->SetLineColor(2);
        h3001e->SetLineColor(3); h3001antie->SetLineColor(4); h3001x->SetLineColor(2);
        h3002e->SetLineColor(3); h3002antie->SetLineColor(4); h3002x->SetLineColor(2);
        h3003e->SetLineColor(3); h3003antie->SetLineColor(4); h3003x->SetLineColor(2);
        h2001e->SetLineColor(3); h2001antie->SetLineColor(4); h2001x->SetLineColor(2);
        h2002e->SetLineColor(3); h2002antie->SetLineColor(4); h2002x->SetLineColor(2);
        h2003e->SetLineColor(3); h2003antie->SetLineColor(4); h2003x->SetLineColor(2);
        h5001e->SetLineColor(3); h5001antie->SetLineColor(4); h5001x->SetLineColor(2);
        h5002e->SetLineColor(3); h5002antie->SetLineColor(4); h5002x->SetLineColor(2);
        h5003e->SetLineColor(3); h5003antie->SetLineColor(4); h5003x->SetLineColor(2);
        
        TLegend * leg = new TLegend(0.7, 0.7, 0.9, 0.9);
        leg->AddEntry(h1301e, "#nu_{e}", "l");
        leg->AddEntry(h1301antie, "#bar{#nu_{e}}", "l");
        leg->AddEntry(h1301x, "#nu_{x}", "l");
        
        //gPad->SetLogy();
        //gPad->SetLogx();
        
        TCanvas * c0 = new TCanvas("c0", "", 800, 600);
        c0->SetLogy();
        c0->SetLogx();
        h1301e->GetXaxis()->SetTitle("E_{#nu} (MeV)");
        h1301e->GetYaxis()->SetTitle("dN/dE_{#nu}  (cm^{-2}s^{-1}MeV^{-1}) ");
        h1301e->SetTitle("13M_{#odot} , Z=0.02, t_{revive}=100ms");
        h1301e->SetMaximum(1.0e11);
        h1301e->DrawClone("same");
        h1301antie->DrawClone("same");
        h1301x->DrawClone("same");
        leg->DrawClone("same");
        c0->Print(savepath + "flux_neuE.pdf(","pdf");//
        TCanvas * c1 = new TCanvas("c1", "", 800, 600);
        c1->SetLogy();
        c1->SetLogx();
        h1302e->GetXaxis()->SetTitle("E_{#nu} (MeV)");
        h1302e->GetYaxis()->SetTitle("dN/dE_{#nu}  (cm^{-2}s^{-1}MeV^{-1}) ");
        h1302e->SetTitle("13M_{#odot} , Z=0.02, t_{revive}=200ms");
        h1302e->SetMaximum(1.0e11);
        h1302e->DrawClone("same");
        h1302antie->DrawClone("same");
        h1302x->DrawClone("same");
        leg->DrawClone("same");
        c1->Print(savepath + "flux_neuE.pdf","pdf");//
        TCanvas * c2 = new TCanvas("c2", "", 800, 600);
        c2->SetLogy();
        c2->SetLogx();
        h1303e->GetXaxis()->SetTitle("E_{#nu} (MeV)");
        h1303e->GetYaxis()->SetTitle("dN/dE_{#nu}  (cm^{-2}s^{-1}MeV^{-1})");
        h1303e->SetTitle("13M_{#odot} , Z=0.02, t_{revive}=300ms");
        h1303e->SetMaximum(1.0e11);
        h1303e->DrawClone("same");
        h1303antie->DrawClone("same");
        h1303x->DrawClone("same");
        leg->DrawClone("same");
        c2->Print(savepath + "flux_neuE.pdf","pdf");//
        TCanvas * c3 = new TCanvas("c3", "", 800, 600);
        c3->SetLogy();
        c3->SetLogx();
        h2001e->GetXaxis()->SetTitle("E_{#nu} (MeV)");
        h2001e->GetYaxis()->SetTitle("dN/dE_{#nu}  (cm^{-2}s^{-1}MeV^{-1}) ");
        h2001e->SetTitle("20M_{#odot} , Z=0.02, t_{revive}=100ms");
        h2001e->SetMaximum(1.0e11);
        h2001e->DrawClone("same");
        h2001antie->DrawClone("same");
        h2001x->DrawClone("same");
        leg->DrawClone("same");
        c3->Print(savepath + "flux_neuE.pdf","pdf");//
        TCanvas * c4 = new TCanvas("c4", "", 800, 600);
        c4->SetLogy();
        c4->SetLogx();
        h2002e->GetXaxis()->SetTitle("E_{#nu} (MeV)");
        h2002e->GetYaxis()->SetTitle("dN/dE_{#nu}  (cm^{-2}s^{-1}MeV^{-1}) ");
        h2002e->SetTitle("20M_{#odot} , Z=0.02, t_{revive}=200ms");
        h2002e->SetMaximum(1.0e11);
        h2002e->DrawClone("same");
        h2002antie->DrawClone("same");
        h2002x->DrawClone("same");
        leg->DrawClone("same");
        c4->Print(savepath + "flux_neuE.pdf","pdf");//
        TCanvas * c5 = new TCanvas("c5", "", 800, 600);
        c5->SetLogy();
        c5->SetLogx();
        h2003e->GetXaxis()->SetTitle("E_{#nu} (MeV)");
        h2003e->GetYaxis()->SetTitle("dN/dE_{#nu}  (cm^{-2}s^{-1}MeV^{-1}) ");
        h2003e->SetTitle("20M_{#odot} , Z=0.02, t_{revive}=300ms");
        h2003e->SetMaximum(1.0e11);
        h2003e->DrawClone("same");
        h2003antie->DrawClone("same");
        h2003x->DrawClone("same");
        leg->DrawClone("same");
        c5->Print(savepath + "flux_neuE.pdf","pdf");//
        TCanvas * c6 = new TCanvas("c6", "", 800, 600);
        c6->SetLogy();
        c6->SetLogx();
        h3001e->GetXaxis()->SetTitle("E_{#nu} (MeV)");
        h3001e->GetYaxis()->SetTitle("dN/dE_{#nu}  (cm^{-2}s^{-1}MeV^{-1}) ");
        h3001e->SetTitle("30M_{#odot} , Z=0.02, t_{revive}=100ms");
        h3001e->SetMaximum(1.0e11);
        h3001e->DrawClone("same");
        h3001antie->DrawClone("same");
        h3001x->DrawClone("same");
        leg->DrawClone("same");
        c6->Print(savepath + "flux_neuE.pdf","pdf");//
        TCanvas * c7 = new TCanvas("c7", "", 800, 600);
        c7->SetLogy();
        c7->SetLogx();
        h3002e->GetXaxis()->SetTitle("E_{#nu} (MeV)");
        h3002e->GetYaxis()->SetTitle("dN/dE_{#nu}  (cm^{-2}s^{-1}MeV^{-1}) ");
        h3002e->SetTitle("30M_{#odot} , Z=0.02, t_{revive}=200ms");
        h3002e->SetMaximum(1.0e11);
        h3002e->DrawClone("same");
        h3002antie->DrawClone("same");
        h3002x->DrawClone("same");
        leg->DrawClone("same");
        c7->Print(savepath + "flux_neuE.pdf","pdf");//
        TCanvas * c8 = new TCanvas("c8", "", 800, 600);
        c8->SetLogy();
        c8->SetLogx();
        h3003e->GetXaxis()->SetTitle("E_{#nu} (MeV)");
        h3003e->GetYaxis()->SetTitle("dN/dE_{#nu}  (cm^{-2}s^{-1}MeV^{-1}) ");
        h3003e->SetTitle("30M_{#odot} , Z=0.02, t_{revive}=300ms");
        h3003e->SetMaximum(1.0e11);
        h3003e->DrawClone("same");
        h3003antie->DrawClone("same");
        h3003x->DrawClone("same");
        leg->DrawClone("same");
        c8->Print(savepath + "flux_neuE.pdf","pdf");//
        TCanvas * c9 = new TCanvas("c9", "", 800, 600);
        c9->SetLogy();
        c9->SetLogx();
        h5001e->GetXaxis()->SetTitle("E_{#nu} (MeV)");
        h5001e->GetYaxis()->SetTitle("dN/dE_{#nu}  (cm^{-2}s^{-1}MeV^{-1}) ");
        h5001e->SetTitle("50M_{#odot} , Z=0.02, t_{revive}=100ms");
        h5001e->SetMaximum(1.0e11);
        h5001e->DrawClone("same");
        h5001antie->DrawClone("same");
        h5001x->DrawClone("same");
        leg->DrawClone("same");
        c9->Print(savepath + "flux_neuE.pdf","pdf");//
        h5002e->GetXaxis()->SetTitle("E_{#nu} (MeV)");
        h5002e->GetYaxis()->SetTitle("dN/dE_{#nu}  (cm^{-2}s^{-1}MeV^{-1}) ");
        TCanvas * c10 = new TCanvas("c10", "", 800, 600);
        c10->SetLogy();
        c10->SetLogx();
        h5002e->SetTitle("50M_{#odot} , Z=0.02, t_{revive}=200ms");
        h5002e->SetMaximum(1.0e11);
        h5002e->DrawClone("same");
        h5002antie->DrawClone("same");
        h5002x->DrawClone("same");
        leg->DrawClone("same");
        c10->Print(savepath + "flux_neuE.pdf","pdf");//
        TCanvas * c11 = new TCanvas("c11", "", 800, 600);
        c11->SetLogy();
        c11->SetLogx();
        h5003e->GetXaxis()->SetTitle("E_{#nu} (MeV)");
        h5003e->GetYaxis()->SetTitle("dN/dE_{#nu}  (cm^{-2}s^{-1}MeV^{-1}) ");
        h5003e->SetTitle("50M_{#odot} , Z=0.02, t_{revive}=300ms");
        h5003e->SetMaximum(1.0e11);
        h5003e->DrawClone("same");
        h5003antie->DrawClone("same");
        h5003x->DrawClone("same");
        leg->DrawClone("same");
        c11->Print(savepath + "flux_neuE.pdf)","pdf");//
        
    }

    //event rate_recoilEnergy with interpolation
    if(opt == 4){
        
        TFile *fs = new TFile(loadpath + "recE_spec.root", "r");
        
        TH1D * h1301e = (TH1D *) fs->Get("1301electron_recoil");
        TH1D * h1301antie = (TH1D *) fs->Get("1301anti-electron_recoil");
        TH1D * h1301x = (TH1D *) fs->Get("1301x_recoil");
        TH1D * h1302e = (TH1D *) fs->Get("1302electron_recoil");
        TH1D * h1302antie = (TH1D *) fs->Get("1302anti-electron_recoil");
        TH1D * h1302x = (TH1D *) fs->Get("1302x_recoil");
        TH1D * h1303e = (TH1D *) fs->Get("1303electron_recoil");
        TH1D * h1303antie = (TH1D *) fs->Get("1303anti-electron_recoil");
        TH1D * h1303x = (TH1D *) fs->Get("1303x_recoil");
        
        TH1D * h2001e = (TH1D *) fs->Get("2001electron_recoil");
        TH1D * h2001antie = (TH1D *) fs->Get("2001anti-electron_recoil");
        TH1D * h2001x = (TH1D *) fs->Get("2001x_recoil");
        TH1D * h2002e = (TH1D *) fs->Get("2002electron_recoil");
        TH1D * h2002antie = (TH1D *) fs->Get("2002anti-electron_recoil");
        TH1D * h2002x = (TH1D *) fs->Get("2002x_recoil");
        TH1D * h2003e = (TH1D *) fs->Get("2003electron_recoil");
        TH1D * h2003antie = (TH1D *) fs->Get("2003anti-electron_recoil");
        TH1D * h2003x = (TH1D *) fs->Get("2003x_recoil");
        
        TH1D * h3001e = (TH1D *) fs->Get("3001electron_recoil");
        TH1D * h3001antie = (TH1D *) fs->Get("3001anti-electron_recoil");
        TH1D * h3001x = (TH1D *) fs->Get("3001x_recoil");
        TH1D * h3002e = (TH1D *) fs->Get("3002electron_recoil");
        TH1D * h3002antie = (TH1D *) fs->Get("3002anti-electron_recoil");
        TH1D * h3002x = (TH1D *) fs->Get("3002x_recoil");
        TH1D * h3003e = (TH1D *) fs->Get("3003electron_recoil");
        TH1D * h3003antie = (TH1D *) fs->Get("3003anti-electron_recoil");
        TH1D * h3003x = (TH1D *) fs->Get("3003x_recoil");
        
        TH1D * h5001e = (TH1D *) fs->Get("5001electron_recoil");
        TH1D * h5001antie = (TH1D *) fs->Get("5001anti-electron_recoil");
        TH1D * h5001x = (TH1D *) fs->Get("5001x_recoil");
        TH1D * h5002e = (TH1D *) fs->Get("5002electron_recoil");
        TH1D * h5002antie = (TH1D *) fs->Get("5002anti-electron_recoil");
        TH1D * h5002x = (TH1D *) fs->Get("5002x_recoil");
        TH1D * h5003e = (TH1D *) fs->Get("5003electron_recoil");
        TH1D * h5003antie = (TH1D *) fs->Get("5003anti-electron_recoil");
        TH1D * h5003x = (TH1D *) fs->Get("5003x_recoil");
        
        h1301e->SetLineColor(3); h1301antie->SetLineColor(4); h1301x->SetLineColor(2);
        h1302e->SetLineColor(3); h1302antie->SetLineColor(4); h1302x->SetLineColor(2);
        h1303e->SetLineColor(3); h1303antie->SetLineColor(4); h1303x->SetLineColor(2);
        h3001e->SetLineColor(3); h3001antie->SetLineColor(4); h3001x->SetLineColor(2);
        h3002e->SetLineColor(3); h3002antie->SetLineColor(4); h3002x->SetLineColor(2);
        h3003e->SetLineColor(3); h3003antie->SetLineColor(4); h3003x->SetLineColor(2);
        h2001e->SetLineColor(3); h2001antie->SetLineColor(4); h2001x->SetLineColor(2);
        h2002e->SetLineColor(3); h2002antie->SetLineColor(4); h2002x->SetLineColor(2);
        h2003e->SetLineColor(3); h2003antie->SetLineColor(4); h2003x->SetLineColor(2);
        h5001e->SetLineColor(3); h5001antie->SetLineColor(4); h5001x->SetLineColor(2);
        h5002e->SetLineColor(3); h5002antie->SetLineColor(4); h5002x->SetLineColor(2);
        h5003e->SetLineColor(3); h5003antie->SetLineColor(4); h5003x->SetLineColor(2);
        
        TLegend * leg = new TLegend(0.7, 0.7, 0.9, 0.9);
        leg->AddEntry(h1301e, "#nu_{e}", "l");
        leg->AddEntry(h1301antie, "#bar{#nu_{e}}", "l");
        leg->AddEntry(h1301x, "#nu_{x}", "l");
        
        //gPad->SetLogy();
        //gPad->SetLogx();
        
        TCanvas * c0 = new TCanvas("c0", "", 800, 600);
        c0->SetLogy();
        c0->SetLogx();
        h1301e->GetXaxis()->SetTitle("E_{r} (keV)");
        h1301e->GetYaxis()->SetTitle("Event rate (ton^{-1}s^{-1}MeV^{-1})");
        h1301e->SetTitle("13M_{#odot} , Z=0.02, t_{revive}=100ms");
        h1301e->SetMaximum(100.0);
        h1301e->DrawClone("Hist same");
        h1301antie->DrawClone("Hist same");
        h1301x->DrawClone("Hist same");
        leg->DrawClone("same");
        c0->Print(savepath + "rate_recoilE.pdf(","pdf");//
        TCanvas * c1 = new TCanvas("c1", "", 800, 600);
        c1->SetLogy();
        c1->SetLogx();
        h1302e->GetXaxis()->SetTitle("E_{r} (keV)");
        h1302e->GetYaxis()->SetTitle("Event rate (ton^{-1}s^{-1}MeV^{-1})");
        h1302e->SetTitle("13M_{#odot} , Z=0.02, t_{revive}=200ms");
        h1302e->SetMaximum(100.0);
        h1302e->DrawClone("Hist same");
        h1302antie->DrawClone("Hist same");
        h1302x->DrawClone("Hist same");
        leg->DrawClone("same");
        c1->Print(savepath + "rate_recoilE.pdf","pdf");//
        TCanvas * c2 = new TCanvas("c2", "", 800, 600);
        c2->SetLogy();
        c2->SetLogx();
        h1303e->GetXaxis()->SetTitle("E_{r} (keV)");
        h1303e->GetYaxis()->SetTitle("dN/dE_{#nu}  (cm^{-2}s^{-1}MeV^{-1})");
        h1303e->SetTitle("13M_{#odot} , Z=0.02, t_{revive}=300ms");
        h1303e->SetMaximum(100.0);
        h1303e->DrawClone("Hist same");
        h1303antie->DrawClone("Hist same");
        h1303x->DrawClone("Hist same");
        leg->DrawClone("same");
        c2->Print(savepath + "rate_recoilE.pdf","pdf");//
        TCanvas * c3 = new TCanvas("c3", "", 800, 600);
        c3->SetLogy();
        c3->SetLogx();
        h2001e->GetXaxis()->SetTitle("E_{r} (keV)");
        h2001e->GetYaxis()->SetTitle("Event rate (ton^{-1}s^{-1}MeV^{-1})");
        h2001e->SetTitle("20M_{#odot} , Z=0.02, t_{revive}=100ms");
        h2001e->SetMaximum(100.0);
        h2001e->DrawClone("Hist same");
        h2001antie->DrawClone("Hist same");
        h2001x->DrawClone("Hist same");
        leg->DrawClone("same");
        c3->Print(savepath + "rate_recoilE.pdf","pdf");//
        TCanvas * c4 = new TCanvas("c4", "", 800, 600);
        c4->SetLogy();
        c4->SetLogx();
        h2002e->GetXaxis()->SetTitle("E_{r} (keV)");
        h2002e->GetYaxis()->SetTitle("Event rate (ton^{-1}s^{-1}MeV^{-1})");
        h2002e->SetTitle("20M_{#odot} , Z=0.02, t_{revive}=200ms");
        h2002e->SetMaximum(100.0);
        h2002e->DrawClone("Hist same");
        h2002antie->DrawClone("Hist same");
        h2002x->DrawClone("Hist same");
        leg->DrawClone("same");
        c4->Print(savepath + "rate_recoilE.pdf","pdf");//
        TCanvas * c5 = new TCanvas("c5", "", 800, 600);
        c5->SetLogy();
        c5->SetLogx();
        h2003e->GetXaxis()->SetTitle("E_{r} (keV)");
        h2003e->GetYaxis()->SetTitle("Event rate (ton^{-1}s^{-1}MeV^{-1})");
        h2003e->SetTitle("20M_{#odot} , Z=0.02, t_{revive}=300ms");
        h2003e->SetMaximum(100.0);
        h2003e->DrawClone("Hist same");
        h2003antie->DrawClone("Hist same");
        h2003x->DrawClone("Hist same");
        leg->DrawClone("same");
        c5->Print(savepath + "rate_recoilE.pdf","pdf");//
        TCanvas * c6 = new TCanvas("c6", "", 800, 600);
        c6->SetLogy();
        c6->SetLogx();
        h3001e->GetXaxis()->SetTitle("E_{r} (keV)");
        h3001e->GetYaxis()->SetTitle("Event rate (ton^{-1}s^{-1}MeV^{-1})");
        h3001e->SetTitle("30M_{#odot} , Z=0.02, t_{revive}=100ms");
        h3001e->SetMaximum(100.0);
        h3001e->DrawClone("Hist same");
        h3001antie->DrawClone("Hist same");
        h3001x->DrawClone("Hist same");
        leg->DrawClone("same");
        c6->Print(savepath + "rate_recoilE.pdf","pdf");//
        TCanvas * c7 = new TCanvas("c7", "", 800, 600);
        c7->SetLogy();
        c7->SetLogx();
        h3002e->GetXaxis()->SetTitle("E_{r} (keV)");
        h3002e->GetYaxis()->SetTitle("Event rate (ton^{-1}s^{-1}MeV^{-1})");
        h3002e->SetTitle("30M_{#odot} , Z=0.02, t_{revive}=200ms");
        h3002e->SetMaximum(100.0);
        h3002e->DrawClone("Hist same");
        h3002antie->DrawClone("Hist same");
        h3002x->DrawClone("Hist same");
        leg->DrawClone("same");
        c7->Print(savepath + "rate_recoilE.pdf","pdf");//
        TCanvas * c8 = new TCanvas("c8", "", 800, 600);
        c8->SetLogy();
        c8->SetLogx();
        h3003e->GetXaxis()->SetTitle("E_{r} (keV)");
        h3003e->GetYaxis()->SetTitle("Event rate (ton^{-1}s^{-1}MeV^{-1})");
        h3003e->SetTitle("30M_{#odot} , Z=0.02, t_{revive}=300ms");
        h3003e->SetMaximum(100.0);
        h3003e->DrawClone("Hist same");
        h3003antie->DrawClone("Hist same");
        h3003x->DrawClone("Hist same");
        leg->DrawClone("same");
        c8->Print(savepath + "rate_recoilE.pdf","pdf");//
        TCanvas * c9 = new TCanvas("c9", "", 800, 600);
        c9->SetLogy();
        c9->SetLogx();
        h5001e->GetXaxis()->SetTitle("E_{r} (keV)");
        h5001e->GetYaxis()->SetTitle("Event rate (ton^{-1}s^{-1}MeV^{-1})");
        h5001e->SetTitle("50M_{#odot} , Z=0.02, t_{revive}=100ms");
        h5001e->SetMaximum(100.0);
        h5001e->DrawClone("Hist same");
        h5001antie->DrawClone("Hist same");
        h5001x->DrawClone("Hist same");
        leg->DrawClone("same");
        c9->Print(savepath + "rate_recoilE.pdf","pdf");//
        h5002e->GetXaxis()->SetTitle("E_{r} (keV)");
        h5002e->GetYaxis()->SetTitle("Event rate (ton^{-1}s^{-1}MeV^{-1})");
        TCanvas * c10 = new TCanvas("c10", "", 800, 600);
        c10->SetLogy();
        c10->SetLogx();
        h5002e->SetTitle("50M_{#odot} , Z=0.02, t_{revive}=200ms");
        h5002e->SetMaximum(100.0);
        h5002e->DrawClone("Hist same");
        h5002antie->DrawClone("Hist same");
        h5002x->DrawClone("Hist same");
        leg->DrawClone("same");
        c10->Print(savepath + "rate_recoilE.pdf","pdf");//
        TCanvas * c11 = new TCanvas("c11", "", 800, 600);
        c11->SetLogy();
        c11->SetLogx();
        h5003e->GetXaxis()->SetTitle("E_{r} (keV)");
        h5003e->GetYaxis()->SetTitle("Event rate (ton^{-1}s^{-1}MeV^{-1}) ");
        h5003e->SetTitle("50M_{#odot} , Z=0.02, t_{revive}=300ms");
        h5003e->SetMaximum(100.0);
        h5003e->DrawClone("Hist same");
        h5003antie->DrawClone("Hist same");
        h5003x->DrawClone("Hist same");
        leg->DrawClone("same");
        c11->Print(savepath + "rate_recoilE.pdf)","pdf");//
        
    }
    
    //event rate_recoilEnergy
    if(opt==5){
        
        TFile *fs = new TFile(loadpath + "recE_spec_total.root", "r");
        
        TH1D * h1301 = (TH1D *) fs->Get("1301_total_recoil");
        TH1D * h1302 = (TH1D *) fs->Get("1302_total_recoil");
        TH1D * h1303 = (TH1D *) fs->Get("1303_total_recoil");
        TH1D * h2001 = (TH1D *) fs->Get("2001_total_recoil");
        TH1D * h2002 = (TH1D *) fs->Get("2002_total_recoil");
        TH1D * h2003 = (TH1D *) fs->Get("2003_total_recoil");
        TH1D * h3001 = (TH1D *) fs->Get("3001_total_recoil");
        TH1D * h3002 = (TH1D *) fs->Get("3002_total_recoil");
        TH1D * h3003 = (TH1D *) fs->Get("3003_total_recoil");
        TH1D * h5001 = (TH1D *) fs->Get("5001_total_recoil");
        TH1D * h5002 = (TH1D *) fs->Get("5002_total_recoil");
        TH1D * h5003 = (TH1D *) fs->Get("5003_total_recoil");
        
        
        h1301->SetLineColor(3); h1302->SetLineColor(3); h1303->SetLineColor(3);
        h2001->SetLineColor(4); h2002->SetLineColor(4); h2003->SetLineColor(4);
        h3001->SetLineColor(2); h3002->SetLineColor(2); h3003->SetLineColor(2);
        h5001->SetLineColor(6); h5002->SetLineColor(6); h5003->SetLineColor(6);
        
        h1301->SetLineStyle(1); h1302->SetLineStyle(2); h1303->SetLineStyle(4);
        h2001->SetLineStyle(1); h2002->SetLineStyle(2); h2003->SetLineStyle(4);
        h3001->SetLineStyle(1); h3002->SetLineStyle(2); h3003->SetLineStyle(4);
        h5001->SetLineStyle(1); h5002->SetLineStyle(2); h5003->SetLineStyle(4);
        
        
        TLegend * leg = new TLegend(0.7, 0.7, 0.9, 0.9);
        leg->AddEntry(h1301, "13M, t_{revive}=100ms", "l");
        leg->AddEntry(h1302, "13M, t_{revive}=200ms", "l");
        leg->AddEntry(h1303, "13M, t_{revive}=300ms", "l");
        leg->AddEntry(h2001, "20M, t_{revive}=100ms", "l");
        leg->AddEntry(h2002, "20M, t_{revive}=200ms", "l");
        leg->AddEntry(h2003, "20M, t_{revive}=300ms", "l");
        leg->AddEntry(h3001, "30M, t_{revive}=100ms", "l");
        leg->AddEntry(h3002, "30M, t_{revive}=200ms", "l");
        leg->AddEntry(h3003, "30M, t_{revive}=300ms", "l");
        leg->AddEntry(h5001, "50M, t_{revive}=100ms", "l");
        leg->AddEntry(h5002, "50M, t_{revive}=200ms", "l");
        leg->AddEntry(h5003, "50M, t_{revive}=300ms", "l");
        
        TCanvas * c0 = new TCanvas("c0", "", 800, 600);
        c0->SetLogy();
        c0->SetLogx();
        h1301->GetXaxis()->SetTitle("E_{r} (keV)");
        h1301->GetYaxis()->SetTitle("Event rate (ton^{-1}s^{-1}keV^{-1})");
        h1301->SetTitle("Total Event Rate");
        h1301->SetMaximum(1.0);
        h1301->DrawClone("Hist same");
        h1302->DrawClone("Hist same");
        h1303->DrawClone("Hist same");
        h2001->DrawClone("Hist same");
        h2002->DrawClone("Hist same");
        h2003->DrawClone("Hist same");
        h3001->DrawClone("Hist same");
        h3002->DrawClone("Hist same");
        h3003->DrawClone("Hist same");
        h5001->DrawClone("Hist same");
        h5002->DrawClone("Hist same");
        h5003->DrawClone("Hist same");
        leg->DrawClone("same");
        c0->Print(savepath + "total_rate_recoilE.pdf","pdf");//
        
        
        
    }
}
