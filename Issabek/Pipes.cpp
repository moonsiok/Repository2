#include "Pipes.h"
#include "Utility.h"
using namespace std;
int Pipes::PMaxID = 1;
ostream& operator <<(ostream& out, const Pipes& p1)
{
    out << "\t*Pipes*\n";
    out << "the ID of the pipe: " << p1.idPipes << endl;
    out << "the length: " << p1.length << endl;
    out << "the diameter: " << p1.diameter << endl;
    (p1.UnderRepair) ? out << "the pipe is under repair\n" : out << "the pipe works\n"; //tern operator
    return out;
}


istream& operator>>(istream& in, Pipes& p1)
{
    cout << "\t*Pipes*\n";
    cout << "the ID of the new pipe: " << p1.idPipes << endl;
    cout << "enter the length(in m): ";
    p1.length = GetCorrectNumber(1.0, 1000.0);
    cout << "enter the diameter(in mm): ";
    p1.diameter = GetCorrectNumber(1.0, 1000.0);
    (p1.UnderRepair) ? cout << "the pipe is under repair\n" : cout << "the pipe works\n";
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
//int PMaxID = 0001;
Pipes::Pipes()
{
   idPipes = PMaxID++;
    length = 0.0;
    diameter = 0.0;
    UnderRepair = false;
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

void Pipes::SetStart(int new_start)
{
    start = new_start;
}

void Pipes::SetEnd(int new_end)
{
    end = new_end;
}

int Pipes::GetStart() const
{
    return start;
}

int Pipes::GetEnd() const
{
    return end;
}





