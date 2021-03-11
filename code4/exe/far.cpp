/***************************/
/*                         */
/*  Created by Jiawei Guo  */
/*   Shandong University   */
/*                         */
/***************************/

#include <iostream>
#include <fstream>
#include <cmath>

#include "eff_far.hpp"

int main(){
    
    Eff_far * false_alert_r = new Eff_far();
    
    double t_refresh[4] = {0.01, 0.02, 0.1, 0.2};
    int N_thr[4] = {3, 4, 5, 10}; 
    double er_bkg_rate = (7558.48 + 9.20852 + 0.00874182) / 24.0 / 60.0 / 60.0;
    double far;
    
    
    std::ofstream outfile;
    outfile.open("/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code4/output/far_5n.dat");
    
    for(int i=0; i<4; i++){
        
        far = false_alert_r->trigger_effeciency(N_thr[2], 1.0, er_bkg_rate);
        far = far * 3600.0 * 24.0 *7.0 /t_refresh[i];
        
        outfile << t_refresh[i] << " " << far << std::endl;
    }
    outfile.close();
    
    
    std::ofstream outfile1;
    outfile1.open("/Users/jiaweiguo/Documents/GitHub/PandaX-4T_sdu/code4/output/far_0.1t.dat");
    
    for(int i=0; i<4; i++){
        
        far = false_alert_r->trigger_effeciency(N_thr[i], 1.0, er_bkg_rate);
        far = far * 3600.0 * 24.0 *7.0 /t_refresh[2];
        
        outfile1 << N_thr[i] << " " << far << std::endl;
    }
    
    outfile1.close();
    
    
    
    return 1;
}
