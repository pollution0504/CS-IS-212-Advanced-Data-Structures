// Name: Noah Poulatian
// Date: 3/24/26
// Assignment: Assignment 6 - Vehicle Hierarchy
#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>

using namespace std;

class Vehicle {
    private:
    // Underline for private variables
        string _make;
        string _model;
        int _year;
        double _fuelCapacity;

    public:
        Vehicle(string make, string model, int year, double fuelCapacity);
        string GetMake() const;
        string GetModel() const;
        int GetYear() const;
        double GetFuelCapacity() const;
        virtual double CalculateFuelCost(double pricePerGallon) const = 0;
        virtual void DisplayVehicleInfo() const;
        virtual ~Vehicle();
        bool operator==(const Vehicle& other) const;

};

#endif