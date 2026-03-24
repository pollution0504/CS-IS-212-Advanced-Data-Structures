// Name: Noah Poulatian
// Date: 3/24/26
// Assignment: Assignment 6 - Vehicle Hierarchy
#include "Motorcycle.h"
#include <iostream>
using namespace std;

Motorcycle::Motorcycle(string make, string model, int year, double fuelCapacity, string style) : Vehicle(make, model, year, fuelCapacity) {
    _style = style;
}

string Motorcycle::GetStyle() const {
    return _style;
}

double Motorcycle::CalculateFuelCost(double pricePerGallon) const {
    return GetFuelCapacity() * pricePerGallon * 0.80;
}

void Motorcycle::DisplayVehicleInfo() const {
    Vehicle::DisplayVehicleInfo();
    cout<<"Type: Motorcycle"<<endl;
    cout<<"Style: "<<_style<<endl;
}