/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

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
    
    TString loadpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/output/";
    TString savepath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/plots/";
    
    
    //trigger efficiency vs T_sn with different rate
    if(opt == 1){
        
        TFile *fs = new TFile(loadpath + "eff.root", "r");
        
        TH1D * h_eff_T_2 = (TH1D *) fs->Get("eff_Tsn_n2_r2.00");
        TH1D * h_eff_T_4 = (TH1D *) fs->Get("eff_Tsn_n2_r4.00");
        TH1D * h_eff_T_6 = (TH1D *) fs->Get("eff_Tsn_n2_r6.00");
        TH1D * h_eff_T_8 = (TH1D *) fs->Get("eff_Tsn_n2_r8.00");
        TH1D * h_eff_T_10 = (TH1D *) fs->Get("eff_Tsn_n2_r10.00");
        
        TH1D * h_eff_r_2 = (TH1D *) fs->Get("eff_rate_n2_Tsn1.0");
        TH1D * h_eff_r_3 = (TH1D *) fs->Get("eff_rate_n3_Tsn1.0");
        TH1D * h_eff_r_4 = (TH1D *) fs->Get("eff_rate_n4_Tsn1.0");
        TH1D * h_eff_r_5 = (TH1D *) fs->Get("eff_rate_n5_Tsn1.0");

        h_eff_T_2->SetLineColor(1); 
        h_eff_T_4->SetLineColor(4); 
        h_eff_T_6->SetLineColor(2);
        h_eff_T_8->SetLineColor(6); 
        h_eff_T_10->SetLineColor(7); 
        
        h_eff_r_2->SetLineColor(1); 
        h_eff_r_3->SetLineColor(4); 
        h_eff_r_4->SetLineColor(2);
        h_eff_r_5->SetLineColor(6); 
        
        TLegend * leg1 = new TLegend(0.6, 0.7, 0.9, 0.9);
        leg1->AddEntry(h_eff_T_2, "N_{thr}=2, rate=2Hz", "l");
        leg1->AddEntry(h_eff_T_4, "N_{thr}=2, rate=4Hz", "l");
        leg1->AddEntry(h_eff_T_6, "N_{thr}=2, rate=6Hz", "l");
        leg1->AddEntry(h_eff_T_8, "N_{thr}=2, rate=8Hz", "l");
        leg1->AddEntry(h_eff_T_10, "N_{thr}=2, rate=10Hz", "l");
        
        TLegend * leg2 = new TLegend(0.6, 0.7, 0.9, 0.9);
        leg2->AddEntry(h_eff_r_2, "N_{thr}=2, T_{SN}=1s", "l");
        leg2->AddEntry(h_eff_r_3, "N_{thr}=3, T_{SN}=1s", "l");
        leg2->AddEntry(h_eff_r_4, "N_{thr}=4, T_{SN}=1s", "l");
        leg2->AddEntry(h_eff_r_5, "N_{thr}=5, T_{SN}=1s", "l");
        
        TCanvas * c0 = new TCanvas("c0", "", 800, 600);
        c0->SetGrid();
        h_eff_T_2->GetXaxis()->SetTitle("T_{SN} (s)");
        h_eff_T_2->GetYaxis()->SetTitle("trigger efficiency ");
        h_eff_T_2->SetMaximum(1.5);
        h_eff_T_2->DrawClone("same");
        h_eff_T_4->DrawClone("same");
        h_eff_T_6->DrawClone("same");
        h_eff_T_8->DrawClone("same");
        h_eff_T_10->DrawClone("same");
        leg1->DrawClone("same");
        c0->Print(savepath + "trigger_eff.pdf(","pdf");//
        TCanvas * c1 = new TCanvas("c1", "", 800, 600);
        c1->SetGrid();
        h_eff_r_2->GetXaxis()->SetTitle("Rate(Hz)");
        h_eff_r_2->GetYaxis()->SetTitle("trigger efficiency ");
        h_eff_r_2->SetMaximum(1.5);
        h_eff_r_2->DrawClone("same");
        h_eff_r_3->DrawClone("same");
        h_eff_r_4->DrawClone("same");
        h_eff_r_5->DrawClone("same");
        leg2->DrawClone("same");
        c1->Print(savepath + "trigger_eff.pdf","pdf");//
        TCanvas * c2 = new TCanvas("c2", "", 800, 600);
        c2->SetGrid();
        h_eff_r_2->GetXaxis()->SetTitle("Rate(Hz)");
        h_eff_r_2->GetYaxis()->SetTitle("trigger efficiency ");
        h_eff_r_2->SetMaximum(1.02);
        h_eff_r_2->SetMinimum(0.98);
        h_eff_r_2->DrawClone("same");
        h_eff_r_3->DrawClone("same");
        h_eff_r_4->DrawClone("same");
        h_eff_r_5->DrawClone("same");
        c2->Print(savepath + "trigger_eff.pdf)","pdf");//
        
    }
    
    //differential rate vs S1 S2
    if(opt == 2){

        TString pdfpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/plots/";
        TString loadpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/output/3003_7s_10000.root";
        
        TFile *fs = new TFile(loadpath, "r");
        
        TH1D * plot_s1 = (TH1D *) fs->Get("s1_signal");
        TH1D * plot_s2 = (TH1D *) fs->Get("s2_signal");
        
        TCanvas * c0 = new TCanvas("c0", "", 800, 600);
        plot_s1->GetXaxis()->SetTitle("S1d[PE]");
        plot_s1->GetYaxis()->SetTitle("Differential Rate [count/ton/PE]");
        plot_s1->SetTitle("#scale[0.9]{#frac{#font[12]{d}R}{#font[12]{d}S1d} vs S1d}");
        plot_s1->SetAxisRange(0.0, 3.0, "Y");
        plot_s1->Draw();
        c0->Print(pdfpath + "s1&s2.pdf(","pdf"); 
        
        TCanvas * c1 = new TCanvas("c1", "", 800, 600);
        plot_s2->GetXaxis()->SetTitle("S2d[100PE]");
        plot_s2->GetYaxis()->SetTitle("Differential Rate [count/ton/100PE]");
        plot_s2->SetTitle("#scale[0.9]{#frac{#font[12]{d}R}{#font[12]{d}S2d} vs S2d}");
        plot_s2->SetAxisRange(0.0, 2.0, "Y");
        plot_s2->Draw();
        c1->Print(pdfpath + "s1&s2.pdf)","pdf"); 
        
        
        
    }
    
}
