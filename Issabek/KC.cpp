#include "KC.h"
#include "Utility.h"
using namespace std;
//KC::KC()
//{
//    cout << "KC::KC()" << endl;
//  /*  id = 0;
//    name = " ";
//    kol_cekhov = 0;
//    kol_cekhov_v_rabote = 0;
//    efficiency = 0;*/
//}
//
//KC::~KC()
//{
//    cout << "KC::~KC()" << endl;
//}
//
//
//KC::KC(std::string name)
//{
//    this->name=name;
//}
//
//KC::KC(const KC& k)
//{
//    cout << "KC::KC(const KC& k)" << endl;
//}
//
//KC::KC(KC&& k)
//{
//    cout << "KC::KC(KC&& k)" << endl;
//}


std::string KC::GetName() const
{
    return std::string();
}



void KC::SetName(std::string new_name)
{
    name = new_name;
}

void KC::Redakt()
{
    cout << "do you want to change the number of workshops in operation?(y/n)\n";
    char i;
    cin >> i;
    while (i != 'y' && i != 'n')
    {
        cout << "yes or no? enter *y* or *n* respectively: ";
        cin >> i;
    }
    switch (i)
    {
    case 'y':
    {
        cout << "enter the number of workshops in operation: ";
        int VseKolichestvo = kol_cekhov;
        kol_cekhov_v_rabote = GetCorrectNumber(0, VseKolichestvo);
        cout << "the information is changed but not saved\n";
        break;
    }
    case 'n':
    {
        break;
    }
    }

}

ostream& operator<<(ostream& out, const KC& k1)
{
    out << "\t*Compressor Station*\n";
    out << "the ID of the CS: " << k1.id << endl;
    out << "the name: " << k1.name << endl;
    out << "the number of workshops: " << k1.kol_cekhov << endl;
    out << "the number of workshops in operation: " << k1.kol_cekhov_v_rabote << endl;
    out << "the efficiency: " << k1.efficiency << endl;
    return out;
}

istream& operator >>(istream& in, KC& k1)
{
    cout << "\t*Compressor station*\n";
    k1.id = rand() % 100 + 1;
    cout << "the ID of the new pipe: " << k1.id << endl;
    cout << "enter the name: ";
    in.ignore(1000, '\n');
    getline(in, k1.name); //https://cboard.cprogramming.com/cplusplus-programming/92353-cplusplus-strings-spaces.html
    cout << "enter the number of workshops: ";
    k1.kol_cekhov = GetCorrectNumber(0, 1000);
    cout << "enter the number of workshops in operation: ";
    int VseKolichestvo = k1.kol_cekhov;
    k1.kol_cekhov_v_rabote = GetCorrectNumber(0, VseKolichestvo);
    cout << "rate the efficiency from 0 to 10: ";
    k1.efficiency = GetCorrectNumber(0, 10);
    cout << endl << "Do not forget to save the new created station! Choose 3 in the menu\n";
    return in;
}