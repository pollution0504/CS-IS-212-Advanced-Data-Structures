// Name: Noah Poulatian
// Date: 3/24/26
// Assignment: Assignment 6 - Vehicle Hierarchy
#include "Truck.h"
#include <iostream>
using namespace std;

Truck::Truck(string make, string model, int year, double fuelCapacity, double towingCapacity) : Vehicle(make, model, year, fuelCapacity) {
    _towingCapacity = towingCapacity;
}

double Truck::GetTowingCapacity() const {
    return _towingCapacity;
}

double Truck::CalculateFuelCost(double pricePerGallon) const {
    return GetFuelCapacity() * pricePerGallon * 1.15;
}

void Truck::DisplayVehicleInfo() const {
    Vehicle::DisplayVehicleInfo();
    cout<<"Type: Truck"<<endl;
    cout<<"Towing Capacity: "<<_towingCapacity<<" lbs"<<endl;
}