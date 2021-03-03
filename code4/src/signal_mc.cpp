/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#include "signal_mc.hpp"
#include "branches.hpp"

Signal_mc::Signal_mc(){};
Signal_mc::~Signal_mc(){};

void Signal_mc::set_num_simu(int input_num_of_simu){
    num_of_simu = input_num_of_simu;
}


void Signal_mc::run_mc(TString para_file, int num_of_simulation, int events_in_20s){

  ifstream fpar(para_file.Data());
  int n;
  nlohmann::json j;
  fpar >> j;
  
  
  int total_time = 0;
  string time_spectrum_file;
  TH1D * time_spec;
  bool supernova = j["ifSN"];//if supernoa is true, the simulation is for supernova
  int num_event;//number of events in 20s
  
  
  if(supernova){
      
      time_spectrum_file = j["supernova"]["time_spectrum"];
      TFile fs(time_spectrum_file.c_str(),"read");
      string time_spectrum_name = j["supernova"]["time_spectrumName"];
      time_spec = (TH1D*) fs.Get(time_spectrum_name.c_str())->Clone();
      time_spec->SetDirectory(0);
      fs.Close();
      
      total_time = num_of_simulation * 20.0;//20 seconds for every SN burst simulation 
      num_event = events_in_20s;

      n = num_of_simulation * num_event;//num of events
}


    
  
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
  
  double event_time;
  if(supernova){
      tree->Branch("event_time", &event_time, "event_time/D");
      tree->Branch("total_time", &total_time, "total_time/I");//save the total_time which is used as the bin number 
  }
  
  
  
  int i = 0;//the ith event
  int k = 0;//the kth simulation for supernova
  
  for (i = 0; i < n; ++i) {
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
      
    if(supernova){
        
        k = i/num_event;
        event_time = time_spec->GetRandom() + k*20.0;
//        if(event_time<10.0 && event_time>9.0){
//        std::cout<<"the event_time is "<<event_time<<std::endl;
//        }
    }
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
  
  
  Int_t nentries = (Int_t)tree->GetEntries();
  tree->Draw("event_time","","goff");
  Int_t *index = new Int_t[nentries];
  TMath::Sort(nentries,tree->GetV1(),index, false);
  tree_sorted = (TTree*)tree->CloneTree(0);
	for (Int_t i=0;i<nentries;i++) {
		tree->GetEntry(index[i]);
		tree_sorted->Fill();
	}
	
  fout->cd();
  tree_sorted->Write();
  fout->Close();
  
  delete [] index;
  
  std::cout<<""<<std::endl;
  std::cout<<"The entries are re-sorted."<<std::endl;
  std::cout<<""<<std::endl;

}

double Signal_mc::time_window(int loadfile_name, double T_sn, double t_refresh, int N_thr){
    //load file name includes number only(3003)
    
    TString load_file_name;
    load_file_name.Form("%d", loadfile_name);
    
    TString load_root = loadpath + load_file_name + "_simu.root";
    TString result_root = outpath + load_file_name + ".root";
    
    TFile *load_file = new TFile(load_root.Data(), "r");//input
    TFile *result_file = new TFile(result_root.Data(), "RECREATE");//output
    
    TTree *sorted_tree = (TTree*)load_file->Get("qmc_tree");
    
    int num_of_events;
    num_of_events = (int)sorted_tree->GetEntries();

    Branches * branch1 = new Branches();
    branch1->init(sorted_tree);
    
    double total_time_simu;//get the total_time of the simulation
    sorted_tree->GetEntry(0);
    total_time_simu = branch1->get_total_time();
    
    //histograms
    TH1D * h_event_time = new TH1D("event_time", "event_time", total_time_simu, 0.0, total_time_simu);
    TH1D * h_detected_event_time =new  TH1D("detected_event_time", "detected_event_time", total_time_simu, 0.0, total_time_simu);
    TH2D * h_logs2s1_s1= new TH2D("logs2s1_s1", "", 100, 0.0, 150.0, 100, 1.0, 10.0);
    
    int n_s1d = 0;
    int n_s2d = 0;
    int n_s1d_s2d = 0;
    
    for (int current_event = 0; current_event < num_of_events; current_event++) {
        
        // Get current event
        sorted_tree->GetEntry(current_event);
        
        
        if(branch1->get_S1d() > 0.0){
            n_s1d++;}
        
        if(branch1->get_S2d() > 0.0){
            n_s2d++;}
        
        if((branch1->get_S2d() > 0.0) && (branch1->get_S2d() > 0.0)){
            n_s1d_s2d++;}
        
        //fill histogram
        h_event_time->Fill(branch1->get_event_time());
        
        if((branch1->get_S1d() > 0.0) && (branch1->get_S2d() > 0.0)){
            h_detected_event_time->Fill(branch1->get_event_time());
        }
        
        //std::cout<<"current event energy is "<<branch1->get_nQuanta()<<std::endl;
    }
    
    //set bin error to 0
        for(int i; i<total_time_simu; i++){
            h_event_time->SetBinError(i, 0.0);
            h_detected_event_time->SetBinError(i, 0.0);
        }
        
    h_event_time->SetDirectory(result_file);
    h_detected_event_time->SetDirectory(result_file);
    h_logs2s1_s1->SetDirectory(result_file);
    
    result_file->Write();
    
    double temp;
        temp = TMath::Log(branch1->get_S2d()/branch1->get_S1d());
        h_logs2s1_s1->Fill(branch1->get_S1d(), temp);
        
        
        
        //sliding time window
        int event_in_win = 0;//num of events in time window
        double eventT;
        double win_left;//lower limit of time window
        double win_right;// upper limit of time window
        double next_win_left;//lower limit of next time window
        bool find_next_win = true;//whether to find next window
        int k = 0;// the kth simulation
        int m = 0;//the mth sliding window
        int index_next_win = 0;//event index for next window left
        int current_event = 0;//index for curent event
        int alert_sent = 0;//num of sent alert
        
        while(current_event < num_of_events){
            
            sorted_tree->GetEntry(current_event);
            eventT = branch1->get_event_time();
            
            win_left = 20.0*k + t_refresh*m;
            win_right = win_left + T_sn;
            next_win_left = win_left + t_refresh;
            
            
            if(current_event%100 ==0){
                    //std::cout<<"Now: running "<<current_event<<"th event"<<std::endl;
            }
            
            
            if(eventT < win_left){
                current_event++;
                continue;//go to next loop
            }
            
            
            if((eventT < win_right) && ( eventT >= win_left)){
                if((branch1->get_S2d() > 0.0) && (branch1->get_S2d() > 0.0)){
                    event_in_win++;
                }
            }
            
            //find next window
            if(find_next_win){
                if(eventT > next_win_left){
                    index_next_win = current_event;
                    find_next_win = false;
                    //std::cout<<"The next window left corresponds to "<<index_next_win<<"th event."<<std::endl;
                }
            }
            
            
                
            if(eventT >= win_right){
                
                if(event_in_win > N_thr){
                    event_in_win = 0;//reset the value
                    alert_sent++;
                    k++;//go to next 20s-simulation;
                    m = 0;//reset m
                    find_next_win = true;
                }
                else{
                    event_in_win = 0;//reset the value
                    m++;//go to next window
                    current_event = index_next_win;
                    find_next_win = true;
                }
                
            }
            else{
                current_event++;
            }
            
            
            
        }
        
        double trigger_eff = double(alert_sent)/num_of_simu;
        
        std::cout<<alert_sent<<" alerts are sent in "<<num_of_simu<<" simulations"<<std::endl;
        std::cout<<"The trigger efficiency is "<<trigger_eff<<std::endl;
        
        delete branch1;
        
        return trigger_eff;
}
