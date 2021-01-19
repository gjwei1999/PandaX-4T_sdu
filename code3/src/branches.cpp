/*****************************/
/*                                                      */
/*       Created by Jiawei Guo          */
/*        Shandong University            */
/*                                                      */
/*****************************/

#include "branches.hpp"

Branches::Branches(){};
Branches::~Branches(){};

Branches::Branches(const std::shared_ptr<TChain> &input_tree){
    
    tree = input_tree;
    Branches::init();
    
}

void Branches::init(){
    
    energy = 0;
    nQuanta = 0;
    Nex = 0;
    Ni = 0;
    Nph = 0;
    Ne = 0;
    NphRec = 0;
    NeRec = 0;
    Ly = 0;
    Qy = 0;
    S1 = 0;
    S1d = 0;
    s1r = 0;
    nHitsS1 = 0;
    nHitsS1eff = 0;
    S2 = 0;
    S2d = 0;
    s2r = 0;
    S2B = 0;
    S2Bd = 0;
    s2r_b = 0;
    dt = 0;
    y = 0;
    x = 0;
    lifetime = 0;
    
    tree->SetBranchStatus("*", 0);
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
    
}

double Branches::get_energy(int i){
    if(i >= energy->size())
        return NAN;
    else
        return energy->at(i);
}

int Branches::get_nQuanta(int i){
    if(i >= energy->size())
        return -999;
    else
        return nQuanta->at(i);
    }

int Branches::get_Nex(int i){
    if(i >= energy->size())
        return -999;
    else
        return Nex->at(i);
    }

int Branches::get_Ni(int i){
    if(i >= energy->size())
        return -999;
    else
        return Ni->at(i);
    }

int Branches::get_Nph(int i){
    if(i >= energy->size())
        return -999;
    else
        return Nph->at(i);
    }

int Branches::get_Ne(int i){
    if(i >= energy->size())
        return -999;
    else
        return Ne->at(i);
    }
       
double Branches::get_NphRec(int i){
    if(i >= energy->size())
        return NAN;
    else
        return NphRec->at(i);
    }

double Branches::get_NeRec(int i){
    if(i >= energy->size())
        return NAN;
    else
        return NeRec->at(i);
    }

double Branches::get_Ly(int i){
    if(i >= energy->size())
        return NAN;
    else
        return Ly->at(i);
    }

double Branches::get_Qy(int i){
    if(i >= energy->size())
        return NAN;
    else
        return Qy->at(i);
    }
double Branches::get_S1(int i){
    if(i >= energy->size())
        return NAN;
    else
        return S1->at(i);
    }

double Branches::get_S1d(int i){
    if(i >= energy->size())
        return NAN;
    else
        return S1d->at(i);
    }

double Branches::get_s1r(int i){
    if(i >= energy->size())
        return NAN;
    else
        return s1r->at(i);
    }

int Branches::get_nHitsS1(int i){
    if(i >= energy->size())
        return -999;
    else
        return nHitsS1->at(i);
    }

int Branches::get_nHitsS1eff(int i){
    if(i >= energy->size())
        return -999;
    else
        return nHitsS1eff->at(i);
    }

double Branches::get_S2(int i){
    if(i >= energy->size())
        return NAN;
    else
        return S2->at(i);
    }

double Branches::get_S2d(int i){
    if(i >= energy->size())
        return NAN;
    else
        return S2d->at(i);
    }

double Branches::get_s2r(int i){
    if(i >= energy->size())
        return NAN;
    else
        return s2r->at(i);
    }

double Branches::get_S2B(int i){
    if(i >= energy->size())
        return NAN;
    else
        return S2B->at(i);
    }

double Branches::get_S2Bd(int i){
    if(i >= energy->size())
        return NAN;
    else
        return S2Bd->at(i);
    }

double Branches::get_s2r_b(int i){
    if(i >= energy->size())
        return NAN;
    else
        return s2r_b->at(i);
    }

double Branches::get_dt(int i){
    if(i >= energy->size())
        return NAN;
    else
        return dt->at(i);
    }

double Branches::get_y(int i){
    if(i >= energy->size())
        return NAN;
    else
        return y->at(i);
    }

double Branches::get_x(int i){
    if(i >= energy->size())
        return NAN;
    else
        return x->at(i);
    }

double Branches::get_lifetime(int i){
    if(i >= energy->size())
        return NAN;
    else
        return lifetime->at(i);
    }


