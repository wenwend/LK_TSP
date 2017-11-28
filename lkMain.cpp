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

int main() {

	/*Need fill the city vector for Matrix*/
	std::vector<City> city;

	/*Read Input files*/
    std::ifstream ifs;

    ifs.open("tsp_example_1.txt");
	if (!ifs) {
		std::cout << "Unable to open file" << std::endl;
		return -1;
	}
    
    std::string line;

    int n;
	double x, y;

    while(!ifs.eof()){
        while(std::getline(ifs,line)){
        	std::istringstream iss(line);
        	iss>>n;
        	iss>>x>>y;
        	City temp = City (n,x,y);
        	cout<<"City  "<< n <<" cood is "<<x<<" "<<y<<endl;
        	city.push_back(temp);
        }
    }
    
    Trip myTrip(&city);
    myTrip.nearNeighbor();
	myTrip.printTour();

	/*OutPut a result file*/

	return 0;
}
