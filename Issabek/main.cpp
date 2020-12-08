#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "KC.h"
#include "Pipes.h"
using namespace std;
// 
//struct Pipes
//{
//    int id = 0;
//    double  length = 0.0;
//    double diameter = 0.0;
//    bool UnderRepair = false;
//};
 
//struct KC
//{
//    int id = 0;
//    string name;
//    int kol_cekhov=0;
//    int  kol_cekhov_v_rabote=0;
//    int efficiency=0;
//};

template <typename T>
T GetCorrectNumber( T min, T max)
{   
    T value;
    while ((cin>>value).fail() || value > max || value < min)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Only numbers from " << min << " to " << max << " can be entered: ";
    }
    return value;
}

unsigned int GetCorrectNumber(unsigned int min, size_t max)
{
    unsigned int value;
    while ((cin >> value).fail() || value > max || value < min)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Only numbers from " << min << " to " << max << " can be entered: ";
    }
    return value;
}

Pipes& SelectPipes(vector <Pipes>& g)
{
    cout << "enter index: ";
    unsigned int index = GetCorrectNumber(1u, g.size());
    return g[index - 1];
}



void SavePipes( ofstream& fout,const Pipes& p1)
{   
        fout << p1.id << endl;
        fout << p1.length << endl;
        fout << p1.diameter << endl;
        fout << p1.UnderRepair << endl;
      
}

Pipes LoadPipes(ifstream &fin)
{   
    Pipes p1;
   
        fin >> p1.id;
        fin >> p1.length;
        fin >> p1.diameter;                   
        fin >> p1.UnderRepair;
        
    return p1;
}

void EditPipes(Pipes& p1)
{
    p1.RedaktPipes();
   /* p1.UnderRepair = !p1.UnderRepair;
    cout << "the pipe's status is changed but not saved";*/
}



void SaveKC(ofstream& fout, const KC& k1)
{
   
    fout << k1.id << endl;
    fout << k1.name << endl;
    fout << k1.kol_cekhov << endl;
    fout << k1.kol_cekhov_v_rabote << endl;
    fout << k1.efficiency << endl;
}
KC LoadKC(ifstream& fin)
    {
        KC k1;
       
                    fin >> k1.id;
                    fin.ignore(2222, '\n');
                    getline(fin, k1.name);
                    fin >> k1.kol_cekhov;
                    fin >> k1.kol_cekhov_v_rabote;
                    fin >> k1.efficiency;
        return k1;
    }

void PrintMenu()
    {
        cout << "\n1. Add Pipe" << endl
            << "2. Add CS" << endl
            << "3. Save All" << endl
            << "4. Edit the pipe" << endl
            << "5. Edit the CS" << endl
            << "6. Load the pipe" << endl
            << "7. Load the CS" << endl
            << "8. Print All" << endl
            << "0. Exit" << endl<<endl;
    }

void EditKC(KC& k1)
{
    k1.RedaktKC();

        /*cout << "do you want to change the number of workshops in operation?(y/n)\n";
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
            int VseKolichestvo=k1.kol_cekhov;
            k1.kol_cekhov_v_rabote=GetCorrectNumber(0, VseKolichestvo);
            cout<< "the information is changed but not saved\n";
            break;
        }
        case 'n':
        {
            break;
        }
        }*/
}

  
int main()
    {   
       // Pipes p1;
        vector <Pipes> group;
        vector <KC> group1;
        while (1)
        {   
            cout << "\nChoose from the menu " << endl;
            PrintMenu();  
            switch (GetCorrectNumber( 0, 8))
            {
            case 1:
            {
                Pipes p1;
                cin >> p1;
                group.push_back(p1);
            break;
            }
            case 2:
            {
                KC k1;
                cin >> k1;
                group1.push_back(k1);
            break;
            }
            case 3:
            {
               /* ofstream fout;
                fout.open("PipesAndCS.txt", ios::out);
                if (fout.is_open())
                {
                    fout << group.size() << endl;
                    for (Pipes p1: group)
                        SavePipes(fout, p1);
                    fout.close();
                }

            cout << "Information was successfully saved" << endl;
            break;*/
            }
            case 4:
            {
            EditPipes(); 
            break;
            }
            case 5:
            {EditKC();
            break;
            }
            case 6:
            { ifstream fin;
            fin.open("PipesAndCS.txt", ios::in);
            if (fin.is_open())
            {
                int count;
                fin >> count;
                group.reserve(count);
                while (count--) 
                {
                group.push_back(LoadPipes(fin));
                }
  
                fin.close();
            }
               
            break;
            }
            case 7:
            {   ifstream fin;
                fin.open("PipesAndCS.txt", ios::in);
                if (fin.is_open())
                {
                    int count;
                    fin >> count;
                    group1.reserve(count);
                    while (count--)
                    {
                        group1.push_back(LoadKC(fin));
                    }
                    fin.close();
                }
            break;
            }
            case 8:
            {
                for(auto& p1: group)
                cout << p1 << endl;
                for (auto& k1 : group1)
                    cout << k1 << endl;
            break;
            }
            case 0:
            {return 0;
            break;
            }
            return 0;
            }
        }
        
        return 0;
    }
 
