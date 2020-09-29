#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;
struct Pipes
{
    string identificator;
    int length;
    int diameter;
    bool in_repairing = false;
};

struct KC
{
    string identificator;
    string name;
    int kol_cekhov;
    int  kol_cekhov_v_rabote;
    int efficiency;
};

/*Pipes InputPipes()
{
    Pipes p1;
    cout << "\t*Pipes*\n";
    cout << "enter the length: " ;
    cin >> p1.length;
    cout << "enter the diameter: " ;
    cin >> p1.diameter;
    bool in_repairing(true);
    if (in_repairing)
        cout << "the pipe works" << endl;
    else
        cout << "the pipe is under repair" << endl;
    return p1;
}*/
Pipes LoadPipes()
{
    ifstream fin;
    fin.open("pipes.txt", ios::in);

    Pipes p1;
    
    fin >> p1.length;
    
    fin >> p1.diameter;
    fin.close();
    return p1;
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
void SavePipes(const Pipes& p1)
{
    ofstream fout;
    fout.open("pipes.txt", ios::out);
   // fout << "\t*Pipes*\n";
    fout <<  p1.length<<endl;

    fout << p1.diameter << endl;

    bool in_repairing(true);
    if (in_repairing)
        fout << "the pipe works" << endl;
    else
        fout << "the pipe is under repair" << endl;
    fout.close();
}
KC InputKC()
{
    KC k1;
    cout << "\t*KC*\n";
    cout << "enter the name: ";
    cin >> k1.name;
    cout << "enter the number of workshops: ";
    cin >> k1.kol_cekhov;
    cout << "enter the number of workshops in operation: " ;
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
void PrintKC(const KC& k1)
{
    cout << "\t*KC*\n";
    cout << "enter the name: " << k1.name << endl;
    cout << "enter the number of workshops: "<< k1.kol_cekhov << endl;
    cout << "enter the number of workshops in operation: "<< k1.kol_cekhov_v_rabote << endl;
    while (k1.kol_cekhov_v_rabote > k1.kol_cekhov)
    {
        cout << "the number of workshops in operation cannot exceed the number of workshops in general. please enter again:\n";
        cout << "enter the number of workshops: " << k1.kol_cekhov << endl;
        cout << "enter the number of workshops in operation: " << k1.kol_cekhov_v_rabote << endl;
    }
    cout << "rate the efficiency from 0 to 10: " << k1.efficiency << endl;
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

int main()
{
   
    Pipes p1= LoadPipes();
    KC k1 = InputKC();
    PrintPipes(p1);
    SavePipes(p1);
    PrintKC(k1);
    SaveKC(k1);
   
    _getch(); //https://vscode.ru/prog-lessons/esli-konsol-zakryivaetsya-posle-vyipolneniya-programmyi.html
    return 0;
}
