#pragma once
#include <string>
#include <iostream>
#include <fstream>

class KC
{
    int id; 
    std::string name;
    int kol_cekhov;
    int  kol_cekhov_v_rabote;
    int efficiency;
    static int MaxID;
public:
   
        KC();
        static int csMaxid;
        double GetPercentWorkingWorkshops() const;
        static int GetMaxID();
        KC(std::ifstream& fin);
        void SaveToFile(std::ofstream& fout);
        std::string GetName() const;
        int GetWorking() const;
        int GetWorkshops() const;
        double GetEfficiency() const;
        int GetID() const;
        void RedaktKC();
     
        friend std::ostream& operator<<(std::ostream& out, const KC& cs);
        friend std::istream& operator >>(std::istream& in, KC& cs);
};

