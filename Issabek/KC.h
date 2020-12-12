#pragma once
#include <string>
#include <iostream>
#include <fstream>

class KC
{
private:
    int idKC; 
    static int MaxID;
public:
    std::string name;
    int kol_cekhov;
    int  kol_cekhov_v_rabote;
    int efficiency;
    
   
        KC();
        int GetID() const;
        void RedaktKC();
     
        friend std::ostream& operator<<(std::ostream& out, const KC& k1);
        friend std::istream& operator >>(std::istream& in, KC& k1);
        friend std::ofstream& operator << (std::ofstream& fout, const KC& k1);
        friend std::ifstream& operator >> (std::ifstream& fin, KC& k1);
};

