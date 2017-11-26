#include<iostream>
#include<vector>
#include <fstream>
#include<string>
#include<sstream>
#include "TwoOpt.hpp"

//#include "lk.hpp"

using namespace std;

std::vector<int> id;
std::vector<pair<double, double> > coord;

int main() {
    int i=0;
    std::ifstream ifs;
    ifs.open("tsp_example_3.txt");

    std::string line;
    int array[500];
    int n;
	double x, y;

    while(!ifs.eof()){
        std::getline(ifs,line);

        std::istringstream input(line);
        std::string number;
	i++;
        while(std::getline(input,number,' ')){
            std::istringstream iss(number);
            iss>>n;
            id.push_back(n);
            iss>>x>>y;
            coord.push_back(make_pair(x, y));
            
	    //cout<<"done reading";
        }

    }
	cout<<"Total is "<<i-1<<" lines.";

	return 0;
}
