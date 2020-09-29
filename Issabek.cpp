// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;
struct Truba
{
    string identificator;
    int length;
    int diameter;
    bool v_remonte = false;
};

struct KC
{
    string identificator;
    string name;
    int kol_cekhov;
    string efficiency;
};

void func(t1)
{
    Truba t1;
    cout << "enter the length" << endl;
    cin >> t1.length;
    cout << "enter the diameter" << endl;
    cin >> t1.diameter;
    bool v_remonte(false);
    if (v_remonte)
        cout << "Truba v remonte" << endl;
    else
        cout << "Truba rabotaet" << endl;
    return t1;
}
void func2(k1)
{
    KC k1;
    cout << "enter the name" << endl;
    cin >> k1.name;
    cout << "enter the number of plants" << endl;
    cin >> k1.kol_cekhov;
    cout << "enter the efficiency" << endl;
    cin >> k1.efficiency;
    return k1;
}

Truba read_from_file() {
    ifstream fin;
    fin.open("info.txt", ios::in);
    if (fin.is_open())
        Truba t1;
    fin >> t1.length >> t1.diameter;
    fin.close();
    return t1;
}
void write_to_file(Truba)
{ ofstream fout;
fout.open("filename", ios::in);
if (fout.is_open())
{
    fout >> i >> d >> ch >> str;
    fout.close();
}
getch();
return 0; }
int main()
{
    ofstream fout;
    fout.open("filename", ios::in);
    if (fout.is_open())
    {
        fout >> i >> d >> ch >> str;
        fout.close();
    }
    getch();
    return 0;
}
