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
        cout << "there is no information\n ";
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
            << "6. Print the pipe" << endl
            << "7. Print the CS" << endl
            << "8. Load All" << endl
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
                    for (const auto& p1: group) cout << p1 << endl;
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
            case 0:
            {return 0;
            break;
            }
            return 0;
            }
        }
        
        return 0;
    }
 
