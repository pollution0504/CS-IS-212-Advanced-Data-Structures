// Name: Noah Poulatian
// Date: 4/23/26
// Assignment: Assignment 8 - Order Processing System
#ifndef ORDERSYSTEM_H
#define ORDERSYSTEM_H

#include "Order.h"
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

class OrderSystem {
    private:
        queue<Order> _pendingOrders;
        stack<Order> _processedOrders;
        int _orderCounter;
    
    public:
        // constructor
        OrderSystem();
        // methods
        void PlaceOrder();
        void ProcessOrder();
        void UndoLastProcessed();
        void ViewPendingOrders();
        void ViewProcessedOrders();
};

#endif