#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "KC.h"
#include "Pipes.h"
#include "Utility.h"
#include "Utils.h"
using namespace std;

void SaveAll(vector <Pipes>& g, vector <KC> g1)
{
    if ((!g.size()) and (!g1.size()))
        cout << "there is no available information\n ";
    else
    {
        ofstream fout;
        fout.open("PipesAndCS.txt", ios::out);
        if (fout.is_open())
        {
            fout << g.size() << endl;
            fout << g1.size() << endl;
            for (const auto& p1 : g)
                fout << p1;
            for (const auto& k1 : g1)
                fout << k1;
            fout.close();
            cout << "information is saved\n";
        }
        else cout << "error";
    }

}

void LoadAll(vector <Pipes>& g, vector <KC> g1)
{
    ifstream fin;
    fin.open("PipesAndCS.txt", ios::in);
    if (fin.is_open())
    {
        char ch;
        while (fin.get(ch))
        {
            cout << ch;
        }
    }
    else cout << "file is not found\n";
    fin.close();
}

Pipes& SelectPipes(vector <Pipes>& g)
{
    cout << "enter index: ";
    unsigned int index = GetCorrectNumber(1u, g.size());
    return g[index - 1];
}

template <typename W, typename T>
using Filter = bool(*)(const W& o, T param);
bool CheckByRepairStatus(const Pipes& p1, bool UnderRepair)
{
    return p1.UnderRepair == UnderRepair;
}
bool CheckByName(const KC& k1, string name)
{
    return k1.name == name;
}
bool CheckByPercentageOfWorkshops(const KC& k1, double percent)
{
    return percent <= (double)(100 * (k1.kol_cekhov - k1.kol_cekhov_v_rabote) / k1.kol_cekhov);
}
template <typename W, typename T>
vector<int> FindItemsByFilter(const vector<Pipes>& g, Filter <W,T> f, T param)
{
    vector<int>res;
    int i = 0;
    for (const auto&  p1: g)
    {
        if (f(p1, param))
            res.push_back(i);
        i++;
    }
    return res;
}
template <typename W, typename T>
vector<int> FindItemsByFilter(const vector<KC>& g, Filter <W, T> f, T param)
{
    vector<int>res;
    int i = 0;
    for (const auto& k1 : g)
    {
        if (f(k1, param))
            res.push_back(i);
        i++;
    }
    return res;
}
void EditPipes(Pipes& p1)
{
    p1.RedaktPipes();
}

KC& SelectKC(vector <KC>& g1)
{
    cout << "enter index: ";
    unsigned int index = GetCorrectNumber(1u, g1.size());
    return g1[index - 1];
}

void PrintMenu()
    {
        cout << "\n1. Add Pipe" << endl
            << "2. Add CS" << endl
            << "3. Save All" << endl
            << "4. Edit the pipe" << endl
            << "5. Edit the CS" << endl
            << "6. Print pipes" << endl
            << "7. Print CS" << endl
            << "8. Load All" << endl
            << "9. Pipes Search by filter" << endl
            << "10. CS Search byy filter" << endl
            << "0. Exit" << endl<<endl;
    }

void EditKC(KC& k1)
{
    k1.RedaktKC();
}

int main()
{
    vector <Pipes> group;
    vector <KC> group1;
    while (1)
    {
        cout << "\nChoose from the menu " << endl;
        PrintMenu();
        switch (GetCorrectNumber(0, 10))
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
            SaveAll(group, group1);
            break;
        }
        case 4:
        { EditPipes(SelectPipes(group));
        break;
        }
        case 5:
        {EditKC(SelectKC(group1));
        break;
        }
        case 6:
        {
            if (group.size())
            {
                for (const auto& p1 : group) cout << p1 << endl;
            }
            else cout << "there is no information about pipes\n ";


            break;
        }
        case 7:
        {
            if (group1.size())
            {
                for (const auto& k1 : group1) cout << k1 << endl;
            }
            else cout << "there is no information about pipes\n ";

            break;
        }
        case 8:
        {
            LoadAll(group, group1);
            break;
        }
        case 9:
        {
           // SearchByFilters();
            cout << "1. Pipes (by repair status)" << endl
                << "2. CS (by name)" << endl
                << "3. CS (by percentage)" << endl
                << "0. Exit" << endl;
            switch (GetCorrectNumber(0, 3))
            {
            case 1:
            {
                cout << "1. find working pipes" << endl
                    << "2. find not working pipes" << endl;
                int a = (GetCorrectNumber(0, 2));
                if (a == 1) {
                    for (int i : FindItemsByFilter(group, CheckByRepairStatus, (bool)false))
                        cout << group[i];
                }
                else
                {
                    for (int i : FindItemsByFilter(group, CheckByRepairStatus, (bool)true))
                        cout << group[i];
                }
                break;
            }
            case 2:
            {
                string name;
                cout << "enter: ";
                cin.ignore(1000, '\n');
                getline(cin, name);
                for (int i : FindItemsByFilter(group1, CheckByName, name))
                    cout << group1[i];
                break;
            }
            case 3:
            {
                for (int i : FindItemsByFilter(group1, CheckByPercentageOfWorkshops, GetCorrectNumber(0.00, 100.0)))
                    cout << group1[i];
                break;
            }
            case 0:
            {
                PrintMenu();
                break;
            }
            }            
            break;
        }
        case 10:
        {



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


 
