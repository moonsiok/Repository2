#include "Pipes.h"
#include "Utility.h"
using namespace std;
vector <Pipes> group;
ostream& operator <<(ostream& out, const Pipes& p1)
{
    out << "\t*Pipes*\n";
    out << "the ID of the pipe: " << p1.id << endl;
    out << "the length: " << p1.length << endl;

    out << "the diameter: " << p1.diameter << endl;
    (p1.UnderRepair) ? out << "the pipe is under repair\n" : out << "the pipe works\n"; //tern operator
    return out;
}


istream& operator>>(istream& in, Pipes& p1)
{
    cout << "\t*Pipes*\n";
    p1.id = rand() % 100 + 1;//https://www.cplusplus.com/reference/cstdlib/rand/
    cout << "the ID of the new pipe: " << p1.id << endl;
    cout << "enter the length(in m): ";
    p1.length = GetCorrectNumber(1.0, 1000.0);
    cout << "enter the diameter(in mm): ";
    p1.diameter = GetCorrectNumber(1.0, 1000.0);
    (p1.UnderRepair) ? cout << "the pipe is under repair\n" : cout << "the pipe works\n";
    return in;
}

void Pipes::RedaktPipes()
{
    UnderRepair = !UnderRepair;
    cout << "the pipe's status is changed but not saved";
}

void Pipes::SavePipes()
{
    string path = "PipesAndKC.txt";
    ofstream fout;
    fout.open(path, ofstream::app);
    if (!fout.is_open())
    {
        fout << "error" << endl;
    }
    else
    {
        fout << group.size() << endl;
        for (Pipes p1 : group)

            fout << id << endl;
        fout << length << endl;
        fout << diameter << endl;
        fout << UnderRepair << endl; fout.close();
    }
}