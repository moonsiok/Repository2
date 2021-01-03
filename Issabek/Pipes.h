#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

class Pipes
{
    int idPipes;
    std::string name;
    double  length;
    double diameter;
    bool UnderRepair;
    static int Maxid;
public:  
    static int PMaxID;
    int startid;
    int endid;
    bool used;
    Pipes();
    std::string GetName() const;
    int GetDiameter() const;
    double GetWeight() const;
    int GetLength() const;
    bool GetStatus() const;
    int GetID() const;
    static int GetMaxID();
    void RedaktPipes();
    Pipes(std::ifstream& fin);
    int GetProductivity() const;
    void Edit();
    void SaveToFile(std::ofstream& fout);
    void IsBroken();
    friend std::ostream& operator<<(std::ostream& out, const Pipes& p1);
    friend std::istream& operator >>(std::istream& in, Pipes& p1);
    friend std::ofstream& operator << (std::ofstream& fout, const Pipes& p1);
    friend std::ifstream& operator >> (std::ifstream& fin, Pipes& p1);
};

