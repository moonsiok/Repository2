#include "KC.h"
#include "Utility.h"
using namespace std;
int KC::MaxID = 1;
int KC::csMaxid = 1;
ostream& operator<<(ostream& out, const KC& k1)
{
    out << "\t*Compressor Station*\n";
   // out << "the ID of the CS: " << k1.idKC << endl;
    out << "the name: " << k1.name << endl;
    out << "the number of workshops: " << k1.kol_cekhov << endl;
    out << "the number of workshops in operation: " << k1.kol_cekhov_v_rabote << endl;
    out << "the efficiency: " << k1.efficiency << endl;
    return out;
}

istream& operator >>(istream& in, KC& k1)
{
    cout << "\t*Compressor station*\n";
  //  cout << "the ID of the new pipe: " << k1.idKC << endl;
    cout << "enter the name: ";
    in.ignore(1000, '\n');
    getline(in, k1.name); 
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

std::ifstream& operator>>(std::ifstream& fin, KC& k1)
{
    fin >> k1.idKC >> k1.name >> k1.kol_cekhov >> k1.kol_cekhov_v_rabote >> k1.efficiency;
    return fin;
}

std::ofstream& operator<<(std::ofstream& fout, const KC& k1)
{
    fout << k1.idKC <<endl<< k1.name <<endl<< k1.kol_cekhov <<endl<< k1.kol_cekhov_v_rabote <<endl<< k1.efficiency << endl;
    return fout;
}

KC::KC()
{
    idKC = MaxID++;
    name = "name";
    kol_cekhov = 0;
    kol_cekhov_v_rabote=0;
    efficiency = 0;
}

int KC::GetMaxID()
{
    return MaxID;
}

void KC::RedaktKC()
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

int KC::GetID() const
{
    return idKC;
}

int KC::GetMaxid()
{
    return MaxID;
}

KC::KC(std::ifstream& fin)
{
}

std::string KC::GetName() const
{
    return name;
}


int KC::GetWorking() const
{
    return kol_cekhov_v_rabote;
}


int KC::GetWorkshops() const
{
    return kol_cekhov;
}


double KC::GetEfficiency() const
{
    return efficiency;
}

double KC::GetPercentWorkingWorkshops() const
{
    return  100.0 * (kol_cekhov-kol_cekhov_v_rabote) / kol_cekhov;
}

void KC::SaveToFile(std::ofstream& fout)
{
    fout << name << '\n'
        << kol_cekhov << '\n'
        << kol_cekhov_v_rabote << '\n'
        << efficiency << '\n';
}


