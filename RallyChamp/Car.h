//
// Created by surprise on 22/02/22.
//
#include <iostream>
#include <fstream>
#include <string>

#include "Pilot.h"

#ifndef RALLYCHAMP_CAR_H
#define RALLYCHAMP_CAR_H

class Car {
private:
    Pilot* P1, * P2;
    int id_car, number;
    std::string brand, type;
    //char designa; //designa = class (group b, 2000cc, etc...)
public:
    //constructors
    Car();
    Car(Pilot& P1, Pilot& P2, int id_car, int number, std::string brand, std::string type);
    virtual ~Car();

    //Access methods
    void SetPilotP1(Pilot* P1) { this->P1 = P1; }
    void SetPilotP2(Pilot* P2) { this->P2 = P2; }
    void SetIDCar(int id_car) { this->id_car = id_car; }
    void SetNumber(int number) { this->number = number; }
    void SetBrand(std::string brand) { this->brand = brand; }
    void SetType(std::string type) { this->type = type; }
    //void SetDesigna(char designa){this->designa = designa;}

    Pilot GetPilotP1()const { return *P1; }
    Pilot GetPilotP2()const { return *P2; }
    int GetIDCar()const { return id_car; }
    int GetNumber()const { return number; }
    std::string GetBrand()const { return brand; }
    std::string GetType()const { return type; }
    //char GetDesign()const {return designa;}

    //other methods
    void Show();
    void Update();
    bool Equal(Car C);
    void SaveFile(std::ofstream& ofs);
    void ReadFile(std::ifstream& ifs);

    //operators
    bool operator==(const Car& C);
    friend std::ostream& operator<<(std::ostream& os, const Car& C);
    friend std::istream& operator>>(std::istream& is, Car& C);
};


#endif //RALLYCHAMP_CAR_H
