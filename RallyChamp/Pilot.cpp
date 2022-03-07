#include "Pilot.h"

Pilot::Pilot() = default;

Pilot::Pilot(std::string pilot_name, int pilot_age, Data date_birth, int pilot_id)
    :pilot_name(pilot_name), pilot_age(pilot_age), date_birth(date_birth), pilot_id(pilot_id)
{
}

Pilot::~Pilot() {

}

void Pilot::Show() {
    std::cout << "Pilot: " << pilot_name << ";" << pilot_age << ";" << date_birth << ";" << pilot_id;
}

void Pilot::Update() {
    this->pilot_name = pilot_name;
    this->pilot_age = pilot_age;
    this->date_birth = date_birth;
    this->pilot_id = pilot_id;
}

void Pilot::SaveFile(std::ofstream & ofs) {
    char delim;
    //ofs << pilot_name << delim << pilot_age << delim << date_birth << delim << pilot_id;
}

void Pilot::ReadFile(std::ifstream & ifs) {
    char delim;
    ifs >> pilot_name >> delim >> pilot_age >> delim >> date_birth >> delim >> pilot_id;
}

std::ostream& operator<<(std::ostream & os, const Pilot & P) {
    os << P.pilot_name << ";" << P.pilot_age << ";" << P.date_birth << ";" << P.pilot_id;
    return os;
}


std::istream& operator>>(std::istream & is, Pilot & P) {
    char delim;
    is >> P.pilot_name >> delim >> P.pilot_age >> delim >> P.date_birth >> delim >> P.pilot_id;
    is.ignore(); //ignore enter or ('\n)
    return is;
}
