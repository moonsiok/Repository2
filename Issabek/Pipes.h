#pragma once
//#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Pipes
{
private:
    int idPipes;
    static int PMaxID;
    
public:  
    std::string name;
    double  length;
    double diameter;
    bool UnderRepair;

    Pipes();
    
    //Pipes(const Pipes& p1);//kopirovanie
    //Pipes(Pipes&& p1);//peremewenie
    //~Pipes();
 
    void RedaktPipes();
    
  
    //void SohrPipes();
    //void ZagruzPipes();
    friend std::ostream& operator<<(std::ostream& out, const Pipes& p1);
    friend std::istream& operator >>(std::istream& in, Pipes& p1);
    friend std::ofstream& operator << (std::ofstream& fout, const Pipes& p1);
    friend std::ifstream& operator >> (std::ifstream& fin, Pipes& p1);
};

