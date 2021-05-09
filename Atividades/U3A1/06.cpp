#include <iostream>
using std::cin, std::cout, std::endl, std::left, std::right;

#include <string>
using std::string;

#include <fstream>
using std::ofstream, std::ifstream;

#include <iomanip>
using std::fixed, std::setw;

struct{
    string type;
    int sizeByte;
} typedef Data;

Data data[] = {
    {"char", sizeof(char)},
    {"unsigned_char", sizeof(unsigned char)},
    {"string", sizeof(string)},
    {"int", sizeof(int)},
    {"long_int", sizeof(long int)},
    {"short_int", sizeof(short int)},
    {"unsigned_int", sizeof(unsigned int)},
    {"float", sizeof(float)},
    {"double", sizeof(double)},
    {"long_double", sizeof(long double)},
    {"bool", sizeof(bool)},
    {"short", sizeof(short)},
    {"long_long", sizeof(long long)},
};

bool addData(ofstream &filler, string &type, int &size){
    if (!filler)
        return false;
    
    filler << type << ' ' << size << endl;

    return true;
}

bool impress(){
    ifstream imfile("data.dat", std::ios::in);

    if (!imfile)
        return false;
    
    Data d;

    cout << " Type " << "      Size in Bytes     " << endl;
    
    cout << fixed;
    while (imfile >> d.type >> d.sizeByte){  
        cout << left << setw(13) << d.type << ' ';
        cout << right << setw(5) << d.sizeByte << endl;
    }
    imfile.close();

    return true;
}

int main(){
    ofstream opfile("data.dat", std::ios::out);
    for(auto &i : data){
        addData(opfile, i.type, i.sizeByte);
    }
    opfile.close();

    impress();

    return 0;
}