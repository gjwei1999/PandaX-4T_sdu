/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#include "branches.hpp"

Branches::Branches(){};
Branches::~Branches(){};

//Branches::Branches(const std::shared_ptr<TChain> &input_tree){
//Branches::Branches(TTree *input_tree){
//    
//    tree = input_tree;
//    Branches::init();
//   
//}

void Branches::init(TTree *tree){
    
    tree->SetBranchAddress("energy", &energy);
    tree->SetBranchAddress("nQuanta", &nQuanta);
    tree->SetBranchAddress("nExcitation", &Nex);
    tree->SetBranchAddress("nIonization", &Ni);
    tree->SetBranchAddress("nPhoton", &Nph);
    tree->SetBranchAddress("nElectron", &Ne);
    tree->SetBranchAddress("nPhotonRec", &NphRec);
    tree->SetBranchAddress("nElectronRec", &NeRec);
    tree->SetBranchAddress("Ly",&Ly);
    tree->SetBranchAddress("Qy",&Qy);
    tree->SetBranchAddress("S1", &S1);
    tree->SetBranchAddress("S1d", &S1d);
    tree->SetBranchAddress("S1dr", &s1r);
    tree->SetBranchAddress("nHitsS1", &nHitsS1);
    tree->SetBranchAddress("nHitsS1eff", &nHitsS1eff);
    tree->SetBranchAddress("S2", &S2);
    tree->SetBranchAddress("S2d", &S2d);
    tree->SetBranchAddress("S2dr", &s2r);
    tree->SetBranchAddress("S2B", &S2B);
    tree->SetBranchAddress("S2Bd", &S2Bd);
    tree->SetBranchAddress("S2Bdr", &s2r_b);
    tree->SetBranchAddress("dt", &dt);
    tree->SetBranchAddress("y", &y);
    tree->SetBranchAddress("x", &x);
    tree->SetBranchAddress("lifetime", &lifetime);
    tree->SetBranchAddress("event_time", &event_time);
    tree->SetBranchAddress("total_time", &total_time);
    
}

double Branches::get_energy(){
        return energy;
}

int Branches::get_nQuanta(){
        return nQuanta;
    }

int Branches::get_Nex(){
        return Nex;
    }

int Branches::get_Ni(){
        return Ni;
    }

int Branches::get_Nph(){
        return Nph;
    }

int Branches::get_Ne(){
        return Ne;
    }
       
double Branches::get_NphRec(){
        return NphRec;
    }

double Branches::get_NeRec(){
        return NeRec;
    }

double Branches::get_Ly(){
        return Ly;
    }

double Branches::get_Qy(){
        return Qy;
    }
double Branches::get_S1(){
        return S1;
    }

double Branches::get_S1d(){
        return S1d;
    }

double Branches::get_s1r(){
        return s1r;
    }

int Branches::get_nHitsS1(){
        return nHitsS1;
    }

int Branches::get_nHitsS1eff(){
        return nHitsS1eff;
    }

double Branches::get_S2(){
        return S2;
    }

double Branches::get_S2d(){
        return S2d;
    }

double Branches::get_s2r(){
        return s2r;
    }

double Branches::get_S2B(){
        return S2B;
    }

double Branches::get_S2Bd(){
        return S2Bd;
    }

double Branches::get_s2r_b(){
        return s2r_b;
    }

double Branches::get_dt(){
        return dt;
    }

double Branches::get_y(){
        return y;
    }

double Branches::get_x(){
        return x;
    }

double Branches::get_lifetime(){
        return lifetime;
    }

double Branches::get_event_time(){
        return event_time;
    }
    
int Branches::get_total_time(){
    return total_time;
}

