#ifndef _XSECTION_H
#define _XSECTION_H


class Xsection{
    
public:
    //constructor
    Xsection();
    
public:
    //destructor
    virtual ~Xsection();
    
public:
    double cross_section(double neu_energy);


};


#endif
