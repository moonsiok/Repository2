// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
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
    return 0;
};
void func2(int k1)
{
    KC k1;
    cout << "enter the name" << endl;
    cin >> k1.name;
    cout << "enter the number of plants" << endl;
    cin >> k1.kol_cekhov;
    cout << "enter the efficiency" << endl;
    cin >> k1.efficiency;
    return k1;
};
int main()
{

}

