// Name: Noah Poulatian
// Date: 3/22/26
// Assignment: Assignment 5 - Generic Storage Container
#include <iostream>
#include "StorageContainer.h"

using namespace std;

int main() {
    StorageContainer<int> Container1 = StorageContainer<int>(5);
    StorageContainer<string> Container2 = StorageContainer<string>(3);
    StorageContainer<double> Container3 = StorageContainer<double>(4);

    cout<<"===== INT CONTAINER ====="<<endl;
    Container1.AddItem(10);
    Container1.AddItem(20);
    Container1.AddItem(30);
    Container1.AddItem(40);
    Container1.AddItem(50);
    Container1.DisplayItems();
    cout<<"Search for 30:";
    if(Container1.FindItem(30) != -1){
        cout<<" found at index "<<Container1.FindItem(30)<<endl;
    }
    else {
        cout<<" not found."<<endl;
    }
    cout<<"Search for 99:";
    if(Container1.FindItem(99) != -1){
        cout<<" found at index "<<Container1.FindItem(99)<<endl;
    }
    else {
        cout<<" not found."<<endl;
    }
    Container1.RemoveItem(1);
    Container1.DisplayItems();

    cout<<"===== STRING CONTAINER ====="<<endl;
    Container2.AddItem("Alice");
    Container2.AddItem("Bob");
    Container2.AddItem("Charlie");
    Container2.AddItem("Diana");
    Container2.DisplayItems();
    cout<<"Item at index 1: "<<Container2.GetItem(1)<<endl;

    cout<<"===== DOUBLE CONTAINER ====="<<endl;
    Container3.AddItem(3.14);
    Container3.AddItem(2.72);
    Container3.AddItem(1.41);
    Container3.DisplayItems();
    cout<<"Container full: ";
    if(Container3.IsFull() == 0) {
        cout<<" false"<<endl;
    }
    else {
        cout<<" true"<<endl;
    }
    cout<<"Container empty:";
    if(Container3.IsEmpty() == 0) {
        cout<<" false"<<endl;
    }
    else {
        cout<<" true"<<endl;
    }
    
    return 0;
}