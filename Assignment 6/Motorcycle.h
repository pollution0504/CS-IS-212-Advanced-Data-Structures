// Name: Noah Poulatian
// Date: 3/24/26
// Assignment: Assignment 6 - Vehicle Hierarchy
#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include "Vehicle.h"
#include <string>

class Motorcycle : public Vehicle {
    private:
        string _style;

    public:
        Motorcycle(string make, string model, int year, double fuelCapacity, string style);
        string GetStyle() const;
        double CalculateFuelCost(double pricePerGallon) const override;
        void DisplayVehicleInfo() const override;
};

#endif