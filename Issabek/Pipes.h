#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Pipes
{
 
    int id ;
    double  length;
    double diameter;
    bool UnderRepair=false;


public:  
    void RedaktPipes();

    void SohrPipes();
    void ZagruzPipes();
    friend std::ostream& operator<<(std::ostream& out, const Pipes& p1);
    friend std::istream& operator >>(std::istream& in, Pipes& p1);
    friend std::ofstream& operator << (std::ofstream& fout, const Pipes& p1);
    friend std::ifstream& operator >> (std::ifstream& fin, Pipes& p1);
};

