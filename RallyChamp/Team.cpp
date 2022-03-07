#include "Team.h"

//
// Created by surprise on 22/02/22.
//

#include "Team.h"

Team::Team() = default;

Team::Team(std::string name, int points, list<Pilot*> ListPilot, list<Car*> ListCar)
    :name(name), points(points)
{
    listPilot = ListPilot;
    listCar = ListCar;
}

Team::~Team() {
    auto it = listPilot.begin();
    while (it != listPilot.end())
    {
        delete (*it);
        ++it;
    }
    listPilot.clear();

    auto it1 = listCar.begin();
    while (it1 != listCar.end())
    {
        delete (*it1);
        ++it;
    }
}

void Team::AddPilot(Pilot * P) {
    listPilot.push_back(P);
}

void Team::RemovePilot(int pilot_id) {
    auto P = [&](Pilot* ListPilot) {return ListPilot->GetPilotId() == pilot_id; };
    auto it = find_if(listPilot.begin(), listPilot.end(), P);
    if (it != listPilot.end())
    {
        delete (*it);
        listPilot.erase(it);
    }
}

void Team::AddCar(Car * C) {
    listCar.push_back(C);
}

void Team::RemoveCar(int carID) {
    auto C = [&](Car* ListCar) {return ListCar->GetIDCar() == carID; };
    auto it = find_if(listCar.begin(), listCar.end(), C);
    if (it != listCar.end())
    {
        delete (*it);
        listCar.erase(it);
    }
}

void Team::SaveFile(ofstream & ofs) {
    for (auto& ListCar : listCar)
    {
        ofs << "1:";
        ListCar->SaveFile(ofs);
    }
    for (auto& ListPilot : listPilot)
    {
        ofs << "2:";
        ListPilot->SaveFile(ofs);
    }
    ofs << endl;
}

void Team::ReadFile(ifstream & ifs) {
    while (!ifs.eof())
    {
        Car* C;
        Pilot* P;
        string aux;
        int type;
        getline(ifs, aux, ':');
        //type = atoi(aux)            //CONFIRMAR ISTO AQUI!
        ifs >> type;

        if (type == 1)
        {
            C = new Car;
            C->ReadFile(ifs);
            listCar.push_back(C);
        }
        else if (type == 2)
        {
            P = new Pilot;
            P->ReadFile(ifs);
            listPilot.push_back(P);
        }
    }
}

ofstream& operator<<(ofstream & os, const Team & T) {
    for (auto& ListCar : T.listCar)
    {
        os << ListCar;
    }
    for (auto& ListPilot : T.listPilot)
    {
        os << ListPilot;
    }
    os << T.name << ";" << T.points;
    return os;
}

istream& operator>>(ifstream & is, Team & T) {
    int type;
    Car* C;
    Pilot* P;
    cout << "New Car (1) or New Pilot (2): ";
    (is >> type).ignore();
    if (type == 2)
    {
        P = new Pilot;
    }
    else if (type == 1)
    {
        C = new Car;
    }
    else
        cout << "ERROR! - not a valid number";
    return is;
}
