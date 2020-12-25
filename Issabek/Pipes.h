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
    double weight;
    double  length;
    double diameter;
    bool UnderRepair;
    int start;
    int end;
    bool used;
    Pipes();
    std::string GetName() const;

    int GetDiameter() const;

    double GetWeight() const;

    int GetLength() const;

    bool GetStatus() const;

    void SetStart(int);
    void SetEnd(int);

    int GetStart() const;
    int GetEnd() const;

    int GetID() const;
    void RedaktPipes();
   
    friend std::ostream& operator<<(std::ostream& out, const Pipes& p1);
    friend std::istream& operator >>(std::istream& in, Pipes& p1);
    friend std::ofstream& operator << (std::ofstream& fout, const Pipes& p1);
    friend std::ifstream& operator >> (std::ifstream& fin, Pipes& p1);
};

