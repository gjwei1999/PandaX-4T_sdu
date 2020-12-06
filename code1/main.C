#include "spectrum.h"

#include "TFile.h"

int main(){
    
     //define path of root
     TString path2 = "/Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code1/build/";
     
     //define root file name
     TString root_time_spec = path2 + "time_spec.root";
     TString root_energy_spec = path2 + "energy_spec.root";
     
     //define filename_time
     TString filename_time_1301 = "intp1301.data";
     TString filename_time_1302 = "intp1302.data";
     TString filename_time_1303 = "intp1303.data";
     
     TString filename_time_2001 = "intp2001.data";
     TString filename_time_2002 = "intp2002.data";
     TString filename_time_2003 = "intp2003.data";
     
     TString filename_time_3001 = "intp3001.data";
     TString filename_time_3002 = "intp3002.data";
     TString filename_time_3003 = "intp3003.data";
     
     TString filename_time_5001 = "intp5001.data";
     TString filename_time_5002 = "intp5002.data";
     TString filename_time_5003 = "intp5003.data";
     
     //define class for every dataset
     Spectrum* Spec_1301 = new Spectrum();
     Spectrum* Spec_1302 = new Spectrum();
     Spectrum* Spec_1303 = new Spectrum();
     Spectrum* Spec_2001 = new Spectrum();
     Spectrum* Spec_2002 = new Spectrum();
     Spectrum* Spec_2003 = new Spectrum();
     Spectrum* Spec_3001 = new Spectrum();
     Spectrum* Spec_3002 = new Spectrum();
     Spectrum* Spec_3003 = new Spectrum();
     Spectrum* Spec_5001 = new Spectrum();
     Spectrum* Spec_5002 = new Spectrum();
     Spectrum* Spec_5003 = new Spectrum();
     
     
    //files for time and energy spec
     TFile * fs1 = new TFile(root_time_spec.Data(), "RECREATE");
     TFile * fs2 = new TFile(root_energy_spec.Data(), "RECREATE");
     
     
     Spec_1301->time_spectrum(filename_time_1301, fs1);
     Spec_1302->time_spectrum(filename_time_1302, fs1);
     Spec_1303->time_spectrum(filename_time_1303, fs1);
     Spec_2001->time_spectrum(filename_time_2001, fs1);
     Spec_2002->time_spectrum(filename_time_2002, fs1);
     Spec_2003->time_spectrum(filename_time_2003, fs1);
     Spec_3001->time_spectrum(filename_time_3001, fs1);
     Spec_3002->time_spectrum(filename_time_3002, fs1);
     Spec_3003->time_spectrum(filename_time_3003, fs1);
     Spec_5001->time_spectrum(filename_time_5001, fs1);
     Spec_5002->time_spectrum(filename_time_5002, fs1);
     Spec_5003->time_spectrum(filename_time_5003, fs1);
     
     fs1->Write();

     
     //define filename energy
     TString filename_energy_1301 = "integ1301.data";
     TString filename_energy_1302 = "integ1302.data";
     TString filename_energy_1303 = "integ1303.data";
     
     TString filename_energy_2001 = "integ2001.data";
     TString filename_energy_2002 = "integ2002.data";
     TString filename_energy_2003 = "integ2003.data";
     
     TString filename_energy_3001 = "integ3001.data";
     TString filename_energy_3002 = "integ3002.data";
     TString filename_energy_3003 = "integ3003.data";
     
     TString filename_energy_5001 = "integ5001.data";
     TString filename_energy_5002 = "integ5002.data";
     TString filename_energy_5003 = "integ5003.data";
     
     Spec_1301->energy_spectrum(filename_energy_1301, fs2);
     Spec_1302->energy_spectrum(filename_energy_1302, fs2);
     Spec_1303->energy_spectrum(filename_energy_1303, fs2);
     Spec_2001->energy_spectrum(filename_energy_2001, fs2);
     Spec_2002->energy_spectrum(filename_energy_2002, fs2);
     Spec_2003->energy_spectrum(filename_energy_2003, fs2);
     Spec_3001->energy_spectrum(filename_energy_3001, fs2);
     Spec_3002->energy_spectrum(filename_energy_3002, fs2);
     Spec_3003->energy_spectrum(filename_energy_3003, fs2);
     Spec_5001->energy_spectrum(filename_energy_5001, fs2);
     Spec_5002->energy_spectrum(filename_energy_5002, fs2);
     Spec_5003->energy_spectrum(filename_energy_5003, fs2);
     
      fs2->Write();
     
     return 0;
}
