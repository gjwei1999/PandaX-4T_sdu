/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#ifndef BRANCHES_H
#define BRANCHES_H

#include <iostream>
#include <vector>
#include "TChain.h"
#include "TTree.h"

class Branches {
    
private:
    //std::shared_ptr<TChain>  tree;
    //TTree *tree;
    
    double energy;
    int nQuanta;
    int Nex;
    int Ni;
    int Nph;
    int Ne;
    double NphRec;
    double NeRec;
    double Ly;
    double Qy;
    double S1;
    double S1d;
    double s1r;
    int nHitsS1;
    int nHitsS1eff;
    double S2;
    double S2d;
    double s2r;
    double S2B;
    double S2Bd;
    double s2r_b;
    double dt;
    double y;
    double x;
    double lifetime;
    double event_time;
    int total_time;
    
    
public:
    Branches();
    virtual ~Branches();
    
    //Branches(const std::shared_ptr<TChain> &input_tree);
    void init(TTree *tree);
    
    double get_energy();
    int get_nQuanta();
    int get_Nex();
    int get_Ni();
    int get_Nph();
    int get_Ne();
    double get_NphRec();
    double get_NeRec();
    double get_Ly();
    double get_Qy();
    double get_S1();
    double get_S1d();
    double get_s1r();
    int get_nHitsS1();
    int get_nHitsS1eff();
    double get_S2();
    double get_S2d();
    double get_s2r();
    double get_S2B();
    double get_S2Bd();
    double get_s2r_b();
    double get_dt();
    double get_y();
    double get_x();
    double get_lifetime();
    double get_event_time();
    int get_total_time();
    
};

#endif
