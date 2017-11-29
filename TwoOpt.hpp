//
//  TwoOpt.hpp
//  TwoOpt
//
//  Created by Kevin Lewis on 11/26/17.
//  Copyright © 2017 Kevin Lewis. All rights reserved.
//

#ifndef TwoOpt_hpp
#define TwoOpt_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>

class City{
private:
    int id;
    double xCoord;
    double yCoord;
    bool visited;
    
public:
    City(int, double, double);
    City(int, int, int);
    void setID(int);
    int getID();
    void setXCoord(double);
    double getXCoord();
    void setYCoord(double);
    double getYCoord();
    void setVisited(bool);
    bool getVisited();
    
    /*********************************************************************
     ** Name: getDist
     ** Description: Returns the distance between this city and another
     ** Output: dist data
     *********************************************************************/
    int getDist(City);
    
};

class DistanceMatrix{
private:
    std::vector< std::vector<int> > distMatrix;
    std::vector<City>* cities;
public:
    DistanceMatrix(std::vector<City>*);
    /*********************************************************************
     ** Name: setCities
     ** Description: Stores the vector of cities, will also fill out the 
     ** distance matrix;
     ** Input: City vector
     ** Output: None
     *********************************************************************/
    void setCities(std::vector<City>*);
    /*********************************************************************
     ** Name: Fill Distance Matrix
     ** Description: fills out the distance matrix based on the cities vector
     ** Input: None
     ** Output: None
     *********************************************************************/
    void fillDistMatrix();
    int getDistance(int, int);
};

class Trip{
private:
    DistanceMatrix dMatrix;
    std::vector<City>* cities;
    std::vector<City*> optTour;
    std::vector<City*> testTour;
    void exchangeCities(int, int);
    double calculateTourLength(std::vector<City*>);
    
public:
    Trip(std::vector<City>*);
    /*********************************************************************
     ** Name: Nearest neighbor
     ** Description: fills out the optimal tour based on the nearest neighbor
     ** algorithim.
     ** Input: None
     ** Output: None
     *********************************************************************/
    void nearNeighbor();
    void runTwoOpt();
    
    /*********************************************************************
     ** Name: nearest neighbor
     ** Description: Initializes the tour based on the nearest neighbor
     ** Input: double
     ** Output: None
     *********************************************************************/
    void initTour();
    void printTour(std::ofstream &);
    double calculateOptTourLength();
};

#endif /* TwoOpt_hpp */
