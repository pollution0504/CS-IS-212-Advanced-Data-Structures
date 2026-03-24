// Name: Noah Poulatian
// Date: 3/22/26
// Assignment: Assignment 5 - Generic Storage Container
#include <iostream>
#include <vector>
#include <algorithm> //for find() function
using namespace std;

#ifndef STORAGE_CONTAINER_H
#define STORAGE_CONTAINER_H

template <typename T>
class StorageContainer {
    private:
        vector<T> _items;
        int _maxCapacity;
    public:
        StorageContainer(int maxCapacity) {
            _maxCapacity = maxCapacity;
        }
        void AddItem(T item) {
            if (IsFull()) {
                cout<<"Container is full. Cannot add item."<<endl;
                return;
            }
            _items.push_back(item);
            cout<<"Item added. ("<<_items.size()<<"/"<<_maxCapacity<<")"<<endl;
            return;
        }
        void RemoveItem(int index) {
            if (index < 0 || index >= _items.size()) {
                cout<<"Invalid Index."<<endl;
                return;
            }
            _items.erase(_items.begin() + index);
            cout<<"Item removed. ("<<_items.size()<<"/"<<_maxCapacity<<")"<<endl;
            return;
        }
        T GetItem(int index) const {
            if (index < 0 || index >= _items.size()) {
                cout<<"Invalid Index."<<endl;
                return T();
            }
            return _items[index];
        }
        int FindItem(T searchTerm) const {
            // using auto fixed compiling issues
            auto iterator = find(_items.begin(),_items.end(), searchTerm);
            if(iterator == _items.end()) {
                return -1;
            }
            return iterator - _items.begin();
        }
        int GetNumberOfItems() const {
            return _items.size();
        }
        int GetMaxCapacity() const {
            return _maxCapacity;
        }
        bool IsEmpty() const {
            return _items.empty();
        }
        bool IsFull() const {
            return _items.size() == _maxCapacity;
        }
        void DisplayItems() const {
            if(IsEmpty()) {
                cout<<"Container is empty."<<endl;
                return;
            }
            cout<<"===== CONTAINER CONTENTS ====="<<endl;
            for(int i = 0; i < _items.size(); i++) {
                cout<<"["<<i<<"] "<<_items[i]<<endl;
            }
            cout<<"=============================="<<endl;
            cout<<"Count: "<<_items.size()<<"/"<<_maxCapacity<<endl;
            return;
        }

};
#endif