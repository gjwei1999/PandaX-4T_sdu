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
#include "TLatex.h"
//#include "TROOT.h"

#include "eff_far.hpp"


void plot();
void contour_3sigma();
void contour_5sigma();

int main(){
    
    TString path = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/output/";
    TString eff_root = path + "eff.root";
    
    TFile *fs1 = new TFile(eff_root.Data(), "RECREATE");
    
    int nbin = 100;
    
    int n_thr_min = 2;
    int n_thr_max = 20;
    
    double t_min = 1e-3;
    double t_max = 2.0;
    
    double log_t_min = TMath::Log10(t_min);
    double log_t_max = TMath::Log10(t_max);
    
    //double * log_bin = new double[nbin+1];
    double * bin = new double[nbin+1];
    double width = (log_t_max-log_t_min)/nbin;
    
    for(int i=0; i<nbin+1; i++){
        //log_bin[i] = log_t_min + i*width;
        bin[i] = TMath::Power(10, log_t_min + i*width);
        
        //std::cout<<"bin["<<i<<"] = "<<bin[i]<<std::endl;
    }
    
    int rate15 =15;
    
    int rate1 = 1;
    int rate10 =10;
    int rate100 = 100;
    int rate1000 = 1000;
    
    double eff_min = TMath::Freq(3);//0.99865010;//3-sigma
    //0.99999971;//5-sigma
    
    double time_window = 0.0;
    int n_thr = 0;
    
    double efficiency = 0.0;
    double false_alert = 100.0;//a large number
    
    Eff_far * eff_far1 = new Eff_far();
    
    //TH2D * eff15 = new TH2D("eff15", "eff15", nbin, t_min, t_max, nbin, n_thr_min, n_thr_max);
    TH2D * eff15 = new TH2D("eff15", "eff15", nbin, bin, nbin, n_thr_min, n_thr_max);
    TH2D * far15 = new TH2D("far15", "far15", nbin, bin, nbin, n_thr_min, n_thr_max);
    
    TH2D * eff1 = new TH2D("eff1", "eff1", nbin, bin, nbin, n_thr_min, n_thr_max);
    //TH2D * far1 = new TH2D("far1", "far1", nbin, bin, nbin, n_thr_min, n_thr_max);
    
    TH2D * eff10 = new TH2D("eff10", "eff10", nbin, bin, nbin, n_thr_min, n_thr_max);
    //TH2D * far10 = new TH2D("far10", "far10", nbin, bin, nbin, n_thr_min, n_thr_max);
    
    TH2D * eff100 = new TH2D("eff100", "eff100", nbin, bin, nbin, n_thr_min, n_thr_max);
    //TH2D * far100 = new TH2D("far100", "far100", nbin, bin, nbin, n_thr_min, n_thr_max);
    
    TH2D * eff1000 = new TH2D("eff1000", "eff1000", nbin, bin, nbin, n_thr_min, n_thr_max);
    //TH2D * far1000 = new TH2D("far1000", "far1000", nbin, bin, nbin, n_thr_min, n_thr_max);
    
    
    eff15->SetDirectory(fs1);
    far15->SetDirectory(fs1);
    
    eff1->SetDirectory(fs1);
    //far1->SetDirectory(fs1);
    eff10->SetDirectory(fs1);
    //far10->SetDirectory(fs1);
    eff100->SetDirectory(fs1);
    //far100->SetDirectory(fs1);
    eff1000->SetDirectory(fs1);
    //far1000->SetDirectory(fs1);
    
    //for(int i=n_thr_min; i<n_thr_max; i++){
    for(int i=0; i<nbin; i++){
        
        n_thr = n_thr_min + ((double)n_thr_max-(double)n_thr_min)/nbin*i;
        //std::cout<<"The i = "<<i<<std::endl;
        //std::cout<<"The n_thr = "<<n_thr<<std::endl;
            
        for(int j=0; j<nbin; j++){
            
            //time_window = t_min + (t_max-t_min)/nbin*j;
            time_window = bin[j];
            
            //rate = 15
            efficiency = eff_far1->trigger_effeciency(n_thr, time_window, rate15);
            false_alert = eff_far1->false_alert_rate(n_thr, time_window);
            
            eff15->SetBinContent(j, i, efficiency);
            far15->SetBinContent(j, i, false_alert);
            
            //std::cout<<"when n_thr = "<<n_thr<<std::endl;
            //std::cout<<"The T = "<<time_window<<std::endl;
            //std::cout<<"The efficiency = "<<efficiency<<std::endl;
            
            //rate  = 1
            efficiency = eff_far1->trigger_effeciency(n_thr, time_window, rate1);
            //false_alert = eff_far1->false_alert_rate(n_thr, time_window);
            
            eff1->SetBinContent(j, i, efficiency);
            //far1->SetBinContent(j, i, false_alert);
            
            //rate = 10
            efficiency = eff_far1->trigger_effeciency(n_thr, time_window, rate10);
            //false_alert = eff_far1->false_alert_rate(n_thr, time_window);
            
            eff10->SetBinContent(j, i, efficiency);
            //far10->SetBinContent(j, i, false_alert);
            
            //rate = 100
            efficiency = eff_far1->trigger_effeciency(n_thr, time_window, rate100);
            //false_alert = eff_far1->false_alert_rate(n_thr, time_window);
            
            eff100->SetBinContent(j, i, efficiency);
            //far100->SetBinContent(j, i, false_alert);
            
            //rate = 1000
            efficiency = eff_far1->trigger_effeciency(n_thr, time_window, rate1000);
            //false_alert = eff_far1->false_alert_rate(n_thr, time_window);
            
            eff1000->SetBinContent(j, i, efficiency);
            //far1000->SetBinContent(j, i, false_alert);
            
            
        }
    }
    
    fs1->Write();
    delete eff_far1;
    
    plot();//draw the plots on pdf
    contour_3sigma();
    contour_5sigma();
    
    return 1;
}


void plot(){
    
    gStyle->SetPalette(57);
    
    
    TString pdfpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/plots/";
    TString loadpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/output/eff.root";
    
    TFile *fs = new TFile(loadpath, "r");
    
    //******************************************************
    //rate = 15
    TH2D * eff15 = (TH2D *) fs->Get("eff15");
    TH2D * far15 = (TH2D *) fs->Get("far15");
    
    TCanvas * c15_0 = new TCanvas("c15_0", "", 800, 600);
    c15_0->SetLogx();
    eff15->GetXaxis()->SetTitle("T_{SN} (s)");
    eff15->GetYaxis()->SetTitle("N_{thr}");
    eff15->SetTitle("Trigger Efficiency with rate=15Hz");
    eff15->SetStats(0);
    eff15->Draw("SURF2");
    //eff15->Draw("CONT1Z");
    //eff15->Draw("COLZ");
    c15_0->Print(pdfpath + "eff15.pdf(","pdf"); 
    TCanvas * c15_1 = new TCanvas("c15_1", "", 800, 600);
    c15_1->SetLogx();
    TLatex latex15;
    latex15.SetTextSize(0.03);
    
    //double contours[9]={0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};
    double contours15[5] = {0.1, 0.5, 0.8, TMath::Freq(3), TMath::Freq(5)};
    //double contours[1] = {TMath::Freq(3)};
    eff15->SetContour(5, contours15);
    
    eff15->Draw("CONT1");
    latex15.DrawLatex( 0.04, 3.0,"0.1");
    latex15.DrawLatex( 0.1, 3.0,"0.5");
    latex15.DrawLatex( 0.2, 3.0,"0.8");
    latex15.DrawLatex( 0.6, 3.0,"3#sigma");
    latex15.DrawLatex( 1.1, 3.0,"5#sigma");
    
    c15_1->Print(pdfpath + "eff15.pdf)","pdf");   
    TCanvas * c15_2 = new TCanvas("c15_2", "", 800, 600);
    c15_2->SetLogx();
    far15->SetStats(0);
    far15->SetTitle("False Alert Rate");
    far15->GetXaxis()->SetTitle("T_{SN} (s)");
    far15->GetYaxis()->SetTitle("N_{thr}");
    far15->DrawClone("SURF2");
    c15_2->Print(pdfpath + "far.pdf(","pdf");    
    TCanvas * c15_3 = new TCanvas("c15_3", "", 800, 600);
    c15_3->SetLogx();
    far15->SetTitle("False Alert Rate");
    
    double far_con15[4] = {0.1, 1.0, 10.0, 100.0};
    far15->SetContour(4, far_con15);
    
    far15->DrawClone("CONT1");
    latex15.DrawLatex( 0.05, 2.5,"0.1Hz");
    latex15.DrawLatex( 0.15, 2.5,"1Hz");
    latex15.DrawLatex( 0.5, 2.5,"10Hz");
    latex15.DrawLatex( 1.5, 2.5,"100Hz");
    
    c15_3->Print(pdfpath + "far.pdf)","pdf");
    
    
    //******************************************************
    //rate = 1
    TH2D * eff1 = (TH2D *) fs->Get("eff1");
    
    TCanvas * c1_0 = new TCanvas("c1_0", "", 800, 600);
    c1_0->SetLogx();
    eff1->GetXaxis()->SetTitle("T_{SN} (s)");
    eff1->GetYaxis()->SetTitle("N_{thr}");
    eff1->SetTitle("Trigger Efficiency with rate=1Hz");
    eff1->SetStats(0);
    eff1->Draw("SURF2");
    //eff1->Draw("CONT1Z");
    //eff1->Draw("COLZ");
    c1_0->Print(pdfpath + "eff1.pdf(","pdf"); 
    TCanvas * c1_1 = new TCanvas("c1_1", "", 800, 600);
    c1_1->SetLogx();
    TLatex latex1;
    latex1.SetTextSize(0.03);
    
    //double contours[9]={0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};
    double contours1[5] = {0.1, 0.5, 0.8, TMath::Freq(3), TMath::Freq(5)};
    //double contours[1] = {TMath::Freq(3)};
    eff1->SetContour(5, contours1);
    
    eff1->Draw("CONT1");
    latex1.DrawLatex( 0.5, 2.5,"0.1");
    latex1.DrawLatex( 1.5, 2.5,"0.5");
    //latex1.DrawLatex( 0.2, 3.0,"0.8");
    //latex1.DrawLatex( 0.6, 3.0,"3#sigma");
    //latex1.DrawLatex( 1.1, 3.0,"5#sigma");
    
    c1_1->Print(pdfpath + "eff1.pdf)","pdf");   
    
    
    //******************************************************
    //rate = 10
    TH2D * eff10 = (TH2D *) fs->Get("eff10");
    
    TCanvas * c10_0 = new TCanvas("c10_0", "", 800, 600);
    c10_0->SetLogx();
    eff10->GetXaxis()->SetTitle("T_{SN} (s)");
    eff10->GetYaxis()->SetTitle("N_{thr}");
    eff10->SetTitle("Trigger Efficiency with rate=10Hz");
    eff10->SetStats(0);
    eff10->Draw("SURF2");
    //eff10->Draw("CONT1Z");
    //eff10->Draw("COLZ");
    c10_0->Print(pdfpath + "eff10.pdf(","pdf"); 
    TCanvas * c10_1 = new TCanvas("c10_1", "", 800, 600);
    c10_1->SetLogx();
    TLatex latex10;
    latex10.SetTextSize(0.03);
    
    //double contours[9]={0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};
    double contours10[5] = {0.1, 0.5, 0.8, TMath::Freq(3), TMath::Freq(5)};
    //double contours[1] = {TMath::Freq(3)};
    eff10->SetContour(5, contours10);
    
    eff10->Draw("CONT1");
    latex10.DrawLatex( 0.05, 2.5,"0.1");
    latex10.DrawLatex( 0.15, 2.5,"0.5");
    latex10.DrawLatex( 0.3, 2.5,"0.8");
    latex10.DrawLatex( 0.8, 2.5,"3#sigma");
    latex10.DrawLatex( 1.5, 2.5,"5#sigma");
    
    c10_1->Print(pdfpath + "eff10.pdf)","pdf");   
    
    
    //******************************************************
    //rate = 100
    TH2D * eff100 = (TH2D *) fs->Get("eff100");
    
    TCanvas * c100_0 = new TCanvas("c100_0", "", 800, 600);
    c100_0->SetLogx();
    eff100->GetXaxis()->SetTitle("T_{SN} (s)");
    eff100->GetYaxis()->SetTitle("N_{thr}");
    eff100->SetTitle("Trigger Efficiency with rate=100Hz");
    eff100->SetStats(0);
    eff100->Draw("SURF2");
    //eff100->Draw("CONT1Z");
    //eff100->Draw("COLZ");
    c100_0->Print(pdfpath + "eff100.pdf(","pdf"); 
    TCanvas * c100_1 = new TCanvas("c100_1", "", 800, 600);
    c100_1->SetLogx();
    TLatex latex100;
    latex100.SetTextSize(0.03);
    
    //double contours[9]={0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};
    double contours100[5] = {0.1, 0.5, 0.8, TMath::Freq(3), TMath::Freq(5)};
    //double contours[1] = {TMath::Freq(3)};
    eff100->SetContour(5, contours100);
    
    eff100->Draw("CONT1");
    latex100.DrawLatex( 0.005, 2.5,"0.1");
    latex100.DrawLatex( 0.015, 2.5,"0.5");
    latex100.DrawLatex( 0.03, 2.5,"0.8");
    latex100.DrawLatex( 0.08, 2.5,"3#sigma");
    latex100.DrawLatex( 0.17, 2.5,"5#sigma");
    
    c100_1->Print(pdfpath + "eff100.pdf)","pdf");   
   
    
    //******************************************************
    //rate = 1000
    TH2D * eff1000 = (TH2D *) fs->Get("eff1000");
    
    TCanvas * c1000_0 = new TCanvas("c1000_0", "", 800, 600);
    c1000_0->SetLogx();
    eff1000->GetXaxis()->SetTitle("T_{SN} (s)");
    eff1000->GetYaxis()->SetTitle("N_{thr}");
    eff1000->SetTitle("Trigger Efficiency with rate=1000Hz");
    eff1000->SetStats(0);
    eff1000->Draw("SURF2");
    //eff1000->Draw("CONT1Z");
    //eff1000->Draw("COLZ");
    c1000_0->Print(pdfpath + "eff1000.pdf(","pdf"); 
    TCanvas * c1000_1 = new TCanvas("c1000_1", "", 800, 600);
    c1000_1->SetLogx();
    TLatex latex1000;
    latex1000.SetTextSize(0.03);
    
    //double contours[9]={0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};
    double contours1000[5] = {0.1, 0.5, 0.8, TMath::Freq(3), TMath::Freq(5)};
    //double contours[1] = {TMath::Freq(3)};
    eff1000->SetContour(5, contours1000);
    
    eff1000->Draw("CONT1");
    latex1000.DrawLatex( 0.001, 3.5,"0.1");
    latex1000.DrawLatex( 0.0025, 3.5,"0.5");
    latex1000.DrawLatex( 0.004, 3.5,"0.8");
    latex1000.DrawLatex( 0.01, 3.5,"3#sigma");
    latex1000.DrawLatex( 0.02, 3.5,"5#sigma");
    
    c1000_1->Print(pdfpath + "eff1000.pdf)","pdf");   
    
    
}

void contour_3sigma(){
    
    TString pdfpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/plots/";
    TString loadpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/output/eff.root";
    
    TFile *fs = new TFile(loadpath, "r");
    
    //TLatex latex;
    //latex.SetTextSize(0.03);
    
    TH2D * eff1000 = (TH2D *) fs->Get("eff1000");
    TH2D * eff100 = (TH2D *) fs->Get("eff100");
    TH2D * eff10 = (TH2D *) fs->Get("eff10");
    TH2D * eff1 = (TH2D *) fs->Get("eff1");
    TH2D * far = (TH2D *) fs->Get("far15");
    
    eff1000->SetLineColor(1);
    eff100->SetLineColor(6);
    eff10->SetLineColor(7);
    eff1->SetLineColor(4);
    far->SetLineColor(2);
    
    double contours1[1] = {TMath::Freq(3)};
    double contours2[1] = {1.0};
    eff1000->SetContour(1, contours1);
    eff100->SetContour(1, contours1);
    eff10->SetContour(1, contours1);
    eff1->SetContour(1, contours1);
    far->SetContour(1, contours2);
    
    TLegend * leg = new TLegend(0.1, 0.7, 0.3, 0.9);
    leg->AddEntry(eff1000, "1000Hz", "l");
    leg->AddEntry(eff100, "100Hz", "l");
    leg->AddEntry(eff10, "10Hz", "l");
    leg->AddEntry(eff1, "1Hz", "l");
    leg->AddEntry(far, "FAR=1/week ", "l");
    
    TCanvas * c1 = new TCanvas("c1", "", 800, 600);
    c1->SetLogx();
    eff1000->GetXaxis()->SetTitle("T_{SN} (s)");
    eff1000->GetYaxis()->SetTitle("N_{thr}");
    eff1000->SetTitle("3#sigma Trigger Efficiency & False Alert Rate ");
    eff1000->SetStats(0);
    
    eff1000->Draw("CONT3");
    eff100->Draw("CONT3 SAME");
    eff10->Draw("CONT3 SAME");
    eff1->Draw("CONT3 SAME");
    far->Draw("CONT3 SAME");
    
    leg->Draw("SAME");
    
    //latex.DrawLatex( 0.01, 3.5,"1000Hz");
    //latex.DrawLatex( 0.08, 2.5,"100Hz");
    
    c1->Print(pdfpath + "3sigma.pdf","pdf");   
    
}

void contour_5sigma(){
    
    TString pdfpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/plots/";
    TString loadpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/output/eff.root";
    
    TFile *fs = new TFile(loadpath, "r");
    
    //TLatex latex;
    //latex.SetTextSize(0.03);
    
    TH2D * eff1000 = (TH2D *) fs->Get("eff1000");
    TH2D * eff100 = (TH2D *) fs->Get("eff100");
    TH2D * eff10 = (TH2D *) fs->Get("eff10");
    TH2D * eff1 = (TH2D *) fs->Get("eff1");
    TH2D * far = (TH2D *) fs->Get("far15");
    
    eff1000->SetLineColor(1);
    eff100->SetLineColor(6);
    eff10->SetLineColor(7);
    eff1->SetLineColor(4);
    far->SetLineColor(2);
    
    double contours1[1] = {TMath::Freq(5)};
    double contours2[1] = {1.0};
    eff1000->SetContour(1, contours1);
    eff100->SetContour(1, contours1);
    eff10->SetContour(1, contours1);
    eff1->SetContour(1, contours1);
    far->SetContour(1, contours2);
    
    TLegend * leg = new TLegend(0.1, 0.7, 0.3, 0.9);
    leg->AddEntry(eff1000, "1000Hz", "l");
    leg->AddEntry(eff100, "100Hz", "l");
    leg->AddEntry(eff10, "10Hz", "l");
    leg->AddEntry(eff1, "1Hz", "l");
    leg->AddEntry(far, "FAR=1/week ", "l");
    
    TCanvas * c1 = new TCanvas("c1", "", 800, 600);
    c1->SetLogx();
    eff1000->GetXaxis()->SetTitle("T_{SN} (s)");
    eff1000->GetYaxis()->SetTitle("N_{thr}");
    eff1000->SetTitle("5#sigma Trigger Efficiency & False Alert Rate ");
    eff1000->SetStats(0);
    
    eff1000->Draw("CONT3");
    eff100->Draw("CONT3 SAME");
    eff10->Draw("CONT3 SAME");
    eff1->Draw("CONT3 SAME");
    far->Draw("CONT3 SAME");
    
    leg->Draw("SAME");
    
    //latex.DrawLatex( 0.01, 3.5,"1000Hz");
    //latex.DrawLatex( 0.08, 2.5,"100Hz");
    
    c1->Print(pdfpath + "5sigma.pdf","pdf");   
    
}

