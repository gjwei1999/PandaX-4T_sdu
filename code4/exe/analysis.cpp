/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#include <iostream>
#include <fstream>
#include <cmath>

#include "branches.hpp"

#include "TString.h"
#include "TFile.h"
#include "TMath.h"
#include "TH1D.h"
#include "TH2D.h"


void sort(TTree *tree, TString resorted_root);


int main(int argc, char* argv[]){
    
    //to run the code
    // ./analysis input_file

    if(argc != 3){
        std::cout<<"Error. The input parameters are wrong."<<std::endl;
        std::cout<<"Usage: "<<argv[0]<<" input_root_file   output_root_file_name"<<std::endl;
        
        return 1;
    }
    
    TString path1 = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/output/";
    TString result_root = path1 + argv[2] + ".root";
    
    
    TFile *fs1 = new TFile(result_root.Data(), "RECREATE");
    
    
    std::string input = argv[1];
    TFile *fs = new TFile(input.c_str(), "r");//input data
    TTree *t1 = (TTree*)fs->Get("qmc_tree");
    
    int num_of_events;
    num_of_events = (int)t1->GetEntries();

    
    Branches * branch1 = new Branches();
    branch1->init(t1);
    
    double total_time_simu;//get the total_time of the simulation
    t1->GetEntry(0);
    total_time_simu = branch1->get_total_time();
    
    TH1D * h_event_time = new TH1D("event_time", "event_time", total_time_simu, 0.0, total_time_simu);
    TH1D * h_detected_event_time =new  TH1D("detected_event_time", "detected_event_time", total_time_simu, 0.0, total_time_simu);
    
    TH2D * h_logs2s1_s1= new TH2D("logs2s1_s1", "", 100, 0.0, 150.0, 100, 1.0, 10.0);
    
    
    int n_s1d = 0;
    int n_s2d = 0;
    int n_s1d_s2d = 0;
    
    for (int current_event = 0; current_event < num_of_events; current_event++) {
        
        // Get current event
        t1->GetEntry(current_event);
        
        
        if(branch1->get_S1d() > 0.0){
            n_s1d++;
        }
        
        if(branch1->get_S2d() > 0.0){
            n_s2d++;
        }
        
        if( (branch1->get_S2d() > 0.0) && (branch1->get_S2d() > 0.0)){
            n_s1d_s2d++;
        }
        
        //fill histogram
        h_event_time->Fill(branch1->get_event_time());
        
        if((branch1->get_S1d() > 0.0) && (branch1->get_S2d() > 0.0)){
            h_detected_event_time->Fill(branch1->get_event_time());
        }
        
        double temp;
        temp = TMath::Log(branch1->get_S2d()/branch1->get_S1d());
        h_logs2s1_s1->Fill(branch1->get_S1d(), temp);
        
        //std::cout<<"current event energy is "<<branch1->get_nQuanta()<<std::endl;
    }
    
    //set bin error to 0
        for(int i; i<total_time_simu; i++){
            h_event_time->SetBinError(i, 0.0);
            h_detected_event_time->SetBinError(i, 0.0);
        }
        
    h_event_time->SetDirectory(fs1);
    h_detected_event_time->SetDirectory(fs1);
    h_logs2s1_s1->SetDirectory(fs1);
    
    fs1->Write();
 
    
    std::cout<<"input "<< num_of_events <<" events "<<std::endl;
    //std::cout<<"detected "<< n_s1d <<" S1 signal "<<std::endl;
    //std::cout<<"detected "<< n_s2d <<" S2 signal "<<std::endl;
    std::cout<<"detected "<< n_s1d_s2d <<" S1&S2 signal "<<std::endl;
    std::cout<<"The average rate of detected events is "<< n_s1d_s2d/total_time_simu <<std::endl; 
    
    
    
    TString path2 = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code3/output/re-sorted/";
    TString resorted_root = path2 + argv[2] + "_resort.root";
    
    //sort the entries in the tree according to event_time
    sort(t1, resorted_root);
    
    return 1;
}


void sort(TTree *tree, TString resorted_root) {
	////TFile f("hsimple.root");
	////TTree *tree = (TTree*)f.Get("ntuple");
	Int_t nentries = (Int_t)tree->GetEntries();
	//Drawing variable pz with no graphics option.
	//variable pz stored in array fV1 (see TTree::Draw)
	tree->Draw("event_time","","goff");
	Int_t *index = new Int_t[nentries];
	//sort array containing pz in decreasing order
	//The array index contains the entry numbers in decreasing order of pz
	TMath::Sort(nentries,tree->GetV1(),index, false);
    
	//open new file to store the sorted Tree
    TFile *f2 = new TFile(resorted_root.Data(), "RECREATE");
	////TFile f2("hsimple_sorted.root","recreate");
	//Create an empty clone of the original tree
	TTree *tsorted = (TTree*)tree->CloneTree(0);
	for (Int_t i=0;i<nentries;i++) {
		tree->GetEntry(index[i]);
		tsorted->Fill();
	}

    //tsorted->SetDirectory(f2);
	f2->cd();
    tsorted->Write();
    f2->Close();
	delete [] index;
    
    std::cout<<""<<std::endl;
    std::cout<<"The entries are re-sorted."<<std::endl;
    std::cout<<""<<std::endl;
}
