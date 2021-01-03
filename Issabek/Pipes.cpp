#include "Pipes.h"
#include "Util.h"
#include "Utility.h"
#include <iostream>
#include <fstream>

using namespace std;
int Pipes::PMaxID = 1;
int Pipes::Maxid = 1;
std::string name;
int diameter;
int length;
bool UnderRepair;
int startid;
int endid;

ostream& operator <<(ostream& out, const Pipes& p1)
{
    out << "\t*Pipes*\n";
 //   out << "the ID of the pipe: " << p1.idPipes << endl;
    out << "the length: " << p1.length << endl;
    out << "the diameter: " << p1.diameter << endl;
    (p1.UnderRepair) ? out << "the pipe is under repair\n" : out << "the pipe works\n"; //tern operator
    return out;
}


istream& operator>>(istream& in, Pipes& p1)
{
    cout << "\t*Pipes*\n";
    //cout << "the ID of the new pipe: " << p1.idPipes << endl;
    cout << "enter the length(in m): ";
    p1.length = GetCorrectNumber(1.0, 1000.0);
    cout << "enter the diameter(in mm): ";
    p1.diameter = GetCorrectNumber(1.0, 1000.0);
    (p1.UnderRepair) ? cout << "the pipe is under repair\n" : cout << "the pipe works\n";
    p1.startid = -1;
    p1.endid = -1;
    return in;
}

std::ifstream& operator>>(std::ifstream& fin, Pipes& p1)
{
    fin >> p1.idPipes >> p1.length >> p1.diameter >> p1.UnderRepair;
    return fin;
}

std::ofstream& operator<<(std::ofstream& fout, const Pipes& p1)
{
    fout << p1.idPipes << endl << p1.length << endl << p1.diameter << endl << p1.UnderRepair << endl;
    return fout;
}

Pipes::Pipes()
{
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
    return idPipes;
}

int Pipes::GetMaxID()
{
    return PMaxID;
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
