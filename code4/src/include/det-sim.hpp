#pragma once

#include <TF1.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TObject.h>
using namespace std;


class DetSim{


  public:

    TF1 *s1_mapping;
    TF1 *s2_mapping;
    DetSim(double v_pde = 0.1048, double v_eee = 0.5115, double v_seg = 20.95,
        double v_bottom_s2_fraction = 1.0 / 3.365, double dpef = 0.215,
        double pmt_res = 0.6, bool zle = true, int runNo = 10)
      : pde{v_pde}, eee{v_eee}, seg{v_seg},
      bottom_s2_fraction{v_bottom_s2_fraction}, dpe_fraction{dpef},
      pmt_resolution{pmt_res}, e_lifetime{1000}, enableZLE{zle},
      run{runNo}
    {
      calculate_f0();

      s2_zle_fluc_l->SetParameters(-0.0360916,0.00890481);
      s2_zle_fluc_h->SetParameters(-0.0143895,-162.854,0.0231579,
          0.939061,-0.214081,685.473);
      s1_zle_fluc_0->SetParameters(-0.137185,0.0210415,-0.00112973);
      if (run==401)
      {
        //s1 zle fluctuation
        s1_zle_fluc=new TF1("s1_zle_fluc","[0]*exp(-x/[1])+[2]",0,300);
        s1_zle_fluc->SetParameters(0.083748,16.4135,0.0207104);
        //s2 zle fluctuation
        s2_zle_fluc=new TF1("s2_zle_fluc","[0]*pow(x,[1])+[2]",0,50000);

        s2_zle_fluc->SetParameters(2.80879, -1.11957, 0.00428969);
        //s1 zle
        //s1_mapping=new TF1("s1_mapping","[&](double *x,double *par){ double x1=x[0]; double zle= s1_mapping_0->Eval(x1);double ratio=par[0]; return (zle+ratio)/(1+ratio)*x1;}",0,300,1);
        //s1_mapping->SetParameter(0,1.);
        s1_mapping=new TF1("s1_mapping","x * ([2]/(1+exp(-(x-[0])/[1]))+[3])",0,500);
        s1_mapping->SetParameters(-12.71, 4.848, 5.303, -4.371);
    

        //s2 zle
        s2_mapping=new TF1("s2_mapping","x * ([2]/(1+exp(-(x-[0])/[1]))+[3])",0,50000);
        s2_mapping->SetParameters(-3358, 779.5, 1.515, -0.5572);
        s1_s2b_frac->SetParameters(0.02018,0.000);
      }
      else if (run ==10) {
        t_drift_ll=50;
        t_drift_ul=350;

        s1_zle_fluc=(TF1*)s1_zle_fluc_0->Clone();
        s1_mapping_0->SetParameter(0,56.99);

        s1_1=60;
        s1_2=200;
        double yl=s1_mapping_0->Eval(s1_1);
        double yu=s1_mapping_0->Eval(s1_2);
        double par1=1.*(yu-yl)/(log(s1_2/s1_1));
        double par0=yu-par1*log(s1_2);
        s1_m_mapping->SetParameters(par0,par1);

        s1_mapping=new TF1("s1_mapping","[&](double *x,double *par){if (x[0]>60 &&x[0]<200) return x[0]*s1_m_mapping->Eval(x[0]); else return x[0]*s1_mapping_0->Eval(x[0]);}",0,500,0);

        s2_zle_fluc=new TF1("s2_zle_fluc","[&](double *x,double *p){ return sqrt(pow(s2_zle_fluc_h->Eval(x[0])*(56.99-50.94)/(57.33-50.94),2) + pow(s2_zle_fluc_l->Eval(x[0])*( 1 - (56.99-50.94)/(57.33-50.94) ),2));}",0,40000,0);
        s2_mapping=(TF1*)s2_mapping_0->Clone();
        s2_mapping->SetParameter(0,56.99);

      } else if(run==11) {
        s1_zle_fluc=(TF1*)s1_zle_fluc_0->Clone();
        fs1_eff=new TF1("fs1_eff","1.",0,500);
        s1_mapping_0->SetParameter(0,55.92);

        //smoothening s1 mapping
        s1_1=60;
        s1_2=200;
        double yl=s1_mapping_0->Eval(s1_1);
        double yu=s1_mapping_0->Eval(s1_2);
        double par1=1.*(yu-yl)/(log(s1_2/s1_1));
        double par0=yu-par1*log(s1_2);
        s1_m_mapping->SetParameters(par0,par1);

        s1_mapping=new TF1("s1_mapping","[&](double *x,double *par){if (x[0]>60 &&x[0]<200) return x[0]*s1_m_mapping->Eval(x[0])*par[0]; else return x[0]*s1_mapping_0->Eval(x[0])*par[0];}",0,500,1);
        s1_mapping->SetParameter(0,1.);
        //std::cout<<"check zle s1 "<<s1_mapping->Eval(59)<<s1_mapping->Eval(61)<<std::endl;

        s2_zle_fluc=new TF1("s2_zle_fluc","[&](double *x,double *p){ return 0.5*sqrt(pow(s2_zle_fluc_h->Eval(x[0])*(55.92-50.94)/(57.33-50.94),2) + pow(s2_zle_fluc_l->Eval(x[0]) * ( 1 - (56.99-50.94)/(57.33-50.94) ),2));}",0,40000,0);
        s2_mapping_0->SetParameter(0,55.92);
        s2_mapping=new TF1("s2_mapping","[&](double *x,double *par){  return s2_mapping_0->Eval(x[0])*par[0];}",0,30000,1);
        s2_mapping->SetParameter(0,1.);
      }
      else if(run==9){
        fs1_eff=new TF1("fs1_eff","1.",0,500);

        //sl zle
        s1_mapping_0 = new TF1("s1_mapping_0",
            " ( ((0.91+0.00032* x-3.3e-7 * x * x) "
            "- (0.89 + 3.8e-4 * x-4.1e-7 * x * x))/(57.33-50.94)*([0]-50.94) "
            "+ (0.89 + 3.8e-4 * x-4.1e-7 * x * x) )",0,500);
        s1_mapping_0->SetParameter(0,57.33);
        s1_mapping=new TF1("s1_mapping","[&](double *x,double *par){ double x1=x[0]*(1+(par[0]-57.33)/57.33) ; double zle= s1_mapping_0->Eval(x1);double ratio=par[1]; return (zle+ratio)/(1+ratio)*x[0];}",0,300,2);
        s1_mapping->SetParameter(0,82);
        s1_mapping->SetParameter(1,1.);

        //s1 zle fluctuation
        s1_zle_fluc=new TF1("s1_zle_fluc","[&](double *x,double *p) { double x1=x[0]*(1+(p[0]-57.33)/57.33) ; if(x1>90) return  s1_zle_fluc_0->Eval(90)*p[1]; else return s1_zle_fluc_0->Eval(x1) *p[1];}",0,300,2);
        s1_zle_fluc->SetParameter(0,82);
        s1_zle_fluc->SetParameter(1,0.4);

        //s2 zle
        s2_mapping_0->SetParameter(0,57.33);
        s2_mapping=new TF1("s2_mapping","[&](double *x,double *par){ double x1=x[0]*(1+(par[0]-57.33)/57.33) ; return s2_mapping_0->Eval(x1)/x1*x[0];}",0,30000,1);
        s2_mapping->SetParameter(0,82);

        //s2 zle fluctuation
        s2_zle_fluc=new TF1("s2_zle_fluc","[&](double *x,double *p) { double x1=x[0]*(1+(p[0]-57.33)/57.33) ; return s2_zle_fluc_h->Eval(x1) ;}",0,40000,1);
        s2_zle_fluc->SetParameter(0,82);



      }
      std::vector<double> values{
        23508.5, 23983,   23267.1, 24499.9, 22626.5, 29660.8, 27169,
          27104.2, 23760.1, 24858.4, 24460.1, 30933.7, 31220.3, 32306.5,
          26470,   21928.6, 23482.4, 29862,   32964.9, 29816.9, 33752.5,
          32066.3, 28660.8, 23353.5, 24506.8, 24675.8, 24512.2, 22759.7,
          27419.7, 29658.3, 29282,   26312.7, 21905,   21231.3, 27462,
          28522.4, 0,       28357,   26963.4, 21065.2, 23790.3, 27958.5,
          31761.6, 31435.8, 31455.9, 31179.5, 29703.8, 32711.9, 27117.3,
          32284,   34907,   0,       32950.3, 30578.8, 26859.3, 0,
          8948.73, 6982.27, 9214.16, 10432,   8765.52, 10902.9, 10308.2,
          8309.22, 8209.99, 10562.9, 10072.6, 12481.2, 11802.7, 10465.2,
          0,       6924.69, 11284.8, 12185.2, 12374,   11235,   11627.9,
          10914,   8056.52, 7662.31, 0,       7749.29, 0,       9673.81,
          9360.73, 9078.94, 10561.2, 7306.12, 7869.56, 10051.8, 9445.94,
          10134.6, 9573.36, 11011.2, 8786.5,  7899.14, 9601.85, 10665.7,
          11867.2, 12757.8, 0,       10281,   7149.81, 9239.96, 11540.5,
          13380.3, 13049.3, 12284.2, 10684.4, 9792.49};
      histo_pmt_hit_ratio = new TH1F("histo_pmt_hit_ratio", "", 110, 0, 110);
      for (int i = 0; i < 110; ++i) {
        histo_pmt_hit_ratio->SetBinContent(i + 1, values[i]);
      }
    }
    double get_s1() { return s1; }
    double get_s2() { return s2; }
    double get_s2b() { return s2b; }
    int get_nhits_s1() { return nhits_s1; }
    double get_s1_det() { return s1_d; }
    double get_s2_det() { return s2_d; }
    double get_s1_det_r() { return s1_d_r; }
    double get_s2_det_r() { return s2_d_r; }
    double get_s2b_det_r() { return s2b_d_r; }
    double get_s2b_det() { return s2b_d; }
    int get_nhits_s1_eff() { return nhits_s1_eff; }
    double get_drift_time() { return drift_time; }

    void calculate(int n_photon, int n_electron, double dt = 0,double x=0,double y=0);

    void set_pde(double v) { pde = v; }
    void set_eee(double v) { eee = v; }
    void set_seg(double v) { seg = v; }
    void set_bottom_s2_fraction(double v) { bottom_s2_fraction = v; }
    void set_dpe_fraction(double v) {
      dpe_fraction = v;
      calculate_f0();
    }
    void set_e_lifetime(double v) { e_lifetime = v; }
    void set_t_drift_lower_limit(double v) { t_drift_ll = v; }
    void set_t_drift_upper_limit(double v) { t_drift_ul = v; }
    void set_2dmap(TH2F* h2){hmap=(TH2F*)h2->Clone("hmap");hmap->SetDirectory(0);}

    auto get_s1_zle_mapping() { return s1_mapping; }

    auto get_s2_zle_mapping() { return s2_mapping; }

    void set_delta_s1_zle_mapping( double delta) {s1_mapping->SetParameter(3, s1_mapping->GetParameters()[3] - delta); }

    void set_delta_s2_zle_mapping( double delta) {s2_mapping->SetParameter(3, s2_mapping->GetParameters()[3] - delta); }

  private:
    // functions
    void calculate_f0() { f0 = 1 - pde / (1 + dpe_fraction); }
    void calculate_nhit_s1(const int i_photon);
    // values
    double pde;
    double eee;
    double seg;
    double bottom_s2_fraction;
    double dpe_fraction;
    double pmt_resolution;
    double e_lifetime;       // in microseconds
    double t_drift_ll = 50;  // lower limit of the drift time
    double t_drift_ul = 350; // upper limit of the drift time

    //horizontal-dependent S2 correction
    TH2F *hmap=0x0;

    // ZLE correction mapping
    //parameter [0] is the average gain
    TF1 *s1_mapping_0 = new TF1("s1_mapping_0"," ((x < 5)*0.896797 + "
        "(x >= 5) * (x<100)*((0.884+5.284e-4 * x +5.12*exp(-x/0.83)"
        "- 1.65 + 2.16e-3 * x + 0.8*exp(-x/ 221.73))/(57.33-50.94)*([0]-50.94) + "
        "1.65 - 2.16e-3 * x - 0.8*exp(-x/ 221.73)) +"
        " (x>=100)*( ((0.91+0.00032* x-3.3e-7 * x * x) "
        "- (0.89 + 3.8e-4 * x-4.1e-7 * x * x))/(57.33-50.94)*([0]-50.94) "
        "+ (0.89 + 3.8e-4 * x-4.1e-7 * x * x) ))",0,500);
    TF1 *s1_m_mapping=new TF1("s1_m_mapping","[0]+[1]*log(x)",0,500);
    TF1 *s1_zle_fluc;
    TF1 *s1_zle_fluc_0= new TF1("s1_zle_fluc_0","sqrt(2)*([0]+[1]*x/10+[2]*x*x/100)",0,500);
    TF1 *fs1_eff=new TF1("fs1_eff","1./(1+exp(-1.*(x-[0])/[1]))",0,500);



    TF1 *s2_mapping_0 = new TF1("s2_mapping_0",
        "x*((x<2000)*((9.36075e-01+1.46127e-05 * x - 9.74033e-02*exp(-x/1.65847e+02 ) - "
        "(9.46711e-01 + 1.00317e-05 * x-4.31553e-02 *exp(-x/7.89394e+02)))/(57.33 - "
        "50.94)*([0]-50.94) + 9.46711e-01 + 1.00317e-05 * x-4.31553e-02 *exp(-x/7.89394e+02))"
        "+ (x>=2000)*( ( (9.55499e-01+ 4.29635e-06 *x -1.86286e-10*x*x + 2.84726e-15*x*x*x)-"
        "(9.52376e-01 + 5.29824e-06*x - 2.73293e-10*x*x + 4.70769e-15*x*x*x))/ (57.33-50.94)*([0]-50.94)*0.99"
        "+ (9.52376e-01 + 5.29824e-06*x - 2.73293e-10*x*x + 4.70769e-15*x*x*x)))",0,50000);
    TF1 *s2_zle_fluc_l=new TF1("s2_zle_fluc_l","[0]+[1]*x/1000",0,40000);
    TF1 *s2_zle_fluc_h=new TF1("s2_zle_fluc_h", "(x>300)*([0]+[1]/(1+pow(x/[2],[3]))) + (x<=300)*([4]*exp(-1*x/[5])-0.035589821+0.13819980)",0,40000);
    TF1 *s2_zle_fluc;

    TF1 *s1_s2b_frac=new TF1("s1_s2b_frac","(x < 30 )* ([0]+[1]*x) + (x>=30) * ([0]+[1]*30)",0,500);
    

    TH1F *histo_pmt_hit_ratio;

    ///////////////////////
    double s1_1{60};
    double s1_2{200};
    double f0;         //  the probability of 0 PE emission
    double s1;         //  s1 without ZLE correction
    double s2;         //  s2 without ZLE correction
    double s2b;        //  s2b without ZLE correction
    double s1_d;       // s1 detected
    double s2_d;       // s2 detected
    double s2b_d;      // s2b detected
    double s1_d_r;  	 //reversely constructed s1d
    double s2_d_r;  	 //reversely constructed s2d
    double s2b_d_r;  	 //reversely constructed s2Bd
    int run;
    bool enableZLE;

    double drift_time; // the drift time
    int nhits_s1;      // nhit of s1
    int nhits_s1_eff;  // nhits of s1 with zle correction
    double map_mean;


};


