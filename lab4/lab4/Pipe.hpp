

#ifndef Pipe_hpp
#define Pipe_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

class Pipe  // �����
{
private:
    int id;
    static int MaxID;
    string kilometr_name;
    double length;
    int diametr;
    bool remont;

public:
    int getID() const;
    string getKmname() const;
    bool getRepair() const;


    void new_pipe();
    void editpipe();

    static int diametr_pipe();

    friend class PipeAndKC;
    friend std::ostream& operator << (std::ostream& out, const Pipe& p);
    friend std::ofstream& operator << (std::ofstream& fout, const Pipe& p);
    friend std::ifstream& operator >> (std::ifstream& fin, Pipe& p);
};
#endif /* Pipe_hpp */
