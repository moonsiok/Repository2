#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
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
        //KC(std::string name);
        //KC(const KC& k);//kopirovanie
        //KC(KC&& k);//peremewenie
        //~KC();


        /*std::string GetName()  const;
        void SetName(std::string);*/
        void RedaktKC();
     
        friend std::ostream& operator<<(std::ostream& out, const KC& k1);
        friend std::istream& operator >>(std::istream& in, KC& k1);
        friend std::ofstream& operator << (std::ofstream& fout, const KC& k1);
        friend std::ifstream& operator >> (std::ifstream& fin, KC& k1);
};

