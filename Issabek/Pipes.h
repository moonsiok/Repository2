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
    bool UnderRepair;

public:  
    void RedaktPipes();

    void SavePipes();
    friend std::ostream& operator<<(std::ostream& out, const Pipes& p1);
    friend std::istream& operator >>(std::istream& in, Pipes& p1);
};

