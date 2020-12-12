#pragma once
#include <iostream>
#include <fstream>


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
   
    int GetID() const;
    void RedaktPipes();
   
    friend std::ostream& operator<<(std::ostream& out, const Pipes& p1);
    friend std::istream& operator >>(std::istream& in, Pipes& p1);
    friend std::ofstream& operator << (std::ofstream& fout, const Pipes& p1);
    friend std::ifstream& operator >> (std::ifstream& fin, Pipes& p1);
};

