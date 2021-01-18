#include "pandax-quanta.h"

#include <TRandom.h> // for gRandom
using namespace std;

namespace pandax {

  double lyFunc_11(double * xx,double* par){
    double x=xx[0];
    double xc=18;
    double xc2=0.8;
    double yield_charge_temp=0;
    if (x>xc){
      double yield_charge_temp_critical=par[0] + par[1] / (1 + pow(xc / par[2], par[3]));
      yield_charge_temp= yield_charge_temp_critical;
    }
    else if (x>xc2){
      yield_charge_temp=par[0] + par[1] / (1 + pow(x / par[2], par[3]));
    }
    else {
      double b=-8.;
      double critical_0 = b *xc2;
      double critcal = par[0] + par[1] / (1 + pow(xc2 / par[2], par[3]));
      yield_charge_temp = b * x - critical_0 + critcal;
    }
    double ly = 1./0.0137-0.975*yield_charge_temp;
    return ly;

  }



  PandaXQuanta::PandaXQuanta(double f)
    : yield_charge{new TF1("cy", "[0] + [1] / (1 + pow(x / [2], [3]))", 0.1, 40)},
    ratio{new TF1("ratio", "[0] * erf([1] * x)", 0.1, 25)}, field{f},
    yield_charge_fluc{new TF1("nr_fluc","[0] + [1] / (1 + pow(x / [2], [3]))",0.1,25)},
    er_ly_ratio_x{nullptr}, nr_ly_ratio_x{nullptr} {

      yield_light=new TF1("yield_light", lyFunc_11, 0.1, 40,4);
      yield_light->SetParameters(1.66401e+01,1.59913e+05,4.00184e-07,5.66834e-01);

      ratio->SetParameters(1.2, 0.05);
      yield_charge_fluc->SetParameters(54.3919,-128.056,0.511504,0.0733625);
      // light ratio
      double e1[62];
      double e2[30];
      for (int i = 0; i < 30; ++i) {
        e2[i] = i + 1.0;
      }
      for (int i = 0; i < 62; ++i) {
        e1[i] = 0.6 + i * 0.4;
      }
      double ratio_er[62] = {
        1.800736581, 1.221377491, 1.00373063,  0.912352754, 0.871516732,
        0.854196221, 0.848511832, 0.848463235, 0.850747251, 0.853460835,
        0.855497085, 0.856233337, 0.855356914, 0.852761752, 0.848483861,
        0.842658624, 0.835490186, 0.827227159, 0.818141399, 0.808508532,
        0.7985903,   0.788619759, 0.778790597, 0.769251548, 0.760106044,
        0.751416334, 0.743210628, 0.735491552, 0.728244394, 0.721444119,
        0.715060688, 0.709062654, 0.703419349, 0.69810201,  0.693084236,
        0.688342056, 0.683853801, 0.6795999,   0.675562655, 0.671726031,
        0.668075468, 0.664597714, 0.661280681, 0.658113316, 0.655085498,
        0.652187938, 0.649412097, 0.646750113, 0.644194735, 0.641739268,
        0.63937752,  0.637103761, 0.634912677, 0.63279934,  0.630759171,
        0.628787914, 0.626881611, 0.625036575, 0.623249369, 0.621516792,
        0.619835853, 0.618203762};
      double ratio_nr[30] = {
        0.895226283, 0.9086133,   0.917436059, 0.92365137,  0.928265836,
        0.931840943, 0.934711849, 0.937089334, 0.939111383, 0.94087118,
        0.942433202, 0.943842942, 0.945133021, 0.946327153, 0.947442793,
        0.948492941, 0.949487398, 0.950433639, 0.951337447, 0.952203355,
        0.953034976, 0.953835234, 0.954606536, 0.955350902, 0.956070051,
        0.956765472, 0.957438478, 0.958090235, 0.958721799, 0.959334131};
      er_ly_ratio_x = new TGraph(62, e1, ratio_er);
      nr_ly_ratio_x = new TGraph(30, e2, ratio_nr);

      double e_nrer_10[]={0.2,
        0.4,0.6,0.8,1,1.2,
        1.4,1.6,1.8,2,2.2,
        2.4,2.6,2.8,3,3.2,
        3.4,3.6,3.8,4,4.2,
        4.4,4.6,4.8,5,5.2,
        5.4,5.6,5.8,6,6.2,
        6.4,6.6,6.8,7,7.2,
        7.4,7.6,7.8,8,8.2,
        8.4,8.6,8.8,9,9.2,
        9.4,9.6,9.8,10,10.2,
        10.4,10.6,10.8,11,11.2,
        11.4,11.6,11.8,12,12.2,
        12.4,12.6,12.8,13,13.2,
        13.4,13.6,13.8,14,14.2,
        14.4,14.6,14.8,15,15.2,
        15.4,15.6,15.8,16,16.2,
        16.4,16.6,16.8,17,17.2,
        17.4,17.6,17.8,18,18.2,
        18.4,18.6,18.8,19,19.2,
        19.4,19.6,19.8};
      double e_qy_10[]={42.0019,
        37.3528,34.6314,32.7001,30.5899,28.8018,
        27.8072,26.9457,26.1857,24.4092,23.8207,
        23.6282,23.4357,23.2431,22.7999,22.3851,
        21.9956,21.6284,21.281,20.9515,20.6381,
        20.3392,20.0536,19.7802,19.518,19.2662,
        19.0237,18.7901,18.5648,18.347,18.1365,
        17.9326,17.735,17.5433,17.3572,17.1763,
        17.0004,16.8292,16.6624,16.4999,16.3413,
        16.1867,16.0356,15.888,15.7438,15.6027,
        15.4647,15.3296,15.1973,15.0675,14.9406,
        14.8159,14.6936,14.5738,14.4559,14.3404,
        14.2268,14.1152,13.9732,13.8313,13.6894,
        13.5475,13.4055,13.2636,13.1217,13.0257,
        12.9312,12.838,12.7462,12.6557,12.5665,
        12.4786,12.3918,12.3063,12.2219,12.1386,
        12.0564,11.9753,11.8952,11.8161,11.738,
        11.6609,11.5847,11.5094,11.435,11.3615,
        11.2888,11.217,11.146,11.0758,11.0063,
        10.9376,10.8697,10.8024,10.7359,10.6701,
        10.605,10.5406,10.4768};

      int N10=sizeof(e_nrer_10)/sizeof(e_nrer_10[0]);
      yield_charge_g = new TGraph(N10,e_nrer_10,e_qy_10);
    }

  void PandaXQuanta::SetParaYield(TGraph *qy1,TGraph *ly1){
    graph=1;
    yield_charge_g=(TGraph*)qy1->Clone("qy");
    yield_light_g=(TGraph*)ly1->Clone("ly");
  }

  void PandaXQuanta::SetParaFluc(TGraph *qy_fluc){
    fluc_graph=1;
    yield_charge_fluc_gr=(TGraph *)qy_fluc->Clone("yield_charge_fluc_gr");

  }


  void PandaXQuanta::calculate(double e, EnergyType type) {
    type0 = type;
    if (type == EnergyType::ELECTRON || type == EnergyType::GAMMA) {
      calculate0(e);
    } else if (type == EnergyType::NR) {
      calculate0(e);
    } else if (type == EnergyType::ERX) {
      calculate_erx(e);
    } else if (type == EnergyType::NRX) {
      calculate_nrx(e);
    }
  }



  double lindhard(double e) {
    double epsilon = 11.5 * e * pow(54, -7.0 / 3);
    double gamma = 3 * pow(epsilon, 0.15) + 0.7 * pow(epsilon, 0.6) + epsilon;

    double kappa = 0.1394;
    return kappa * gamma / (1 + kappa * gamma);
  }

  double lindhard_tune(double e)
  {
    return exp(-1.*e/14.5329) * 0.49201 + 0.208898;
    //return exp(-1.*e/12) * 0.3 + 0.209;
  }

  double lindhard_x(double e) {
    return 0.0611 + 0.00482 * e - 0.0002415 * e * e + 5.53035e-6 * e * e * e -
      6.759e-8 * e * e * e * e + 4.600e-10 * e * e * e * e * e -
      1.644e-12 * e * e * e * e * e * e +
      2.409e-15 * e * e * e * e * e * e * e;
  }

  double lindhard_try(double e) { return 0.0223 * 0.8 * log(e * 7.278 + 11.795); }

  double lindhard_mu(double e) {
    return exp(-0.033 * pow(e, -0.958)) / (1 + 13.789 * pow(e, -0.189));
  }

  void PandaXQuanta::calculate0(double e) {
    // double l = lindhard(e);
    if (type0 == EnergyType::NR) 
    {
      e = (double) gRandom->Gaus(e, 0.5*sqrt(e));
      if (e<0) e=0;
      //if(soldier)
      //  e = e * lindhard_tune(e);
      //else
      //e = e*0.215;
       e = e*lindhard(e)*0.94;
    }
    eee = e;
    int nq = int(e / kW);
    nq = (int)gRandom->Gaus(nq, sqrt(nq * 0.0034));
    //if(type0 == EnergyType::NR)
    //{
    //  nq = (int)gRandom->Gaus(nq, sqrt(nq));
    //  if(nq<0) nq=0;
    //}
    if (nq<0){
      nq=0;
      return;
    }

    int nex=0;
    int ni=0;

    //
    double var_r;
    if (fluc_graph)
      var_r=TMath::Abs(yield_charge_fluc_gr->Eval(e))*e;
    else  var_r=TMath::Abs(yield_charge_fluc->Eval(e))*e;

    var_r *=0.4;

    int ne ;
    double yield_q=yield_charge_g->Eval(e);
    if (graph) {
      ne=int(gRandom->Gaus(yield_q * e,var_r));
    }
    else ne= int(gRandom->Gaus(yield_charge->Eval(e) * e, var_r));
    if (ne < 0)
      ne = 0;
    int nph = e*(1./kW) - ne;

    // fill the result
    quanta.Ni = ni;
    quanta.Nex = nex;
    quanta.Nph = nph;
    quanta.Ne = ne;
    quanta.Nq = nq;
  }

  void PandaXQuanta::calculate_erx(double e) {
    type0 = EnergyType::ELECTRON;
    calculate0(e);
    quanta.Ne = 0;
    quanta.Nph = quanta.Nph * er_ly_ratio_x->Eval(e, 0, "S");
  }

  void PandaXQuanta::calculate_nrx(double e) {
    type0 = EnergyType::NR;
    calculate0(e);
    quanta.Ne = 0;
    quanta.Nph = quanta.Nph * nr_ly_ratio_x->Eval(e, 0, "S");
  }
}
