#include "KC.h"
#include "Utility.h"
//#include "Utils.h"
using namespace std;
vector <KC> group1;
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

std::ifstream& operator>>(std::ifstream& fin, KC& k1)
{
    fin >> k1.id >> k1.name >> k1.kol_cekhov >> k1.kol_cekhov_v_rabote >> k1.efficiency;
    return fin;
}

std::ofstream& operator<<(std::ofstream& fout, const KC& k1)
{
    fout << k1.id <<endl<< k1.name <<endl<< k1.kol_cekhov <<endl<< k1.kol_cekhov_v_rabote <<endl<< k1.efficiency << endl;
    return fout;
}
void KC::SohrKC()
{
    ofstream fout;
    fout.open("PipesAndCS.txt", ios::out);
    if (!fout.is_open())
    {
        fout << "error" << endl;
    }
    else
    {
        fout << group1.size() << endl;
        for (KC k1 : group1)

            fout << id << endl;
        fout << name << endl;
        fout << kol_cekhov << endl;
        fout << kol_cekhov_v_rabote << endl;
        fout << efficiency << endl; fout.close();
    }
}

void KC::ZagruzKC()
{
    ifstream fin;
    fin.open("PipesAndCS.txt", ios::in);
    if (fin.is_open())
    {
        int count;
        fin >> count;
        group1.reserve(count);
        while (count--)
        {
            /*  fin >> id;
              fin.ignore(2222, '\n');
              getline(fin, name);
              fin >> kol_cekhov;
              fin >> kol_cekhov_v_rabote;
              fin >> efficiency;
          }
          fin.close();*/
            char ch;
            while (fin.get(ch))
            {
                cout << ch;
            }

            fin.close();
        }
    }
}
