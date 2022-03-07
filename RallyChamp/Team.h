//
// Created by surprise on 22/02/22.
//
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <list>

#include "Pilot.h"
#include "Car.h"

#ifndef RALLYCHAMP_TEAM_H
#define RALLYCHAMP_TEAM_H

using namespace std;

class Team {
private:
    std::string name;
    int points;
    list <Pilot*> listPilot;
    list <Car*> listCar;
public:
    //constructors
    Team();
    Team(std::string name, int points, list<Pilot*> listPilot, list<Car*> listCar);
    virtual ~Team();

    //Access Methods
    string GetName()const { return name; }
    int GetPoints()const { return points; }
    list<Pilot*> GetListPilot() const { return listPilot; }
    list<Car*> GetListCar() const { return listCar; }

    void SetName(string name) { this->name = name; }
    void SetPoints(int points) { this->points = points; }

    //Other Methods
    void AddPilot(Pilot* P);
    void RemovePilot(int pilot_id);
    void AddCar(Car* C);
    void RemoveCar(int carID);

    void SaveFile(ofstream& ofs);
    void ReadFile(ifstream& ifs);
    friend ofstream& operator<<(ofstream& os, const Team& T);
    friend istream& operator>>(ifstream& is, Team& T);
};

#endif //RALLYCHAMP_TEAM_H
