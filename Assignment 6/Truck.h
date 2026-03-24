// Name: Noah Poulatian
// Date: 3/24/26
// Assignment: Assignment 6 - Vehicle Hierarchy
#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"
#include <string>

class Truck : public Vehicle {
    private:
        double _towingCapacity;

    public:
        Truck(string make, string model, int year, double fuelCapacity, double towingCapacity);
        double GetTowingCapacity() const;
        double CalculateFuelCost(double pricePerGallon) const override;
        void DisplayVehicleInfo() const override;
};

#endif