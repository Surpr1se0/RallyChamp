//
// Created by surprise on 22/02/22.
//
#include <ctime>
#include <iostream>
#include <fstream>

#ifndef RALLYCHAMP_DATA_H
#define RALLYCHAMP_DATA_H

class Data {
private:
    static const char delim = '/';
    int day, month, year;
public:
    //constructors
    Data();
    Data(int day, int month, int year);

    //access methods
    void SetDay(int day) { this->day = day; }
    void SetMonth(int month) { this->month = month; }
    void SetYear(int day) { this->day = day; }
    int GetDay() const { return day; }
    int GetMonth() const { return day; }
    int GetYear() const { return day; }

    //other methods
    void Show();
    void Update();
    void ReadFile(std::ifstream& ifs);
    void SaveFile(std::ofstream& ofs);

    //operators

    friend std::ostream& operator<<(std::ostream& os, const Data& D);
    friend std::istream& operator>>(std::istream& is, Data& D);
};

#endif //RALLYCHAMP_DATA_H
