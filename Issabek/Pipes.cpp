#include "Pipes.h"
#include "Util.h"
#include "Utility.h"
#include <iostream>
#include <fstream>

using namespace std;
int Pipes::PMaxID = 0;
int Pipes::Maxid = 0;
std::string name;
int diameter;
int length;
bool UnderRepair;
int startid;
int endid;

ostream& operator <<(ostream& out, const Pipes& p)
{
    out << "\t*Pipes*\n";
    out << "the name: " << p.name << endl;
    out << "the length: " << p.length << endl;
    out << "the diameter: " << p.diameter << endl;
    (p.UnderRepair) ? out << "the pipe is under repair\n" : out << "the pipe works\n"; //tern operator
    return out;
}


istream& operator>>(istream& in, Pipes& p)
{
    cout << "\t*Pipes*\n";
    std::cout << "enter the name: " ;
    std::cin.ignore(256, '\n');
    getline(in, p.name, '\n');
    cout << "enter the length(in m): ";
    p.length = GetCorrectNumber(1.0, 1000.0);
    cout << "enter the diameter(in mm): ";
    p.diameter = GetCorrectNumber(1.0, 1000.0);
    (p.UnderRepair) ? cout << "the pipe is under repair\n" : cout << "the pipe works\n";
    p.startid = -1;
    p.endid = -1;
    return in;
}

Pipes::Pipes()
{
    id = Maxid++;
    name = "name";
    length = 0.0;
    diameter = 0.0;
}

double Pipes::GetWeight() const
{
    return length;
}

void Pipes::RedaktPipes()
{
    UnderRepair = !UnderRepair;
    cout << "the pipe's status is changed but not saved";
}

int Pipes::GetID() const
{
    return id;
}

int Pipes::GetMaxID()
{
    return Maxid;
}

string Pipes::GetName() const
{
    return name;
}
int Pipes::GetDiameter() const
{
    return diameter;
}
int Pipes::GetLength() const
{
    return length;
}
bool Pipes::GetStatus() const
{
    return UnderRepair;
}

int Pipes::GetProductivity() const
{
    return length;
}


Pipes::Pipes(std::ifstream& fin)
{
    fin.ignore();
    std::getline(fin, name);
    fin
        >> length
        >> diameter
        >> UnderRepair
        >> startid
        >> endid;
}

void Pipes::SaveToFile(std::ofstream& fout)
{
    fout << name << '\n'
        << length << '\n'
        << diameter << '\n'
        << UnderRepair << '\n'
        << startid << '\n'
        << endid << '\n';
}
void Pipes::Edit()
{
    if (UnderRepair)
        std::cout << "\nThe pipe does not need to be repaired.\n";
    else
        std::cout << "\nThe pipe is broken!\n";
    std::cout << "Whta do you want to do with pipe?\n"
        << "1 - To fix/To break\n"
        << "0 and etc. - Exit\n";
    int input;
    proverka2(input, "Enter: ");
    switch (input)
    {
    case 1:
    {
        UnderRepair = !UnderRepair;
        std::cout << "Pipe repair completed successfully!\n";
    }
    default:
    {
        std::cout << "You are out of editing mode.\n";
        break;
    }
    }
}
void Pipes::IsBroken()
{
    UnderRepair = false;
}
