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

class City{
private:
    int id;
    double xCoord;
    double yCoord;
    
public:
    City(int, double, double);
    void setID(int);
    int getID();
    void setXCoord(double);
    double getXCoord();
    void setYCoord(double);
    double getYCoord();
    
    /*********************************************************************
     ** Name: getDist
     ** Description: Returns the distance between this city and another
     ** Output: dist data
     *********************************************************************/
    double getDist(City);
    
};

class DistanceMatrix{
private:
    std::vector<std::vector<double>> distMatrix;
    std::vector<City> cities;
public:
    void addCity(City);
    /*********************************************************************
     ** Name: setCities
     ** Description: Stores the vector of cities, will also fill out the 
     ** distance matrix;
     ** Input: City vector
     ** Output: None
     *********************************************************************/
    void setCities(std::vector<City>);
    /*********************************************************************
     ** Name: Fill Distance Matrix
     ** Description: fills out the distance matrix based on the cities vector
     ** Input: None
     ** Output: None
     *********************************************************************/
    void fillDistMatrix();
};

class Trip{
private:
    std::vector<City> cities;
    std::vector<City*> optTour;
    std::vector<City*> testTour;
    
    /*********************************************************************
     ** Name: Nearest neighbor
     ** Description: fills out the optimal tour based on the nearest neighbor
     ** algorithim.
     ** Input: None
     ** Output: None
     *********************************************************************/
    void nearNeighbor();
    
public:
    /*********************************************************************
     ** Name: nearest neighbor
     ** Description: Initializes the tour based on the nearest neighbor
     ** Input: double
     ** Output: None
     *********************************************************************/
    void initTour();
    
    
};

#endif /* TwoOpt_hpp */
