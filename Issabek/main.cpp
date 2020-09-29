#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;
struct Pipes
{
    string identificator;
    int length=0;
    int diameter=0;
    bool in_repairing = false;
};

struct KC
{
    string identificator;
    string name;
    int kol_cekhov=0;
    int  kol_cekhov_v_rabote=0;
    int efficiency=0;
};
bool isNumber(char Symbol)//https://pyatnitsev.ru/2011/11/21/isnumber/
{
        if (Symbol >= '0' && Symbol <= '9')
            return true;
        else
            return false;
    }

Pipes InputPipes()
{
    
    
    Pipes p1; int l = 0; int d = 0;
    cout << "\t*Pipes*\n";
        cout << "enter the length(in mm)\n";
        
        do
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Only the value in mm can be entered: ";
        cin >> p1.length;
    } while (cin.fail() || isNumber(p1.length));
   
    cout << "enter the diameter(in mm)\n";
    
    do
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Only the value in mm can be entered: ";
        cin >> p1.diameter;
    } while (cin.fail() || isNumber(p1.diameter));

    bool in_repairing(true);
    if (in_repairing)
        cout << "the pipe works" << endl;
    else
        cout << "the pipe is under repair" << endl;
    return p1;
}
Pipes LoadPipes()
{
    Pipes p1;
    ifstream fin;
    fin.open("pipes.txt", ios::in);
    if (fin.is_open())
    {
        fin >> p1.length;
        fin >> p1.diameter;
        fin.close();
    }
    return p1;
}

void SavePipes(const Pipes& p1)
{
    ofstream fout;
    fout.open("pipes.txt", ios::out);
    if (fout.is_open())
    {
        fout << p1.length << endl;

        fout << p1.diameter << endl;

        bool in_repairing(true);
        if (in_repairing)
            fout << "the pipe works" << endl;
        else
            fout << "the pipe is under repair" << endl;

        fout.close();
    }
}
void PrintPipes(const Pipes& p1)
{

    cout << "\t*Pipes*\n";
    cout << "enter the length: " << p1.length << endl;

    cout << "enter the diameter: " << p1.diameter << endl;

    bool in_repairing(true);
    if (in_repairing)
        cout << "the pipe works" << endl;
    else
        cout << "the pipe is under repair" << endl;
}

/*void EditPipes(const Pipes& p1)
{
    cout << "1. Edit the length" << endl
        << "2. Edit the diameter" << endl
        << "3. Edit the condition of the pipe" << endl;
    int i = 0;
    cin >> i;
    switch (i)
    {
    case 1:
    {cout << "enter the length: " << p1.length << endl;
    break;
    }
    case 2:
    { cout << "enter the diameter: " << p1.diameter << endl;
    break;
    }
    case 3:
    {bool in_repairing = true;
    break;


    }

    }
    */

    KC LoadKC()
    {
        KC k1;
        ifstream fin;
        fin.open("KC.txt", ios::in);
        if (fin.is_open())
        {
            fin >> k1.name;
            fin >> k1.kol_cekhov;
            fin >> k1.kol_cekhov_v_rabote;
            fin >> k1.efficiency;
            fin.close();
        }
        return k1;
    }
    KC InputKC()
    {
        KC k1;
        cout << "\t*KC*\n";
        cout << "enter the name: ";
        cin >> k1.name;
        cout << "enter the number of workshops: ";
        cin >> k1.kol_cekhov;
        cout << "enter the number of workshops in operation: ";
        cin >> k1.kol_cekhov_v_rabote;
        while (k1.kol_cekhov_v_rabote > k1.kol_cekhov)
        {
            cout << "the number of workshops in operation cannot exceed the number of workshops in general. please enter again:\n";
            cout << "enter the number of workshops: ";
            cin >> k1.kol_cekhov;
            cout << "enter the number of workshops in operation: ";
            cin >> k1.kol_cekhov_v_rabote;
        }
        cout << "rate the efficiency from 0 to 10: ";
        cin >> k1.efficiency;

        return k1;
    }
    void SaveKC(const KC& k1)
    {
        ofstream fout;
        fout.open("KC.txt", 'w');
        fout << "\t*KC*\n";
        fout << "enter the name: " << k1.name << endl;
        fout << "enter the number of workshops: " << k1.kol_cekhov << endl;
        fout << "enter the number of workshops in operation: " << k1.kol_cekhov_v_rabote << endl;
        while (k1.kol_cekhov_v_rabote > k1.kol_cekhov)
        {
            fout << "the number of workshops in operation cannot exceed the number of workshops in general. please enter again:\n";
            fout << "enter the number of workshops: " << k1.kol_cekhov << endl;
            fout << "enter the number of workshops in operation: " << k1.kol_cekhov_v_rabote << endl;
        }
        fout << "rate the efficiency from 0 to 10: " << k1.efficiency << endl;
    }
    void PrintKC(const KC & k1)
    {
        cout << "\t*KC*\n";
        cout << "enter the name: " << k1.name << endl;
        cout << "enter the number of workshops: " << k1.kol_cekhov << endl;
        cout << "enter the number of workshops in operation: " << k1.kol_cekhov_v_rabote << endl;
        while (k1.kol_cekhov_v_rabote > k1.kol_cekhov)
        {
            cout << "the number of workshops in operation cannot exceed the number of workshops in general. please enter again:\n";
            cout << "enter the number of workshops: " << k1.kol_cekhov << endl;
            cout << "enter the number of workshops in operation: " << k1.kol_cekhov_v_rabote << endl;
        }
        cout << "rate the efficiency from 0 to 10: " << k1.efficiency << endl;
    }

    
    void PrintMenu()
    {
        cout << "1. Add Pipes" << endl
            << "2. Add the CS" << endl
            << "3. View All Objects" << endl
            << "4. Edit Pipes" << endl
            << "5. Edit the CS" << endl
            << "6. Save All" << endl
            << "0. Exit" << endl;

    }
    int main()
    {
        Pipes p1;
        KC k1;
        while (1)
        {
            PrintMenu();
            int i = 0;
            cin >> i;
            switch (i)
            {
            case 1:
            {p1 = InputPipes();
            break;
            }
            case 2:
            {k1 = InputKC();
            break;
            }
            case 3:
            {p1 = LoadPipes();
            //k1=LoadKC();
            break;
            }
            case 4:
            {//EditPipes();
            break;
            }
            case 5:
            {//EditKC();
            break;
            }
            case 6:
            {SavePipes(p1);
            SaveKC(k1);
            break;
            }
           
            case 0:
            {return 0;
            break;
            }
            return 0;
            }
           
            
        }
        _getch(); //https://vscode.ru/prog-lessons/esli-konsol-zakryivaetsya-posle-vyipolneniya-programmyi.html
        return 0;
    }
 /* = LoadPipes();
             KC k1 = InputKC();
             PrintPipes(p1);
             SavePipes(p1);
             PrintKC(k1);
             SaveKC(k1);
            */
