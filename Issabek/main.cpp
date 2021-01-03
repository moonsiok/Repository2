#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include "KC.h"
#include "Pipes.h"
#include "Utility.h"
#include "Utils.h"
#include "util.h"
#include "Network.h"
using namespace std;
string EnterName()
{
    string filename;
    cout << "\nplease enter a name for the file: ";
    cin.ignore(1000, '\n');
    getline(cin, filename);
    return filename;
}
//
//void SaveAll(const unordered_map<int, Pipes>& pipes_p, const unordered_map <int, KC>& kc_k)
//{
//    if ((!pipes_p.size()) and (!kc_k.size()))
//        cout << "there is no available information\n ";
//    else
//    {
//        ofstream fout;
//        fout.open(EnterName(), ios::out);
//        if (fout.is_open())
//        {
//            fout << pipes_p.size() << endl;
//            fout << kc_k.size() << endl;
//            for (const auto& p : pipes_p)
//                fout << p.second;
//            for (const auto& k : kc_k)
//                fout << k.second;
//            fout.close();
//            cout << "information is saved\n";
//        }
//        else cout << "error";
//    }
//
//}
//
//void LoadAll(unordered_map <int, Pipes>& pipes_s, unordered_map <int, KC>& kc_k)
//{
//    ifstream fin;
//    fin.open(EnterName(), ios::in);
//    if (fin.is_open())
//    {
//        char ch;
//        while (fin.get(ch))
//        {
//            cout << ch;
//        }
//    }
//    else cout << "error\n";
//    fin.close();
//}

template <typename W, typename T>
using Filter = bool(*)(const W& o, T param);
bool CheckByRepairStatus(const Pipes& p, bool UnderRepair)
{
    return p.GetStatus() == UnderRepair;
}
bool CheckByName(const KC& k, string name)
{
    return k.GetName() == name;
}
bool CheckByPercentageOfWorkshops(const KC& k, double percent)
{
    return (k.GetPercentWorkingWorkshops() >= percent);
}
template <typename W, typename T>
vector<int> FindItemsByFilter(const unordered_map <int,W>& g, Filter <W,T> f, T param)
{
    vector<int>res;
    int i = 0;
    for (const auto&  obj: g)
    {
        if (f(obj.second, param))
            res.push_back(i);
        i++;
    }
    if (res.size() == 0)
    {
        cout << "error\n";
    }
    return res;
}

void PrintMenu()
    {
    cout << "\n1. Add Pipe" << endl
        << "2. Add CS" << endl
        << "3. Save All" << endl
        << "4. Batch Edit Pipe" << endl
        << "5. Edit the CS" << endl
        << "6. Print pipes" << endl
        << "7. Print CS" << endl
        << "8. Load All" << endl
        << "9. Search by filters" << endl
        << "10. Delete Objects" << endl
        << "11. Establish a connection" << endl
        << "12. Delete a connection" << endl
        << "13. Show GTS" << endl
        << "14. Topological Sort" << endl
        << "15. The shortest path" << endl
        << "16. The maximum flow" << endl
            << "0. Exit" << endl<<endl;
    }

//void EditOnePipe(unordered_map<int, Pipes>& pipes_p)
//{
//    cout<< "please enter an ID of the pipe you want to edit: ";
//    int n;
//    cin>> n;
//    
//    cout << "0. a working pipe"<<endl<<"1. pipe under repair\n";
//    cout << "please choose to change its working status: \n";
//    int choice = GetCorrectNumber(0, 1);
//    pipes_p[n].GetStatus() = choice;
//}

void DelPipes(unordered_map<int, Pipes> &pipes_p)
{
    if (pipes_p.size() != 0)
    {
        cout << "enter an ID of the pipe you want to delete: ";
        int i;
        cin >> i;
        if (pipes_p.find(i) != pipes_p.end())
            pipes_p.erase(i);
        cout << "the pipe is deleted";
    }
    else
    {
        cout << "error\n";
    }
 }

void DelKC(unordered_map <int, KC>& kc_k)
{
    if (kc_k.size() != 0)
    {
        cout << "enter an ID of the CS you want to delete: ";
        int t;
        cin >> t;
        if (kc_k.find(t) != kc_k.end())
            kc_k.erase(t);
        cout << "the CS is deleted";
    }
    else
    {
        cout << "error\n";
    }
}
int main()
{
    Network gts =Network();
    unordered_map <int, Pipes> pipes_p;
    unordered_map <int, KC> kc_k;
    while (1)
    {
        cout << "\nChoose from the menu " << endl;
        PrintMenu();
        switch (GetCorrectNumber(0, 16))
        {
        case 1:
        {
            gts.AddPipe();
            break;
        }
        case 2:
        {
            gts.AddCS();
            break;
        }
        case 3:
        {
            if (gts.HasPipe() == false && gts.HasCs() == false)
            {
                cout << "You didn't add any pipe or CS. Do you really want to save the file?\n";
                int input;
                proverka2(input, "(1 - Yes, 0 and etc. - No): ");
                if (input != 1)
                {
                    cout << "Cancel the save\n";
                    break;
                }
            }
            string filename;
            cout << "Type filename: ";
            cin >> filename;
            ofstream fout;
            fout.open(filename, ios::out);
            if (fout.is_open())
            {
                gts.SaveToFile(fout);
                fout.close();
                cout << "The file was saved successfully\n";
            }
            else
            {
                cout << "Error saving the file!\n";
            }
            break;
        }
        case 4:
        { 
            cout << "1. Change the working status of all pipes to the opposite" << endl
                << "2. Edit one pipe" << endl;
            if (GetCorrectNumber(1, 2) == 1)
            {
                for (auto& p : pipes_p)
                {
                    p.second.RedaktPipes();
                }
            }
            else
            {
                if (gts.HasPipe())
                    gts.EditPipe();
                else
                    cout << "You don't have any pipe\n";
            }
            break;
        break;
        }
        case 5:
        {   
            if (gts.HasCs())
                gts.EditCs();
            else
                cout << "You don't have any CS\n";
            break;
        }
        case 6:
        {
            if (pipes_p.size())
            {
                for (const auto& p : pipes_p) cout << p.second << endl;
            }
            else cout << "there is no information about pipes\n ";
           

            break;
        }
        case 7:
        {
            if (kc_k.size())
            {
                for (const auto& k : kc_k) cout << k.second << endl;
            }
            else cout << "there is no information about pipes\n ";

            break;
        }
        case 8:
        {
            string filename;
            cout << "Type filename: ";
            cin >> filename;
            ifstream fin;
            fin.open(filename, ios::in);
            if (fin.is_open())
            {
                gts = Network(fin);
                fin.close();
                cout << "The file was uploaded successfully\n";
            }
            else
            {
                cout << "Error saving the file!\n";
            }
            break;
        }
        case 9:
        {
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
                if (GetCorrectNumber(1,2)== 1) {
                    for (int i : FindItemsByFilter(pipes_p, CheckByRepairStatus, false))
                        cout << pipes_p[i+1];
                }
                else
                {
                    for (int i : FindItemsByFilter(pipes_p, CheckByRepairStatus, true))
                        cout << pipes_p[i+1];
                }
                break;
            }
            case 2:
            {
                for (int i : FindItemsByFilter(kc_k, CheckByName, EnterName()))
                    cout << kc_k[i+1];
                
                break;
            }
            case 3:
            {
                for (int i : FindItemsByFilter(kc_k, CheckByPercentageOfWorkshops, GetCorrectNumber(0.00, 100.0)))
                    cout << kc_k[i+1];
                
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
            cout << "1. Pipes" << endl
                << "2. CS" << endl
                << "please choose what you want to delete: ";
            if (GetCorrectNumber(1, 2) == 1)
            {
                DelPipes(pipes_p);
            }
            else
            {
                DelKC(kc_k);
            }
            break;
        }
        case 11: 
        {
            if (gts.HasPipe() && gts.HasCs(2))
                gts.ConnectPipe();
            else
                cout << "You don't have any pipes and CS for linking.\n";
            break;
            gts.TopologicalSort();
            break;
        }
        case 12: 
        {
            if (gts.HasPipe() && gts.HasCs(2))
                gts.DisconnectPipe();
            else
                cout << "You don't have any linking\n";
            break;
        }
        case 13: 
        {
            gts.ShowNetwork();
            break;
        }
        case 14:
        {
            gts.TopologicalSort();
            break;
        }
        case 15:
        {
            gts.FindShortestPath();
            break;
        }

        case 16:
        {
            gts.FindMaxFlow();
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


 
