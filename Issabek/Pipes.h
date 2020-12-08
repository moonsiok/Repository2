#pragma once
#include <string>
#include <iostream>
class Pipes
{
    int id = 0;
    double  length = 0.0;
    double diameter = 0.0;
    bool UnderRepair = false;

public:
    void RedaktPipes();
    friend std::ostream& operator<<(std::ostream& out, const Pipes& p1);
    friend std::istream& operator >>(std::istream& in, Pipes& p1);
};

