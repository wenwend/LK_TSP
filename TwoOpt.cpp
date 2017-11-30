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

void City::setVisited(bool statusIn){
    visited = statusIn;
}

bool City::getVisited(){
    return visited;
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
    int size = (int) cities->size();
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


Trip::Trip(std::vector<City>* cities)
    :dMatrix(cities){
        
        this->cities = cities;
        dMatrix.fillDistMatrix();
        optTour.resize(cities->size());
        testTour.resize(cities->size());
        for (auto& n : *cities)
            n.setVisited(false);
}

void Trip::nearNeighbor(){
    City* nearNeigh;
    
    optTour.at(0) = &cities->at(0);
    cities->at(0).setVisited(false);
    
    for(int i = 0; i <= (int) optTour.size() - 2; i++){
        nearNeigh = NULL;
        
        for(int j = 1; j <= (int) cities->size() - 1; j++){
            
            // Check if the city is already on the tour. If it isn't, and no neighbor has
            // been chosen, then use it as the nearest neighber. If a nearest neighbor already
            // exists, check if this new city is closer.
            if(!cities->at(j).getVisited()){
                if(nearNeigh == NULL)
                    nearNeigh = &cities->at(j);
                
                else{
                    if(dMatrix.getDistance(optTour.at(i)->getID(), cities->at(j).getID()) <
                       dMatrix.getDistance(optTour.at(i)->getID(), nearNeigh->getID())) {
                           nearNeigh = &cities->at(j);
                       }
                }
            }
        }
        nearNeigh->setVisited(true);
        optTour.at(i + 1) = nearNeigh;
    }
    testTour = optTour;
}
void Trip::runTwoOpt() {
    double virtualLength = 0;
    double oldLength = calculateTourLength(optTour);
    for (int i = 0; i < optTour.size(); i++) {
        for (int j = i + 1; j < optTour.size(); j++) {
            virtualLength = calcVirtTourLength(i, j);
            if(virtualLength < oldLength){
                exchangeCities(i, j);
                optTour = testTour;
                oldLength = virtualLength;
            }
        }
    }
}

double Trip::calculateTourLength(std::vector<City*> tour) {
    if (tour.size() == 1) {
        return 0;
    }
    double tourLength = 0;
    for (int i = 1; i < tour.size(); i++) {
        tourLength += dMatrix.getDistance(tour.at(i)->getID(),
            tour.at(i-1)->getID());
    }
    tourLength += dMatrix.getDistance(tour.at(tour.size()-1)->getID(),
        tour.at(0)->getID());
    return tourLength;
}

double Trip::calcVirtTourLength(int i, int j){
    double tourLength = 0;
    
    if (i == j || j == optTour.size() - 1) {
        return INFINITY;
    }
    for (int k = 0; k < i; k++) {
        tourLength += dMatrix.getDistance(optTour.at(k)->getID(),
                                          optTour.at(k+1)->getID());
    }
    
    tourLength += dMatrix.getDistance(optTour.at(i)->getID(),
                                     optTour.at(j)->getID());
    for (int h = j; h > i + 1; h--) {
        tourLength += dMatrix.getDistance(optTour.at(h)->getID(),
                                          optTour.at(h-1)->getID());
    }
    
    tourLength += dMatrix.getDistance(optTour.at(i+1)->getID(),
                                      optTour.at(j+1)->getID());
    
    for (int k = j + 1; k < optTour.size() - 1; k++) {
        tourLength += dMatrix.getDistance(optTour.at(k)->getID(),
                                          optTour.at(k+1)->getID());
    }
    
    tourLength += dMatrix.getDistance(optTour.back()->getID(),
                                      optTour.at(0)->getID());
    
    return tourLength;
}

double Trip::calculateOptTourLength() {
    return calculateTourLength(optTour);
}

void Trip::exchangeCities(int i, int j) {
    if (i == j) {
        return;
    }    
    for (int k = 0; k < i; k++) {
        testTour.at(k) = optTour.at(k);
    }
    int inc = i;
    for (int h = j; h >= i; h--) {
        testTour.at(inc) = optTour.at(h);
        inc++;
    }
    for (int k = j + 1; k < optTour.size(); k++) {
        testTour.at(k) = optTour.at(k);
    }
}

void Trip::printTour(std::ofstream &outputFile) {
    for (int i = 0; i < optTour.size(); i++) {
        outputFile << optTour.at(i)->getID() << std::endl;
    }
}
