#ifndef BRANCHES_H
#define BRANCHES_H

#include <iostream>
#include <vector>
#include "TTree.h"

using v_int = std::vector<int> *;
using v_double = std::vector<double> *;

class Branches12 {
    
private:
    TTree * tree;
    
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
    ~Branches();
    
    Branches(const TTree * input_tree);
    void init();
    
    double energy(int i);
    int nQuanta(int i);
    int Nex(int i);
    int Ni(int i);
    int Nph(int i);
    int Ne(int i);
    double NphRec(int i);
    double NeRec(int i);
    double Ly(int i);
    double Qy(int i);
    double S1(int i);
    double S1d(int i);
    double s1r(int i);
    int nHitsS1(int i);
    int nHitsS1eff(int i);
    double S2(int i);
    double S2d(int i);
    double s2r(int i);
    double S2B(int i);
    double S2Bd(int i);
    double s2r_b(int i);
    double dt(int i);
    double y(int i);
    double x(int i);
    double lifetime(int i);
    

}
    
