/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#include <cmath>
#include "TFile.h"
#include "TH1D.h"
#include "TString.h"


int main(){
    
    //TString loadpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code1_SN/output/1st_second/";
    TString loadpath = "/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code1_SN/output/";
    TFile *fs = new TFile(loadpath + "time_spec.root", "r");
    TFile *fs1 = new TFile(loadpath + "energy_spec.root", "r");
    
    int bin_num_left;
    int bin_num_right;
    double num_of_events;
    
    
    //13 solar mass
    //1301
    TH1D * h1301_1 = (TH1D *) fs->Get("1301e");
    num_of_events = h1301_1->Integral("width");
    
    TH1D * h1301_2 = (TH1D *) fs->Get("1301antie");
    num_of_events += h1301_2->Integral("width");
    
    TH1D * h1301_3 = (TH1D *) fs->Get("1301x");
    num_of_events += 4 * h1301_3->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 1301 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    TH1D * h1301_1e = (TH1D *) fs->Get("1301e");
    num_of_events = h1301_1e->Integral("width");
    
    TH1D * h1301_2e = (TH1D *) fs->Get("1301antie");
    num_of_events += h1301_2e->Integral("width");
    
    TH1D * h1301_3e = (TH1D *) fs->Get("1301x");
    num_of_events += 4 * h1301_3e->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 1301 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    //1302
    TH1D * h1302_1 = (TH1D *) fs->Get("1302e");
    num_of_events = h1302_1->Integral("width");
    
    TH1D * h1302_2 = (TH1D *) fs->Get("1302antie");
    num_of_events += h1302_2->Integral("width");
    
    TH1D * h1302_3 = (TH1D *) fs->Get("1302x");
    num_of_events += 4 * h1302_3->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 1302 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    
    TH1D * h1302_1e = (TH1D *) fs->Get("1302e");
    num_of_events = h1302_1e->Integral("width");
    
    TH1D * h1302_2e = (TH1D *) fs->Get("1302antie");
    num_of_events += h1302_2e->Integral("width");
    
    TH1D * h1302_3e = (TH1D *) fs->Get("1302x");
    num_of_events += 4 * h1302_3e->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 1302 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    //1303
    TH1D * h1303_1 = (TH1D *) fs->Get("1303e");
    num_of_events = h1303_1->Integral("width");
    
    TH1D * h1303_2 = (TH1D *) fs->Get("1303antie");
    num_of_events += h1303_2->Integral("width");
    
    TH1D * h1303_3 = (TH1D *) fs->Get("1303x");
    num_of_events += 4 * h1303_3->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 1303 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    
    TH1D * h1303_1e = (TH1D *) fs->Get("1303e");
    num_of_events = h1303_1e->Integral("width");
    
    TH1D * h1303_2e = (TH1D *) fs->Get("1303antie");
    num_of_events += h1303_2e->Integral("width");
    
    TH1D * h1303_3e = (TH1D *) fs->Get("1303x");
    num_of_events += 4 * h1303_3e->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 1303 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    //2001
    TH1D * h2001_1 = (TH1D *) fs->Get("2001e");
    num_of_events = h2001_1->Integral("width");
    
    TH1D * h2001_2 = (TH1D *) fs->Get("2001antie");
    num_of_events += h2001_2->Integral("width");
    
    TH1D * h2001_3 = (TH1D *) fs->Get("2001x");
    num_of_events += 4 * h2001_3->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 2001 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    
    TH1D * h2001_1e = (TH1D *) fs->Get("2001e");
    num_of_events = h2001_1e->Integral("width");
    
    TH1D * h2001_2e = (TH1D *) fs->Get("2001antie");
    num_of_events += h2001_2e->Integral("width");
    
    TH1D * h2001_3e = (TH1D *) fs->Get("2001x");
    num_of_events += 4 * h2001_3e->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 2001 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    
    //2002
    TH1D * h2002_1 = (TH1D *) fs->Get("2002e");
    num_of_events = h2002_1->Integral("width");
    
    TH1D * h2002_2 = (TH1D *) fs->Get("2002antie");
    num_of_events += h2002_2->Integral("width");
    
    TH1D * h2002_3 = (TH1D *) fs->Get("2002x");
    num_of_events += 4 * h2002_3->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 2002 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    
    TH1D * h2002_1e = (TH1D *) fs->Get("2002e");
    num_of_events = h2002_1e->Integral("width");
    
    TH1D * h2002_2e = (TH1D *) fs->Get("2002antie");
    num_of_events += h2002_2e->Integral("width");
    
    TH1D * h2002_3e = (TH1D *) fs->Get("2002x");
    num_of_events += 4 * h2002_3e->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 2002 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    
    //2003
    TH1D * h2003_1 = (TH1D *) fs->Get("2003e");
    num_of_events = h2003_1->Integral("width");
    
    TH1D * h2003_2 = (TH1D *) fs->Get("2003antie");
    num_of_events += h2003_2->Integral("width");
    
    TH1D * h2003_3 = (TH1D *) fs->Get("2003x");
    num_of_events += 4 * h2003_3->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 2003 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    
    TH1D * h2003_1e = (TH1D *) fs->Get("2003e");
    num_of_events = h2003_1e->Integral("width");
    
    TH1D * h2003_2e = (TH1D *) fs->Get("2003antie");
    num_of_events += h2003_2e->Integral("width");
    
    TH1D * h2003_3e = (TH1D *) fs->Get("2003x");
    num_of_events += 4 * h2003_3e->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 2003 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    
    //3001
    TH1D * h3001_1 = (TH1D *) fs->Get("3001e");
    num_of_events = h3001_1->Integral("width");
    
    TH1D * h3001_2 = (TH1D *) fs->Get("3001antie");
    num_of_events += h3001_2->Integral("width");
    
    TH1D * h3001_3 = (TH1D *) fs->Get("3001x");
    num_of_events += 4 * h3001_3->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 3001 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    
    TH1D * h3001_1e = (TH1D *) fs->Get("3001e");
    num_of_events = h3001_1e->Integral("width");
    
    TH1D * h3001_2e = (TH1D *) fs->Get("3001antie");
    num_of_events += h3001_2e->Integral("width");
    
    TH1D * h3001_3e = (TH1D *) fs->Get("3001x");
    num_of_events += 4 * h3001_3e->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 3001 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    //3002
    TH1D * h3002_1 = (TH1D *) fs->Get("3002e");
    num_of_events = h3002_1->Integral("width");
    
    TH1D * h3002_2 = (TH1D *) fs->Get("3002antie");
    num_of_events += h3002_2->Integral("width");
    
    TH1D * h3002_3 = (TH1D *) fs->Get("3002x");
    num_of_events += 4 * h3002_3->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 3002 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    
    TH1D * h3002_1e = (TH1D *) fs->Get("3002e");
    num_of_events = h3002_1e->Integral("width");
    
    TH1D * h3002_2e = (TH1D *) fs->Get("3002antie");
    num_of_events += h3002_2e->Integral("width");
    
    TH1D * h3002_3e = (TH1D *) fs->Get("3002x");
    num_of_events += 4 * h3002_3e->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 3002 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    
    //3003
    TH1D * h3003_1 = (TH1D *) fs->Get("3003e");
    num_of_events = h3003_1->Integral("width");
    
    TH1D * h3003_2 = (TH1D *) fs->Get("3003antie");
    num_of_events += h3003_2->Integral("width");
    
    TH1D * h3003_3 = (TH1D *) fs->Get("3003x");
    num_of_events += 4 * h3003_3->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 3003 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    
    TH1D * h3003_1e = (TH1D *) fs->Get("3003e");
    num_of_events = h3003_1e->Integral("width");
    
    TH1D * h3003_2e = (TH1D *) fs->Get("3003antie");
    num_of_events += h3003_2e->Integral("width");
    
    TH1D * h3003_3e = (TH1D *) fs->Get("3003x");
    num_of_events += 4 * h3003_3e->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 3003 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    
    //5001
    TH1D * h5001_1 = (TH1D *) fs->Get("5001e");
    num_of_events = h5001_1->Integral("width");
    
    TH1D * h5001_2 = (TH1D *) fs->Get("5001antie");
    num_of_events += h5001_2->Integral("width");
    
    TH1D * h5001_3 = (TH1D *) fs->Get("5001x");
    num_of_events += 4 * h5001_3->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 5001 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    
    TH1D * h5001_1e = (TH1D *) fs->Get("5001e");
    num_of_events = h5001_1e->Integral("width");
    
    TH1D * h5001_2e = (TH1D *) fs->Get("5001antie");
    num_of_events += h5001_2e->Integral("width");
    
    TH1D * h5001_3e = (TH1D *) fs->Get("5001x");
    num_of_events += 4 * h5001_3e->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 5001 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    //5002
    TH1D * h5002_1 = (TH1D *) fs->Get("5002e");
    num_of_events = h5002_1->Integral("width");
    
    TH1D * h5002_2 = (TH1D *) fs->Get("5002antie");
    num_of_events += h5002_2->Integral("width");
    
    TH1D * h5002_3 = (TH1D *) fs->Get("5002x");
    num_of_events += 4 * h5002_3->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 5002 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    
    TH1D * h5002_1e = (TH1D *) fs->Get("5002e");
    num_of_events = h5002_1e->Integral("width");
    
    TH1D * h5002_2e = (TH1D *) fs->Get("5002antie");
    num_of_events += h5002_2e->Integral("width");
    
    TH1D * h5002_3e = (TH1D *) fs->Get("5002x");
    num_of_events += 4 * h5002_3e->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 5002 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    
    
    //5003
    TH1D * h5003_1 = (TH1D *) fs->Get("5003e");
    num_of_events = h5003_1->Integral("width");
    
    TH1D * h5003_2 = (TH1D *) fs->Get("5003antie");
    num_of_events += h5003_2->Integral("width");
    
    TH1D * h5003_3 = (TH1D *) fs->Get("5003x");
    num_of_events += 4 * h5003_3->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 5003 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    
    
    
    TH1D * h5003_1e = (TH1D *) fs->Get("5003e");
    num_of_events = h5003_1e->Integral("width");
    
    TH1D * h5003_2e = (TH1D *) fs->Get("5003antie");
    num_of_events += h5003_2e->Integral("width");
    
    TH1D * h5003_3e = (TH1D *) fs->Get("5003x");
    num_of_events += 4 * h5003_3e->Integral("width");
    
    std::cout<<"The num of events in 20 seconds for 5003 is "<<num_of_events<<" ton-1"<<std::endl;
    std::cout<<"For PandaX-4T, the number of events in 20 seconds is  "<< 4*num_of_events<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    std::cout<<" "<<std::endl;
    
    return 1;
}
