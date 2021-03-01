#include "det-sim.hpp"

#include <TRandom.h>

#include <map>
#include <vector>


void DetSim::calculate(int n_photon, int n_electron, double dt, double x,double y) {
    s1 = 0;
    s2 = 0;
    s2b = 0;
    s1_d = 0;
    s2_d = 0;
    s2b_d = 0;
    nhits_s1 = 0;
    nhits_s1_eff = 0;
    // s1
    int i_photon = gRandom->Binomial(n_photon, 1 - f0);
    if (i_photon <= 0)
        return;
    int i_photon_2 = gRandom->Binomial(i_photon, dpe_fraction);
    int i_pe = i_photon + i_photon_2;
    while (s1 <= 0)
        s1 = gRandom->Gaus(i_pe, pmt_resolution * sqrt(i_pe));
    // nhit s1 ?
    calculate_nhit_s1(i_photon);
	//	if(x&&y)std::cout<<"no x y dependecy counted"<<std::endl;

    // s2
    // 1. drift
    if (dt <1e-20) 
        drift_time = gRandom->Uniform(t_drift_ll, t_drift_ul);
    else
        drift_time = dt;
    double survive_rate = exp(-drift_time/e_lifetime);
    int n_electron_survive = gRandom->Binomial(n_electron, survive_rate);
    int i_electron = gRandom->Binomial(n_electron_survive, eee);

    if (i_electron <= 0)
      return;
    
    if(hmap)
    {
      double s2mean=i_electron * seg * hmap->Interpolate(x,y);
      //if (hmap->Interpolate(x,y)>1.8)cout<<" x y cymap "<<x<<"\t"<<y<<"\t"<<hmap->Interpolate(x,y)<<endl;
      s2=gRandom->Gaus(s2mean, pmt_resolution * sqrt(s2mean));
      // 2. correction for the electron lifetime.
      s2 /= survive_rate;
      //3. correction for horizontal nonuniformity.
      s2 /= hmap->Interpolate(x,y);
    }
    else
    {
      s2 = gRandom->Gaus(i_electron * seg, pmt_resolution * sqrt(i_electron * seg));
      // 2. correction for the electron lifetime.
      s2 /= survive_rate;
     }


    s2b = s2 * bottom_s2_fraction ;

    if (enableZLE)
    {
      double s1_mean_zle=s1_mapping->Eval(s1)/s1;
      double s1_sigma_zle=TMath::Abs(s1_zle_fluc->Eval(s1));
      if(s1_mean_zle>1)
        s1_mean_zle=1;
      double s1_zle_eff;
      if(s1>100){
        s1_sigma_zle = TMath::Abs(s1_zle_fluc->Eval(100)) ;
      }
      s1_zle_eff=-1;
      while(s1_zle_eff<0||s1_zle_eff>1)
        s1_zle_eff=gRandom->Gaus(s1_mean_zle,s1_sigma_zle);

      if(s1_zle_eff>=1)s1_zle_eff=1;
      //std::cout<<s1_mean_zle<<"\t"<<s1_sigma_zle<<"\t"<<s1_zle_eff<<"\t"<<s1<<"  s1_mean_zle s1_sigma_zle s1_zle_eff s1"<<std::endl;

      s1_d = s1 * s1_zle_eff;

      double s2_mean_zle=s2_mapping->Eval(s2)/s2;
      if(s2_mean_zle>1) s2_mean_zle=1;
      double s2_sigma_zle=TMath::Abs(s2_zle_fluc->Eval(s2));
      double s2_zle_eff;
      if(s2>2000)s2_sigma_zle = TMath::Abs(s2_zle_fluc->Eval(2000)) ;
      s2_zle_eff=-1;
      while(s2_zle_eff<0||s2_zle_eff>1)
        s2_zle_eff=gRandom->Gaus(s2_mean_zle,s2_sigma_zle);

      if(s2_zle_eff>=1)s2_zle_eff=1;

      s2_d = s2 * s2_zle_eff;

      //s1_d = s1_mapping->Eval(s1);
      //s2_d = s2_mapping->Eval(s2);
      double r_bottom_s2_fraction = gRandom->Gaus(bottom_s2_fraction, s1_s2b_frac->Eval(s1_d));
      if(r_bottom_s2_fraction < 0) r_bottom_s2_fraction=0;
      s2b_d = s2_d * r_bottom_s2_fraction;
      s1_d_r = s1_mapping->GetX(s1_d,0.3*s1_d,2*s1_d);
      s2_d_r = s2_mapping->GetX(s2_d,0.3*s2_d,2*s2_d);
      s2b_d_r = s2_d_r * r_bottom_s2_fraction;
    }
    else{

      s1_d = s1;
      s2_d = s2;
      s2b_d = s2b;
    }
    if (s1_d < 0 ) {
      s1_d = 0;
    }
    if (s2b_d < 0) {
      s2b_d = 0;
    }
    if (s2_d < 0) {
      s2_d = 0;
    }
}

void DetSim::calculate_nhit_s1 (const int i_photon) {
  std::map<int, int> pmt_hit_map; // i_pmt, n_PE
  for (int i = 0; i < i_photon; ++i) {
    auto n_hits = 1 + gRandom->Binomial(1, dpe_fraction);
    int i_pmt = int(histo_pmt_hit_ratio->GetRandom());
    pmt_hit_map[i_pmt] += n_hits;
  }
  nhits_s1 = pmt_hit_map.size();
  nhits_s1_eff = 0;
  for (const auto &pmt_hit : pmt_hit_map) {
    auto n_hits = pmt_hit.second;
    double channel_light = 0;
    while (channel_light <= 0) {
      channel_light  = gRandom->Gaus(n_hits, pmt_resolution * sqrt(n_hits));
    }
    if (channel_light > 0.5) {
      ++nhits_s1_eff;
    }
  }

}
