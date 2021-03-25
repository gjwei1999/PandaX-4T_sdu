/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#include <iostream>

#include "TFile.h"
#include "TMath.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TGraph.h"

#include "eff_far.hpp"

int main(){
    
    TString path = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/output/";
    TString eff_root = path + "eff.root";
    
    TString pdfpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/plots/";
    
    TFile *fs1 = new TFile(eff_root.Data(), "RECREATE");
    
    int nbin = 100000;
    
    int n_thr_min = 2;
    int n_thr_max = 11;
    
    double t_min = 0.03;
    double t_max = 4.0;
    
    int rate15 =15;
    int rate10 =10;
    int rate8 = 8;
    int rate6 = 6;
    int rate4 = 4;
    
    double eff_min = //0.99865010;//3-sigma
    0.99999971;//5-sigma
    
    double time_window = 0.0;
    double efficiency = 0.0;
    double false_alert = 1000.0;//a large number
    
    Eff_far * eff_far1 = new Eff_far();
    
    TH2D * nandt15 = new TH2D("nandt15", "nandt15", nbin, t_min, t_max, n_thr_max-n_thr_min, n_thr_min, n_thr_max);
    TH2D * nandt10 = new TH2D("nandt10", "nandt10", nbin, t_min, t_max, n_thr_max-n_thr_min, n_thr_min, n_thr_max);
    TH2D * nandt8 = new TH2D("nandt8", "nandt8", nbin, t_min, t_max, n_thr_max-n_thr_min, n_thr_min, n_thr_max);
    TH2D * nandt6 = new TH2D("nandt6", "nandt6", nbin, t_min, t_max, n_thr_max-n_thr_min, n_thr_min, n_thr_max);
    TH2D * nandt4 = new TH2D("nandt4", "nandt4", nbin, t_min, t_max, n_thr_max-n_thr_min, n_thr_min, n_thr_max);
    
    nandt15->SetDirectory(fs1);
    nandt10->SetDirectory(fs1);
    nandt8->SetDirectory(fs1);
    nandt6->SetDirectory(fs1);
    nandt4->SetDirectory(fs1); 
     
    TGraph * g15 = new TGraph(0);
    TGraph * g10 = new TGraph(0);
    TGraph * g8 = new TGraph(0);
    TGraph * g6 = new TGraph(0);
    TGraph * g4 = new TGraph(0);
    
    for(int i=n_thr_min; i<n_thr_max; i++){
        
        for(int j=0; j<nbin; j++){
            
        
            //rate = 10
            time_window = t_min + (t_max-t_min)/nbin*j;
            efficiency = eff_far1->trigger_effeciency(i, time_window, rate10);
            false_alert = eff_far1->false_alert_rate(i, time_window);
            
            if((efficiency>eff_min)&&(false_alert<=1.0)){
                nandt10->Fill(time_window, i);
            }
            
            //rate = 8
            efficiency = eff_far1->trigger_effeciency(i, time_window, rate8);
            false_alert = eff_far1->false_alert_rate(i, time_window);
            
            if((efficiency>eff_min)&&(false_alert<=1.0)){
                nandt8->Fill(time_window, i);
            }
            
            //rate = 15
            efficiency = eff_far1->trigger_effeciency(i, time_window, rate15);
            false_alert = eff_far1->false_alert_rate(i, time_window);
            
            if((efficiency>eff_min)&&(false_alert<=1.0)){
                nandt15->Fill(time_window, i);
            }
            
            //rate = 6
            efficiency = eff_far1->trigger_effeciency(i, time_window, rate6);
            false_alert = eff_far1->false_alert_rate(i, time_window);
            
            if((efficiency>eff_min)&&(false_alert<=1.0)){
                nandt6->Fill(time_window, i);
            }
            
            //rate = 4
            efficiency = eff_far1->trigger_effeciency(i, time_window, rate4);
            false_alert = eff_far1->false_alert_rate(i, time_window);
            
            if((efficiency>eff_min)&&(false_alert<=1.0)){
                nandt4->Fill(time_window, i);
            }
            
        }
    }
    
    gStyle->SetPalette(53);
    
    nandt15->SetMarkerColor(1);
    nandt10->SetMarkerColor(4);
    nandt8->SetMarkerColor(2);
    nandt6->SetMarkerColor(6);
    nandt4->SetMarkerColor(7);
    
    g15->SetFillColor(1);
    g10->SetFillColor(4);
    g8->SetFillColor(2);
    g6->SetFillColor(6);
    g4->SetFillColor(7);
    
    TLegend * leg = new TLegend(0.1, 0.7, 0.3, 0.9);
    leg->AddEntry(g15, "SN rate = 15", "f");
    leg->AddEntry(g10, "SN rate = 10", "f");
    leg->AddEntry(g8, "SN rate = 8", "f");
    leg->AddEntry(g6, "SN rate = 6", "f");
    leg->AddEntry(g4, "SN rate = 4", "f");
    
    TCanvas * c0 = new TCanvas("c0", "", 800, 600);
    nandt15->GetXaxis()->SetTitle("T_{SN} (s)");
    nandt15->GetYaxis()->SetTitle("N_{thr}");
    nandt15->SetTitle("Qualified T_{SN} & N_{thr} with 5#sigma trigger efficiency");
    nandt15->SetStats(0);
    nandt15->DrawClone();
    nandt10->DrawClone("same");
    nandt8->DrawClone("same");
    nandt6->DrawClone("same");
    nandt4->DrawClone("same");
    leg->DrawClone("same");

    c0->Print(pdfpath + "eff.pdf","pdf");    
    
    fs1->Write();
    delete eff_far1;
    
    return 1;
}
