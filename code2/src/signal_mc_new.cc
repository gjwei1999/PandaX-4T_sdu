#include "det-sim.h"
#include "pandax-quanta.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <TFile.h>
#include <TGraph.h>
#include <TTree.h>
#include <TKey.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TF1.h>
#include <TRandom.h>

#include "json.hpp"
using namespace std;

int main(int argc, char *argv[]) {
  if (argc!=3) {
    std::cerr << "Usage: " << argv[0] << "confFile n"<<endl;
    //std::cerr << "Usage: " << argv[0] << " lifetime_file yield g1g2 outfile run [n]" << std::endl;
    return 1;
  }

  ifstream fpar(argv[1]);
  int n=atoi(argv[2]);
  nlohmann::json j;
  fpar >> j;
  string homePath=j["home_path"];
  string oname=j["simuRootFile"];
//  string yieldName=j["yieldRootFile"];
//  string mapName=j["quantaDataRootFile"];
  string eSpec=j["energyFunc"]["func"];
  bool th1f_e_bool=j["energyFunc"]["TH1F"];
  string eFileName;
  TH1F* h_energy;
  if(th1f_e_bool)
  {
    eFileName=j["energyFunc"]["TH1Ffile"];
    TFile fileTemp(eFileName.c_str(),"read");
    string eName=j["energyFunc"]["TH1Fname"];
    h_energy=(TH1F*) fileTemp.Get(eName.c_str())->Clone();
    h_energy->SetDirectory(0);
    fileTemp.Close();
  }
  string twoDFile;
  oname=homePath+"/"+oname;
//  yieldName=homePath+"/"+yieldName;
//  mapName=homePath+"/"+mapName;

  int run=j["run"];
  bool zle=j["zle"];
  bool NR=j["NR"];
  bool twoD=j["twoD"];
  double z_interface=j["z_interface"];
  double maxR=j["maxR"];
  double field=j["field"];
  double E_eeMax=j["E_eeMax"];
  double E_eeTh=j["E_eeTh"];
  double v_e=j["v_e"];


  if (NR) 
  {
    E_eeTh *=5;
    E_eeMax *=4;
  }
  else E_eeMax *=2;
  vector<double> pars=j["energyFunc"]["par"].get<std::vector<double> >();
  TF1 * f_spec;
  if(TString(eSpec).Contains("double")) f_spec = new TF1("f_spec", eSpec.c_str(), E_eeTh, E_eeMax, pars.size());
  else f_spec = new TF1("f_spec", eSpec.c_str(), E_eeTh, E_eeMax);
  if (pars.size())f_spec->SetParameters(&pars[0]);
  cout<<"test f_spec "<<f_spec->Eval(1)<<endl;

//  TFile *yieldFile = new TFile(yieldName.c_str(),"read");
//  TGraph *qy=(TGraph*)yieldFile->Get("qy_g");
//  TGraph *ly=(TGraph*)yieldFile->Get("ly_g");
//  TGraph *qy_fluc;

//  TFile mapFile(mapName.c_str(),"read");
//  TF1 *fs1=(TF1*) mapFile.Get("fs1")->Clone();
//  TF1 *fs2=(TF1*) mapFile.Get("fs2")->Clone();
//  fs1->SetRange(0,fs1->GetXmax());
//  fs2->SetRange(0,fs2->GetXmax());
//  mapFile.Close();


  double pde, eee, seg, s2b_fraction, dpe_ratio,pmt_resolution;
  pde=j["pde"];
  eee=j["eee"];
  seg=j["seg"];
  s2b_fraction=j["s2b_fraction"];
  pmt_resolution=j["pmt_resolution"];
  dpe_ratio=j["dpe"];
  if(dpe_ratio==0) std::cout<<"something wrong with g1g2"<<std::endl;

  gRandom->SetSeed(0);
  double lifetime;
  std::vector<double> lifetimes=j["elife"]["lifetime"].get<std::vector<double> >();
  std::vector<double> durations=j["elife"]["duration"].get<std::vector<double> >();         //duration 是什么
  TH1D *th_duration = new TH1D("dur", "Duration", int(durations.size()), 0, int(durations.size()));
  for (int i = 0; i < int(durations.size()); ++i) {
    th_duration->SetBinContent(i + 1, durations[i]);
  }
  DetSim ds(pde, eee, seg, s2b_fraction, dpe_ratio, pmt_resolution, zle,run);
  TH2F *hr2z=0x0;
  TH2F *hs2map=0x0;
  if(twoD)
  {
    twoDFile=j["2dRootFile"];
    twoDFile=homePath+"/"+twoDFile;
    TFile file2d(twoDFile.c_str(),"read");
    hr2z=(TH2F*)file2d.Get("hr2z")->Clone();
    hs2map=(TH2F*)file2d.Get("hCyMap")->Clone();
    hr2z->SetDirectory(0);
    hs2map->SetDirectory(0);
    file2d.Close();
  }
  //ds.set_eff(fs2eff,fs1eff);
  double tl=j["dt_l"];
  double tu=j["dt_u"];
  if (NR)
    tu=j["dt_u_nr"];

  ds.set_t_drift_lower_limit(tl);
  ds.set_t_drift_upper_limit(tu);

  namespace px = pandax;
  px::PandaXQuanta pq{field};
//  pq.SetParaYield(qy,ly);
//  cout<<yieldFile->Get("fit_fluc_gr")<<endl;
//  if (yieldFile->Get("fit_fluc_gr"))
//  {
//    qy_fluc=(TGraph*)yieldFile->Get("fit_fluc_gr");
//    cout<<"fluc inputted"<<endl;
//    pq.SetParaFluc(qy_fluc);
//  }
  //pq.SetParaNr(para);
  double energy{0}, energy_rec, energy_rec_nozle;
  int nQuanta, Nex, Ni, Nph, Ne;
  double NphRec, NeRec;
  double S1, S1d;
  double S2, S2d, S2B, S2Bd;
  int nHitsS1, nHitsS1eff;
  double x,y,dt;
  double Ly,Qy;
  double s1r,s2r,s2r_b; 

  TFile *fout=new TFile(oname.c_str(), "recreate");
  TTree *tree = new TTree("qmc_tree", "Quanta MC");
  tree->Branch("energy", &energy, "energy/D");
  tree->Branch("nQuanta", &nQuanta, "nQuanta/I");
  tree->Branch("nExcitation", &Nex, "nExcitation/I");
  tree->Branch("nIonization", &Ni, "nIonization/I");
  tree->Branch("nPhoton", &Nph, "nPhoton/I");
  tree->Branch("nElectron", &Ne, "nElectron/I");
  tree->Branch("nPhotonRec", &NphRec, "nPhotonRec/D");
  tree->Branch("nElectronRec", &NeRec, "nElectronRec/D");
  tree->Branch("Ly",&Ly,"Ly/D");
  tree->Branch("Qy",&Qy,"Qy/D");
  tree->Branch("S1", &S1, "S1/D");
  tree->Branch("S1d", &S1d, "S1d/D");
  tree->Branch("S1dr", &s1r, "S1dr/D");
  tree->Branch("nHitsS1", &nHitsS1, "nHitsS1/I");
  tree->Branch("nHitsS1eff", &nHitsS1eff, "nHitsS1eff/I");
  tree->Branch("S2", &S2, "S2/D");
  tree->Branch("S2d", &S2d, "S2d/D");
  tree->Branch("S2dr", &s2r, "S2dr/D");
  tree->Branch("S2B", &S2B, "S2B/D");
  tree->Branch("S2Bd", &S2Bd, "S2Bd/D");
  tree->Branch("S2Bdr", &s2r_b, "S2Bdr/D");

  tree->Branch("dt", &dt, "dt/D");
  tree->Branch("y", &y, "y/D");
  tree->Branch("x", &x, "x/D");
  tree->Branch("lifetime", &lifetime, "lifetime/D");
//  tree->Branch("energyRec", &energy_rec, "energyRec/D");
//  tree->Branch("energyRecNoZLE", &energy_rec_nozle, "energyRecNoZLE/D");




  for (int i = 0; i < n; ++i) {
    if(th1f_e_bool)
      energy = h_energy->GetRandom();
    else
      energy = f_spec->GetRandom(E_eeTh,E_eeMax);

    if (NR)
      pq.calculate(energy, px::EnergyType::NR);
    else 
      pq.calculate(energy, px::EnergyType::ELECTRON);
    auto res = pq.getQuanta();
    nQuanta = res.Nq;
    Nex = res.Nex;
    Ni = res.Ni;
    Nph = res.Nph;
    Ne = res.Ne;
    //cout<<"Nph Ne "<<Nph<<" "<<Ne<<endl;
    int nBin = (int)th_duration->GetRandom();
    lifetime = lifetimes[nBin];
    //cout<<lifetime<<endl;
    ds.set_e_lifetime(lifetime);
    //cout<<Nph<<"\t"<<Ne<<"\t"<<dt<<"\t"<<x<<"\t"<<y<<endl;
    if(twoD)
    {
      double rtemp(3000),ztemp(0),dtTemp(-1);
      while(rtemp>maxR || (dtTemp < tl || dtTemp > tu))
      {
        hr2z->GetRandom2(rtemp,ztemp);
        dtTemp=TMath::Abs(ztemp-z_interface)/v_e;//unit: z mm; dt us
      }
      double thetaTemp=2*TMath::Pi()*gRandom->Rndm();
      x=rtemp*TMath::Cos(thetaTemp);
      y=rtemp*TMath::Sin(thetaTemp);
      ds.calculate(Nph, Ne,dtTemp,x,y);
      dt=dtTemp;
    }
    else
    {
      ds.calculate(Nph, Ne,0,0,0);
      x=0;
      y=0;
      dt=ds.get_drift_time();
    }
    S1 = ds.get_s1();
    S1d = ds.get_s1_det();
    nHitsS1 = ds.get_nhits_s1();
    nHitsS1eff = ds.get_nhits_s1_eff();
    S2 = ds.get_s2();
    S2d = ds.get_s2_det();
    S2B = ds.get_s2b();
    S2Bd = ds.get_s2b_det();
    //cout<<"s1 s2 "<<S1d<<" "<<S2d<<endl; 
    NphRec=0;
    NeRec=0;
      
//no mapname input so cannot do reconstruction
/*
    if (S1d< fs1->GetMinimum(0,100) || S2d < fs2->GetMinimum(0,1000))
    {
      energy_rec = 0;
      energy_rec_nozle = 0;
    }
    else
    {
      NphRec=fs1->GetX(S1d);
      NeRec=fs2->GetX(S2d);
      s1r=S1d;
      s2r=S2d;
      if (zle){
        s1r = ds.s1_mapping->GetX(S1d);
        s2r = ds.s2_mapping->GetX(S2d);
        s2r_b = s2r * S2Bd/S2d*s2r;
        if(s1r<S1d)s1r=S1d;
        if(s2r<S2d)s2r=S2d;
        if(s2r_b < S2Bd) s2r_b = S2Bd;

      }
      energy_rec = pandax::kW * (s1r / pde + s2r / eee / seg );
      energy_rec_nozle = pandax::kW * (S1d / pde + S2d / eee / seg );

      Ly=NphRec/energy_rec;
      Qy=NeRec/energy_rec;
    }
 */
    tree->Fill();
  }
  fout->cd();
  tree->Write();
  fout->Close();
  return 1;
}
