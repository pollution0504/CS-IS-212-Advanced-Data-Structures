// Name: Noah Poulatian
// Date: 3/24/26
// Assignment: Assignment 6 - Vehicle Hierarchy
#include "Vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle(string make, string model, int year, double fuelCapacity) {
    _make = make;
    _model = model;
    _year = year;
    _fuelCapacity = fuelCapacity;
}

string Vehicle::GetMake() const {
    return _make;
}

string Vehicle::GetModel() const {
    return _model;
}

int Vehicle::GetYear() const {
    return _year;
}

double Vehicle::GetFuelCapacity() const {
    return _fuelCapacity;
}
// no calculateFuelCost in cpp file
// no virtual before method in cpp file
void Vehicle::DisplayVehicleInfo() const {
    cout<<_year<<" "<<_make<<" "<<_model<<endl;
    cout<<"Fuel Capacity: "<<_fuelCapacity<<" gal"<<endl;
}

Vehicle::~Vehicle() {}

bool Vehicle::operator==(const Vehicle& other) const {
    return (_make == other._make && _model == other._model && _year == other._year);
}