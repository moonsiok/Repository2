#include "KC.h"
#include "Utility.h"
using namespace std;
int KC::MaxID = 0;
int KC::csMaxid = 0;
ostream& operator<<(ostream& out, const KC& cs)
{
    out << "\t*Compressor Station*\n";
    out << "the name: " << cs.name << endl;
    out << "the number of workshops: " << cs.kol_cekhov << endl;
    out << "the number of workshops in operation: " << cs.kol_cekhov_v_rabote << endl;
    out << "the efficiency: " << cs.efficiency << endl;
    return out;
}

istream& operator >>(istream& in, KC& cs)
{
    cout << "\t*Compressor station*\n";
    cout << "enter the name: ";
    in.ignore(1000, '\n');
    getline(in, cs.name); 
    cout << "enter the number of workshops: ";
    cs.kol_cekhov = GetCorrectNumber(0, 1000);
    cout << "enter the number of workshops in operation: ";
    int VseKolichestvo = cs.kol_cekhov;
    cs.kol_cekhov_v_rabote = GetCorrectNumber(0, VseKolichestvo);
    cout << "rate the efficiency from 0 to 10: ";
    cs.efficiency = GetCorrectNumber(0, 10);
    cout << endl << "Do not forget to save the new created station! Choose 3 in the menu\n";
    return in;
}

KC::KC()
{
    id = MaxID++;
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
    return id;
}

KC::KC(std::ifstream& fin)
{
    fin.ignore();
    std::getline(fin, name);
    fin
        >> kol_cekhov
        >> kol_cekhov_v_rabote
        >> efficiency;
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


