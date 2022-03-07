//
// Created by surprise on 22/02/22.
//
#include <iostream>
#include "Data.h"

#ifndef RALLYCHAMP_PILOT_H
#define RALLYCHAMP_PILOT_H


class Pilot {
private:
    Data date_birth;
    std::string pilot_name;
    int pilot_age;
    int pilot_id;
    static const char delim = ';';
    //probably a variable to add won races
    //Add later a variable with times, points, etc
public:
    //constructors
    Pilot();
    Pilot(std::string name, int age, Data date_birth, int pilot_id);
    virtual ~Pilot();

    //access methods
    void SetName(std::string pilot_name) { this->pilot_name = pilot_name; }
    void SetPilotID(int pilot_id) { this->pilot_id = pilot_id; }
    void SetAge(int age) { this->pilot_age = pilot_age; }

    std::string GetName()const { return pilot_name; }
    int GetAge()const { return pilot_age; }
    Data GetDate()const { return date_birth; } //why?
    int GetPilotId()const { return pilot_id; }

    //other methods
    void Show();
    void Update();
    void SaveFile(std::ofstream& ofs);
    void ReadFile(std::ifstream& ifs);

    //operators
    friend std::ostream& operator<<(std::ostream& os, const Pilot& P);
    friend std::istream& operator>>(std::istream& is, Pilot& P);
};

#endif //RALLYCHAMP_PILOT_H
