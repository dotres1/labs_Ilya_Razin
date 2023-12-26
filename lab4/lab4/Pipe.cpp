
#include "Pipe.hpp"
#include "header.h"

int Pipe::MaxID = 0;

ostream& operator << (ostream& out, const Pipe& p) {
    out << "pipe name: " << p.kilometr_name << "\t" << "length: " << p.length << "\t"
        << "pipe diametr: " << p.diametr << "\t"
        << "pipe is remont: " << p.remont << endl;
    return out;
}

ofstream& operator << (ofstream& fout, const Pipe& p) {
    fout << "here_pipe\n" << p.id << endl << p.kilometr_name << endl <<
        p.length << endl << p.diametr << endl << p.remont << endl;
    return fout;
}

ifstream& operator >> (ifstream& fin, Pipe& p) {
    fin >> p.id;
    fin >> ws;
    getline(fin, p.kilometr_name);
    fin >> p.length >> p.diametr >> p.remont;
    return fin;
}

int Pipe::diametr_pipe() {
    cout << "diametr maybe 500, 700, 1000, 1400:";
    int d;
    while ((std::cin >> d).fail() || std::cin.peek() != '\n' || (d != 500) && (d != 700) && (d != 1000) && (d != 1400))
    {
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::cout << "Incorrect input. Please enter again: ";
    }
    std::cerr << d << std::endl;
    return d;
}


void Pipe::new_pipe()
{
    id = ++MaxID;
    cout << "New pipe\n";
    cout << "Kilometer mark: ";
    INPUT_LINE(cin, kilometr_name);
    cout << "Length(km): ";
    length = get_correct(1500., 0.);
    cout << "Pipe Diameter(mm): ";
    diametr = diametr_pipe();
    cout << "Sign in repair(0 - no or 1 - yes): ";
    remont = get_correct(true, false);
    if (remont) {
        length = 1e9;
    }
    cout << endl;
}

void Pipe::editpipe() {
    remont = !remont;
    if (remont) {
        length = 1e9;
    }
    else {
        length = get_correct(1500., 0.);
    }
    cout << endl;
}

int Pipe::getID() const {
    return id;
}

string Pipe::getKmname() const {
    return kilometr_name;
}

bool Pipe::getRepair() const {
    return remont;
}
