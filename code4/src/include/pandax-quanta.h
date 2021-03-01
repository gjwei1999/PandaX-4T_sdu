#pragma once

#include "general.h"

#include <TF1.h>
#include <TGraph.h>

namespace pandax {

struct QuantaResult {
    int Ni;
    int Nex;
    int Nph;
    int Ne;
    int Nq;
};

class PandaXQuanta {
  public:
    PandaXQuanta(double f = 400);
    void calculate(double e, EnergyType type = EnergyType::ELECTRON);
    QuantaResult getQuanta() const { return quanta; }

    double get_eee() const { return eee; }
		double CriticalFluc(double ec=2.5);
		void SetParaYield(TGraph *qy1,TGraph *ly1);
    void SetParaFluc(TGraph *qy_fluc);
		void TuneLH(){soldier=1;};
  private:
    void calculate0(double e);
    //void calculate_nr(double e);

    // functions to calculate the quanta in x region
    void calculate_erx(double e);
    void calculate_nrx(double e);
		bool soldier{false};
    EnergyType type0;
    QuantaResult quanta;
    TF1 *yield_charge;
    TF1 *yield_light;
    TF1 *ratio;
		TF1 *yield_charge_fluc;
    double field;
		int run;
		double var_c;
		TGraph *yield_charge_fluc_gr;
    // ratio for the light yield of x events.
    TGraph *er_ly_ratio_x;
    TGraph *nr_ly_ratio_x;
		int graph=1;
		int fluc_graph=0;
		TGraph *yield_charge_g;
		TGraph *yield_light_g;

    double eee;
};
}
