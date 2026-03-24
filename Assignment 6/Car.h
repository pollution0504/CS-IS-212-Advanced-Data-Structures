// Name: Noah Poulatian
// Date: 3/24/26
// Assignment: Assignment 6 - Vehicle Hierarchy
#ifndef CAR_H
#define CAR_H
// use include vehicle.h to connect this to the derived class
#include "Vehicle.h"
#include <string>

class Car : public Vehicle {
    private:
        int _numDoors;
    
    public:
        Car(string make, string model, int year, double fuelCapacity, int numDoors);
        int GetNumDoors() const;
        double CalculateFuelCost(double pricePerGallon) const override;
        void DisplayVehicleInfo() const override;
};

#endif