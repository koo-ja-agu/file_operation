#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>

using std::ifstream;
using std::fixed;
using std::setprecision;
using std::ostream_iterator;
using std::istringstream;
using std::string;
using std::vector;
using std::stod;
using std::all_of;
using std::isdigit;
using std::copy;
using std::cout;
using std::endl;

bool ReadSsv(const char* ps,vector<vector<double> >& dvv);
bool isDotDigit(char ch);

int main(void){
    vector<vector<double> > data;
    if(ReadSsv("testdata.txt",data)){
        for(const auto& dat:data){
            cout << fixed << setprecision(1);
            copy(dat.begin(),dat.end(),ostream_iterator<double>(cout," "));
            cout << endl;
        }
    }
    return 0;
}

bool isDotDigit(char ch){
    if(ch == '.')
        return true;
    if(isdigit(ch))
        return true;
    return false;
}

bool ReadSsv(const char* ps,vector<vector<double> >& dvv){
    if(ps){
        ifstream ifs(ps);
        if(ifs){
            string line;
            for(int i = 0;getline(ifs,line);++i){
                string item;
                double d = 0;
                istringstream iss(line);
                vector<double> dv;
                for(int j = 0;j <= 4; j++){
                    iss >> item;
                    d = stod(item);
                    dv.push_back(d);
                }
            dvv.push_back(dv);
            }
        return true;
        }
    }
    return false;
}

