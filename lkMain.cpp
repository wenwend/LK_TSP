#include<iostream>
#include<vector>
#include <fstream>
#include<string>
#include<sstream>
#include "TwoOpt.hpp"

using namespace std;

/*Delete the two vectors instead we use a city class*/
//std::vector<int> id;
//std::vector<pair<double, double> > coord;

/*Need fill the city vector for Matrix*/
std::vector<City> city;

int main() {

	/*Read Input files*/
    std::ifstream ifs;
    ifs.open("tsp_example_1.txt");
    
    std::string line;

    int n;
	double x, y;
	City temp = City(0,0,0);

    while(!ifs.eof()){
        while(std::getline(ifs,line)){
        	std::istringstream iss(line);
        	iss>>n;
        	iss>>x>>y;
        	temp = City (n,x,y);
        	cout<<"City  "<< n <<" cood is "<<x<<" "<<y<<endl;
        	city.push_back(temp);
        }

    }
    
    Trip myTrip(&city);
    myTrip.nearNeighbor();

	/*OutPut a result file*/

	return 0;
}
