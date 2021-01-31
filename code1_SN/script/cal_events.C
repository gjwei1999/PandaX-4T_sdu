/*****************************/
/*                                                      */
/*       Created by Jiawei Guo          */
/*        Shandong University            */
/*                                                      */
/*****************************/

#include <cmath>
#include "TFile.h"
#include "TH1D.h"
#include "TString.h"


int main(){
    
    TString loadpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code1_SN/build/";
    TFile *fs = new TFile(loadpath + "recE_spec_total.root", "r");
    
    int bin_num_left;
    int bin_num_right;
    double num_of_events;
    
    
    //13 solar mass
    //1301
    TH1D * h1301 = (TH1D *) fs->Get("1301_total_recoil");
    
    bin_num_left = h1301->GetBin(0.0);
    bin_num_right = h1301->GetBin(100.0);
    
    num_of_events = h1301->Integral(bin_num_left, bin_num_right);
    
    std::cout<<"The events rate in the first second for 1301 is "<<num_of_events<<" ton-1 s-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in the first second is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    
    //1302
    TH1D * h1302 = (TH1D *) fs->Get("1302_total_recoil");
    
    bin_num_left = h1302->GetBin(0.0);
    bin_num_right = h1302->GetBin(100.0);
    
    num_of_events = h1302->Integral(bin_num_left, bin_num_right);
    
    std::cout<<"The events rate in the first second for 1302 is "<<num_of_events<<" ton-1 s-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in the first second is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    
    //1303
    TH1D * h1303 = (TH1D *) fs->Get("1303_total_recoil");
    
    bin_num_left = h1303->GetBin(0.0);
    bin_num_right = h1303->GetBin(100.0);
    
    num_of_events = h1303->Integral(bin_num_left, bin_num_right);
    
    std::cout<<"The events rate in the first second for 1303 is "<<num_of_events<<" ton-1 s-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in the first second is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    //20 solar mass
    //2001
    TH1D * h2001 = (TH1D *) fs->Get("2001_total_recoil");
    
    bin_num_left = h2001->GetBin(0.0);
    bin_num_right = h2001->GetBin(100.0);
    
    num_of_events = h2001->Integral(bin_num_left, bin_num_right);
    
    std::cout<<"The events rate in the first second for 2001 is "<<num_of_events<<" ton-1 s-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in the first second is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    
    //2002
    TH1D * h2002 = (TH1D *) fs->Get("2002_total_recoil");
    
    bin_num_left = h2002->GetBin(0.0);
    bin_num_right = h2002->GetBin(100.0);
    
    num_of_events = h2002->Integral(bin_num_left, bin_num_right);
    
    std::cout<<"The events rate in the first second for 2002 is "<<num_of_events<<" ton-1 s-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in the first second is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    
    //2003
    TH1D * h2003 = (TH1D *) fs->Get("2003_total_recoil");
    
    bin_num_left = h2003->GetBin(0.0);
    bin_num_right = h2003->GetBin(100.0);
    
    num_of_events = h2003->Integral(bin_num_left, bin_num_right);
    
    std::cout<<"The events rate in the first second for 2003 is "<<num_of_events<<" ton-1 s-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in the first second is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    //30 solar mass
    //3001
    TH1D * h3001 = (TH1D *) fs->Get("3001_total_recoil");
    
    bin_num_left = h3001->GetBin(0.0);
    bin_num_right = h3001->GetBin(100.0);
    
    num_of_events = h3001->Integral(bin_num_left, bin_num_right);
    
    std::cout<<"The events rate in the first second for 3001 is "<<num_of_events<<" ton-1 s-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in the first second is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    
    //3002
    TH1D * h3002 = (TH1D *) fs->Get("3002_total_recoil");
    
    bin_num_left = h3002->GetBin(0.0);
    bin_num_right = h3002->GetBin(100.0);
    
    num_of_events = h3002->Integral(bin_num_left, bin_num_right);
    
    std::cout<<"The events rate in the first second for 3002 is "<<num_of_events<<" ton-1 s-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in the first second is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    
    //3003
    TH1D * h3003 = (TH1D *) fs->Get("3003_total_recoil");
    
    bin_num_left = h3003->GetBin(0.0);
    bin_num_right = h3003->GetBin(100.0);
    
    num_of_events = h3003->Integral(bin_num_left, bin_num_right);
    
    std::cout<<"The events rate in the first second for 3003 is "<<num_of_events<<" ton-1 s-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in the first second is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    //50 solar mass
    //5001
    TH1D * h5001 = (TH1D *) fs->Get("5001_total_recoil");
    
    bin_num_left = h5001->GetBin(0.0);
    bin_num_right = h5001->GetBin(100.0);
    
    num_of_events = h5001->Integral(bin_num_left, bin_num_right);
    
    std::cout<<"The events rate in the first second for 5001 is "<<num_of_events<<" ton-1 s-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in the first second is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    
    //5002
    TH1D * h5002 = (TH1D *) fs->Get("5002_total_recoil");
    
    bin_num_left = h5002->GetBin(0.0);
    bin_num_right = h5002->GetBin(100.0);
    
    num_of_events = h5002->Integral(bin_num_left, bin_num_right);
    
    std::cout<<"The events rate in the first second for 5002 is "<<num_of_events<<" ton-1 s-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in the first second is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    
    //5003
    TH1D * h5003 = (TH1D *) fs->Get("5003_total_recoil");
    
    bin_num_left = h5003->GetBin(0.0);
    bin_num_right = h5003->GetBin(100.0);
    
    num_of_events = h5003->Integral(bin_num_left, bin_num_right);
    
    std::cout<<"The events rate in the first second for 5003 is "<<num_of_events<<" ton-1 s-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in the first second is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    return 1;
}
