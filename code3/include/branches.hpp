/*****************************/
/*                                                      */
/*       Created by Jiawei Guo          */
/*        Shandong University            */
/*                                                      */
/*****************************/

#ifndef BRANCHES_H
#define BRANCHES_H

#include <iostream>
#include <vector>
#include "TChain.h"

using v_int = std::vector<int> *;
using v_double = std::vector<double> *;

class Branches {
    
private:
    TChain * tree;
    
    v_double energy;
    v_int nQuanta;
    v_int Nex;
    v_int Ni;
    v_int Nph;
    v_int Ne;
    v_double NphRec;
    v_double NeRec;
    v_double Ly;
    v_double Qy;
    v_double S1;
    v_double S1d;
    v_double s1r;
    v_int nHitsS1;
    v_int nHitsS1eff;
    v_double S2;
    v_double S2d;
    v_double s2r;
    v_double S2B;
    v_double S2Bd;
    v_double s2r_b;
    v_double dt;
    v_double y;
    v_double x;
    v_double lifetime;
    
    
public:
    Branches();
    virtual ~Branches();
    
    Branches(const std::shared_ptr<TChain> &input_tree);
    void init();
    
    double get_energy(int i);
    int get_nQuanta(int i);
    int get_Nex(int i);
    int get_Ni(int i);
    int get_Nph(int i);
    int get_Ne(int i);
    double get_NphRec(int i);
    double get_NeRec(int i);
    double get_Ly(int i);
    double get_Qy(int i);
    double get_S1(int i);
    double get_S1d(int i);
    double get_s1r(int i);
    int get_nHitsS1(int i);
    int get_nHitsS1eff(int i);
    double get_S2(int i);
    double get_S2d(int i);
    double get_s2r(int i);
    double get_S2B(int i);
    double get_S2Bd(int i);
    double get_s2r_b(int i);
    double get_dt(int i);
    double get_y(int i);
    double get_x(int i);
    double get_lifetime(int i);
    
};

#endif
