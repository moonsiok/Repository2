#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
class KC
{
    int id ;
    std::string name;
    int kol_cekhov;
    int  kol_cekhov_v_rabote;
    int efficiency;
    
   
        //KC();
        //KC(std::string name);
        //KC(const KC& k);//kopirovanie
        //KC(KC&& k);//peremewenie
        //~KC();
 public:
        /*std::string GetName()  const;
        void SetName(std::string);*/
        void RedaktKC();
        void SohrKC();
      void ZagruzKC();
        friend std::ostream& operator<<(std::ostream& out, const KC& k1);
        friend std::istream& operator >>(std::istream& in, KC& k1);
};

