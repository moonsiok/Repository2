#pragma once
#include <string>
#include <iostream>
#include <fstream>

class KC
{
    int idKC; 
    std::string name;
    int kol_cekhov;
    int  kol_cekhov_v_rabote;
    int efficiency;
    static int MaxID;
public:
   
        KC();
        static int csMaxid;
        double GetPercentWorkingWorkshops() const;
        static int GetMaxid();
        KC(std::ifstream& fin);
        void SaveToFile(std::ofstream& fout);
        std::string GetName() const;
        int GetWorking() const;
        int GetWorkshops() const;
        double GetEfficiency() const;
        static int GetMaxID();
        int GetID() const;
        void RedaktKC();
     
        friend std::ostream& operator<<(std::ostream& out, const KC& k1);
        friend std::istream& operator >>(std::istream& in, KC& k1);
        friend std::ofstream& operator << (std::ofstream& fout, const KC& k1);
        friend std::ifstream& operator >> (std::ifstream& fin, KC& k1);
};

