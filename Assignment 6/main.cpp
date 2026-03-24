// Name: Noah Poulatian
// Date: 3/24/26
// Assignment: Assignment 6 - Vehicle Hierarchy
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>

using namespace std;
//g++ main.cpp Car.cpp Truck.cpp Motorcycle.cpp Vehicle.cpp -o main && ./main
int main() {
    vector<unique_ptr<Vehicle>> garage;
    double pricePerGallon = 3.50;
    garage.push_back(make_unique<Car>("Toyota", "Camry", 2024, 16.0, 4));
    garage.push_back(make_unique<Truck>("Ford", "F-150", 2023, 26.0, 13000));
    garage.push_back(make_unique<Motorcycle>("Honda", "Rebel", 2024, 3.6, "Cruiser"));
    garage.push_back(make_unique<Motorcycle>("Honda", "Rebel", 2024, 3.6, "Cruiser"));

    cout<<"===== GARAGE ====="<<endl;
    for (int i = 0; i < garage.size(); i++) {
        garage[i]->DisplayVehicleInfo();
        if (i < garage.size() - 1) {
            cout<<"------------------"<<endl;
        }
    }
    cout<<"=================="<<endl;

    cout<<"===== FUEL COSTS ====="<<endl;
    cout<<fixed<<setprecision(2);
    for (int i = 0; i < garage.size(); i++) {
        cout<<garage[i]->GetYear()<<" "<<garage[i]->GetMake()<<" "<<garage[i]->GetModel()<<" - Fuel cost: $"<<garage[i]->CalculateFuelCost(pricePerGallon)<<endl;
    }
    cout<<"======================"<<endl;

    // Im learning to shorten if statements by using ? and : 
    cout<<"===== COMPARISONS ====="<<endl;
    cout<<"Vehicle 3 and Vehicle 4 are equal: "<<((*garage[2]==*garage[3]) ? "true" : "false")<<endl;
    cout<<"Vehicle 1 and Vehicle 2 are equal: "<<((*garage[0]==*garage[1]) ? "true" : "false")<<endl;
    cout<<"======================="<<endl;

    return 0;
}