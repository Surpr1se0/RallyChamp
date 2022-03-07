#define _CRT_SECURE_NO_WARNINGS 0

#include "Data.h"

Data::Data() {

    time_t now = time(0); //actual date
    tm* ltm = localtime(&now); //tm -> struct that represents the actual date/hour of the calendar
    day = ltm->tm_mday; //tm_mday = day of the month
    month = 1 + ltm->tm_mon; //tm_mon = n of months since Jan.
    year = 1900 + ltm->tm_year; //tm_year = n of years since 1900
}

Data::Data(int day, int month, int year)
    :day(day), month(month), year(year)
{
}

void Data::Show() {
    std::cout << "Data: " << day << delim << month << delim << year << std::endl;
}

void Data::Update() {
    this->day = day;
    this->month = month;
    this->year = year;
}

void Data::ReadFile(std::ifstream& ifs) {
    char delim;
    ifs >> day >> delim >> month >> delim >> year;
}

void Data::SaveFile(std::ofstream& ofs) {
    ofs << day << delim << month << delim << year;
}

std::ostream& operator<<(std::ostream& os, const Data& D) {
    os << D.day << Data::delim << D.month << Data::delim << D.year;
    return os;
}

std::istream& operator>>(std::istream& is, Data& D) {
    char delim;
    is >> D.day >> delim >> D.month >> delim >> D.year;
    is.ignore(); //ignore enter or ('\n)
    return is;
}
