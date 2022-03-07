#include "Car.h"

#include "Car.h"

Car::Car() {

}

Car::Car(Pilot& P1, Pilot& P2, int id_car, int number, std::string brand, std::string type)
    :brand(brand), type(type)
{
    P1 = P1;
    P2 = P2;
}

Car::~Car() {

}

void Car::Show() {

}

void Car::Update() {

}

bool Car::Equal(Car C) {
    return (id_car == C.id_car);
}

void Car::SaveFile(std::ofstream& ofs) {
    P1->SaveFile(ofs);
    P1->SaveFile(ofs);
    ofs << id_car << number << brand << type;
}


void Car::ReadFile(std::ifstream& ifs) {
    P1->ReadFile(ifs);
    P2->ReadFile(ifs);

    ifs >> id_car;
    ifs.ignore();

    ifs >> number;
    ifs.ignore();

    getline(ifs, brand, ';');
    getline(ifs, type, ';');
}

bool Car::operator==(const Car& C)
{
    return (id_car == C.id_car);
}


std::ostream& operator<<(std::ostream& os, const Car& C) {
    os << *C.P1 << ";" << *C.P2 << ";" << C.id_car << ";" << C.number << ";" << C.number << ";" << C.brand;

    return os;
}

std::istream& operator>>(std::istream& is, Car& C) {
    char delim;
    is >> *C.P1 >> delim >> *C.P2 >> delim >> C.id_car >> delim >> C.number >> delim >> C.brand;
    return is;
}

