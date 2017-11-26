//
//  TwoOpt.cpp
//  TwoOpt
//
//  Created by Kevin Lewis on 11/26/17.
//  Copyright © 2017 Kevin Lewis. All rights reserved.
//

#include "TwoOpt.hpp"
#include <vector>
#include <cmath>
#include <iostream>

City::City(int id, double xCoord, double yCoord) {
    this->id = id;
    this->xCoord = xCoord;
    this->yCoord = yCoord;
}

City::City(int id, int xCoord, int yCoord) {
    this->id = id;
    this->xCoord = static_cast<double>(xCoord);
    this->yCoord = static_cast<double>(yCoord);
}

void City::setID(int id) {
    this->id = id;
}

int City::getID() {
    return this->id;
}

void City::setXCoord(double xCoord) {
    this->xCoord = xCoord;
}

double City::getXCoord() {
    return this->xCoord;
}

void City::setYCoord(double yCoord) {
    this->yCoord = yCoord;
}

double City::getYCoord() {
    return this->yCoord;
}

double City::getDist(City otherCity) {
    double xdist = getXCoord() - otherCity.getXCoord();
    double ydist = getYCoord() - otherCity.getYCoord();
    return sqrt(pow(xdist, 2.0) + pow(ydist, 2.0));
}

DistanceMatrix::DistanceMatrix(std::vector<City>* cities) {
    setCities(cities);
}

void DistanceMatrix::setCities(std::vector<City>* cities) {
    this->cities = cities;
}

void DistanceMatrix::fillDistMatrix() {
    int size = cities->size();
    distMatrix.reserve(size);
    for (int i = 0; i < size; i++) {
        std::vector<double> curRow;
        curRow.reserve(size);
        for (int j = 0; j < size; j++) {
            if (i == j) {
                curRow.push_back(0.0);
            }
            else {
                // Distance between this city and another
                double dist = cities->at(i).getDist(cities->at(j));
                curRow.push_back(dist);
            }
        }
        distMatrix.push_back(curRow);
    }
}

double DistanceMatrix::getDistance(int cityID1, int cityID2) {
    return distMatrix.at(cityID1).at(cityID2);
}

int main() {
    std::vector<City> a;
    City b = City(0, 3.0, 5.0);
    a.push_back(b);
    DistanceMatrix c = DistanceMatrix();
    c.setCities(&a);
    c.fillDistMatrix();
    return 0;
}