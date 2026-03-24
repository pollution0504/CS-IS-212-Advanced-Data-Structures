// Name: Noah Poulatian
// Date: 3/24/26
// Assignment: Assignment 6 - Vehicle Hierarchy
#include "Car.h"
#include <iostream>
using namespace std;

Car::Car(string make, string model, int year, double fuelCapacity, int numDoors) : Vehicle(make, model, year, fuelCapacity) {
    _numDoors = numDoors;
}

int Car::GetNumDoors() const {
    return _numDoors;
}

double Car::CalculateFuelCost(double pricePerGallon) const {
    return GetFuelCapacity() * pricePerGallon;
}

void Car::DisplayVehicleInfo() const {
    Vehicle::DisplayVehicleInfo();
    cout<<"Type: Car"<<endl;
    cout<<"Doors: "<<_numDoors<<endl;
}

