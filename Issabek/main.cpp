#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;
struct Pipes
{
    int id;  
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

int RightValue (int &value)
{
do
{
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Only the numbers can be entered: ";
    cin >> value;
} while (cin.fail() || isNumber(value));
return value;
}

Pipes InputPipes()
{
    Pipes p1;

    
    cout << "\t*Pipes*\n";
    p1.id = rand() % 100 + 1;//https://www.cplusplus.com/reference/cstdlib/rand/
    cout << "ID of the new pipe: " << p1.id << endl;
    cout << "enter the length(in mm)\n";
    RightValue(p1.length);
    cout << "enter the diameter(in mm)\n";
    RightValue(p1.diameter);
    
        bool in_repairing(true);
        if (in_repairing)
            cout << "the pipe works\n" << endl;
        else
            cout << "the pipe is under repair\n" << endl;

        cout << "Do not forget to save the new created pipe! Choose 3 in the menu\n"; 

    return p1;
    }


Pipes LoadPipes()
{
    Pipes p1;
    ifstream fin;
    
    
    fin.open("pipes.txt", ios::in);
    if (fin.is_open())
    {
        fin >> p1.id;
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
        fout << p1.id << endl;
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
    cout << "ID of the pipe: " << p1.id << endl;
    cout << "the length: " << p1.length << endl;

    cout << "the diameter: " << p1.diameter << endl;

    bool in_repairing(true);
    if (in_repairing)
        cout << "the pipe works" << endl;
    else
        cout << "the pipe is under repair" << endl;
   
}

int EditPipe(const Pipes& p1)
{
    while (1)
    {
        int a; int length = 0; int diameter = 0;
        cin >> a;
        switch (a)
        {
        case 1:
        {cout << "enter the length. "; RightValue(length);  
        break;
        }
        case 2:
        { cout << "enter the diameter. "; RightValue(diameter);  
        break;
        }
        case 3:
        {bool in_repairing = true;
        break;
        }
        case 0:
        {SavePipes(p1);
        break;
        }
        return 0;
        }
    }
}

    KC InputKC()
{
        KC k1; 
    cout << "\t*Compressor station*\n";
    cout << "enter the name: ";
    cin >> k1.name;
   
    int kol_cekhov = 0; int kol_cekhov_v_rabote = 1;
    do 
    {
     cout << "enter the number of workshops. ";
        do
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "only the number can be entered: ";
            cin >> k1.kol_cekhov;
        } while (cin.fail() || isNumber(k1.kol_cekhov));
        cout << "enter the number of workshops in operation. ";
        do
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "only the number can be entered: ";
            cin >> k1.kol_cekhov_v_rabote;
        } while (cin.fail() || isNumber(k1.kol_cekhov_v_rabote));
     
    } while (k1.kol_cekhov_v_rabote > k1.kol_cekhov);
    
    cout << "rate the efficiency from 0 to 10. "; 
    do 
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "only numbers 1-10 can be entered: ";
        cin >> k1.efficiency;
    } while (k1.efficiency > 10 || k1.efficiency < 0);
    cout <<endl<< "Do not forget to save the new created station! Choose 3 in the menu\n";
    return k1;
}
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
   
    void SaveKC(const KC& k1)
    {
        ofstream fout;
        fout.open("KC.txt", 'w');
        fout << "\t*Compressor Station*\n";
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
        cout << "\t*Compressor Station*\n";
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
        cout << "\n1. Add Pipes" << endl
            << "2. Add the CS" << endl
            << "3. Save All" << endl
            << "4. Edit Pipes" << endl
            << "5. Edit the CS" << endl
            << "6. View All Objects" << endl
            << "0. Exit" << endl<<endl;

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
            { SavePipes(p1);
            SaveKC(k1);
            cout << "Information was successfully saved" << endl;
            break;
            }
            case 4:
            {cout << "Enter the ID of the pipe you want to edit. ";
            int enter_id;
            RightValue(enter_id);
            if (p1.id == enter_id)
            {
                cout << "Which parameter do you want to edit?\n";
                int PipeEdit = 0;
                do
                {
                    cout << "1. The length" << endl
                        << "2. The diameter" << endl
                        << "3. The repairing status" << endl
                        << "0. Save All" << endl;
                    cin >> PipeEdit;
                } while (PipeEdit < 0 || PipeEdit>3);
                EditPipe(p1); SavePipes(p1);
            }
            else
            {
                cout << "Not the real ID!";
            }

            break;
            }
            case 5:
            {//EditKC();
            break;
            }
            case 6:
            {PrintPipes(LoadPipes());
            PrintKC(LoadKC());
               
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
 
