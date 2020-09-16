// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using std::cout;using std::cin;
using std::string;
using std::endl;
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

void func()
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
}
void func2()
{
    KC k1;
    cout << "enter the name" << endl;
    cin >> k1.name;
    cout << "enter the number of plants" << endl;
    cin >> k1.kol_cekhov;
    cout << "enter the efficiency" << endl;
    cin >> k1.efficiency;

}
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
