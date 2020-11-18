#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <vector>

using namespace std;
struct Pipes
{
    int id=0;  
    double  length = 0.0;
    double diameter = 0.0;
    bool UnderRepair=false;
};
 
struct KC
{
    int id = 0;
    string name;
    int kol_cekhov=0;
    int  kol_cekhov_v_rabote=0;
    int efficiency=0;
};

double GetDouble()
{
    double value;
    cin >> value;
   while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Only numbers can be entered: ";
        cin >> value;
    } 
   return value;
}

int GetInt(int value, int min, int max)
{
    while (cin.fail() || value > max || value < min)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Only numbers from " << min << " to " << max << " can be entered: ";
        cin >> value;
    }
    return value;
}

Pipes InputPipes()
{   Pipes p1;
    cout << "\t*Pipes*\n";
    p1.id = rand() % 100 + 1;//https://www.cplusplus.com/reference/cstdlib/rand/
    cout << "the ID of the new pipe: " << p1.id << endl;
    cout << "enter the length(in mm): ";
    p1.length = GetDouble();
    cout << "enter the diameter(in mm): ";
    p1.diameter = GetDouble();
    (p1.UnderRepair) ? cout <<"the pipe is under repair\n" : cout << "the pipe works\n";
    return p1;
 }

void SavePipesKC(const Pipes& p1, const KC& k1)
{   
    ofstream fout;
    fout.open("PipesAndCS.txt", ios::out);
    if (fout.is_open())
    {
        vector<int> a(9);
       
        fout << p1.id <<a[1]<< endl;
        fout << p1.length <<a[2]<< endl;
        fout << p1.diameter <<a[3]<< endl;
        fout << p1.UnderRepair <<a[4]<< endl;
        fout << k1.id <<a[5]<< endl;
        fout << k1.name <<a[6]<< endl;
        fout << k1.kol_cekhov <<a[7]<< endl;
        fout << k1.kol_cekhov_v_rabote<<a[8] << endl;
        fout << k1.efficiency <<a[9]<< endl;
        fout.close(); 
    }
    else
    {
        cout << "the file was not found" << endl;
    }
}

void PrintPipes(const Pipes& p1)
{

    cout << "\t*Pipes*\n";
    cout << "the ID of the pipe: " << p1.id << endl;
    cout << "the length: " << p1.length << endl;

    cout << "the diameter: " << p1.diameter << endl;
    (p1.UnderRepair) ? cout << "the pipe is under repair\n" : cout << "the pipe works\n"; //tern operator
}

Pipes LoadPipes()
{   
    Pipes p1;
    ifstream fin;
    fin.open("PipesAndCS.txt", ios::in);
    if (fin.is_open())
    {

        fin >> p1.id;
        fin >> p1.length;
        fin >> p1.diameter;                   
        fin >> p1.UnderRepair;
        fin.close();
    }
    else
    {
        cout << "the file was not found"<<endl;
    }
    return p1;
}

void EditPipes(Pipes& p1)
{
    p1.UnderRepair = !p1.UnderRepair;
    cout << "the pipe's status is changed but not saved";
}

KC InputKC()
{
    KC k1;
    cout << "\t*Compressor station*\n";
    k1.id = rand() % 100 + 1;
    cout << "the ID of the new pipe: " << k1.id << endl;
    cout << "enter the name: "; 
    cin.ignore(1000, '\n');
    getline(cin, k1.name); //https://cboard.cprogramming.com/cplusplus-programming/92353-cplusplus-strings-spaces.html
    cout << "enter the number of workshops: "; 
    cin >> k1.kol_cekhov;
    GetInt(k1.kol_cekhov, 0, 1000);
    cout << "enter the number of workshops in operation: "; 
    cin >> k1.kol_cekhov_v_rabote;
    int VseKolichestvo = k1.kol_cekhov;
    GetInt(k1.kol_cekhov_v_rabote, 0, VseKolichestvo);
    cout << "rate the efficiency from 0 to 10: "; 
    cin >> k1.efficiency;
    GetInt(k1.efficiency, 0, 10);
    cout << endl << "Do not forget to save the new created station! Choose 3 in the menu\n";
    return k1;
 }

//void SaveKC(const KC& k1)
//    {
//        ofstream fout;
//        
//       ofstream file("PipesAndCS.txt", ios::app);
//      //  fout.open("PipesAndCS.txt", 'a');
//        if (fout.is_open())
//        {
//            fout << k1.id << endl; 
//            fout << k1.name << endl;
//            fout << k1.kol_cekhov << endl;
//            fout << k1.kol_cekhov_v_rabote << endl;
//            fout << k1.efficiency << endl;
//            fout.close();
//        }
//         else
//        {
//        cout << "the file was not found" << endl;
//        }
//    }

void PrintKC(const KC & k1)
{
        cout << "\t*Compressor Station*\n";
        cout << "the ID of the CS: " << k1.id << endl;
        cout << "the name: " << k1.name << endl;
        cout << "the number of workshops: " << k1.kol_cekhov << endl;
        cout << "the number of workshops in operation: " << k1.kol_cekhov_v_rabote << endl;
        cout << "the efficiency: " << k1.efficiency << endl;

}

KC LoadKC()
    {
        KC k1;
        ifstream fin;
        fin.open("PipesAndCS.txt", ios::in);
        if (fin.is_open())
        {
            vector<int> a(9);
            fin >> a[4];// k1.id;
                    fin.ignore(2222, '\n');
                    getline(fin, k1.name);
                    fin >> k1.kol_cekhov;
                    fin >> k1.kol_cekhov_v_rabote;
                    fin >> k1.efficiency;
                    fin.close();
                
        }
        else
        {
            cout << "the file was not found" << endl;
        }
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
            << "8. View All" << endl
            << "0. Exit" << endl<<endl;
    }

void EditKC(KC& k1)
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
            cin >> k1.kol_cekhov_v_rabote;
            int VseKolichestvo=k1.kol_cekhov;
            GetInt(k1.kol_cekhov_v_rabote, 0, VseKolichestvo);
            cout<< "the information is changed but not saved\n";
            break;
        }
        case 'n':
        {
            break;
        }
        }
}
  
int main()
    {
        Pipes p1;
        KC k1;
        while (1)
        {   int i=0;
            cout << "\nChoose from the menu " << endl;
            PrintMenu();  
            cin >> i;
            GetInt(i, 0, 8);
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
            {//SaveKC(k1);
            SavePipesKC(p1,k1);
            
            cout << "Information was successfully saved" << endl;
            break;
            }
            case 4:
            {
            EditPipes(p1); 
            break;
            }
            case 5:
            {EditKC(k1);
            break;
            }
            case 6:
            {PrintPipes(LoadPipes());
               
            break;
            }
            case 7:
            {PrintKC(LoadKC());
            break;
            }
            case 8:
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
 
