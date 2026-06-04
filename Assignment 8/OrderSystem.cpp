// Name: Noah Poulatian
// Date: May 10, 2026
// Assignment: Assignment 8 - Order Processing System

#include "OrderSystem.h"

using namespace std;

OrderSystem::OrderSystem()
{
    _orderCounter = 0;
}

void OrderSystem::PlaceOrder()
{
    Order newOrder;
    string item;
    double price;

    cout<<"Enter item name: ";
    // to prevent "enter" from entering in
    getline(cin>>ws, item);

    cout<<"Enter price: ";
    cin>>price;

    _orderCounter++;
    newOrder.id = _orderCounter;
    newOrder.item = item;
    newOrder.price = price;

    _pendingOrders.push(newOrder);

    cout<<fixed<<setprecision(2);
    cout<<"Order #"<<newOrder.id<<" placed: "<<newOrder.item<<" ($"<<newOrder.price<<")"<<endl;
}

void OrderSystem::ProcessOrder()
{
    if (_pendingOrders.empty()) {
        cout<<"No orders to process."<<endl;
        return;
    }

    Order current = _pendingOrders.front();
    _pendingOrders.pop();
    _processedOrders.push(current);

    cout<<fixed<<setprecision(2);
    cout<<"Processed Order #"<<current.id<<": "<<current.item<<" ($"<<current.price<<")"<<endl;
}

void OrderSystem::UndoLastProcessed()
{
    if (_processedOrders.empty())
    {
        cout<<"No processed orders to undo."<<endl;
        return;
    }

    Order undone = _processedOrders.top();
    _processedOrders.pop();
    _pendingOrders.push(undone);

    cout<<fixed<<setprecision(2);
    cout<<"Undo Order #"<<undone.id<<": "<<undone.item<<" ($"<<undone.price<<") - added back to queue"<<endl;
}

void OrderSystem::ViewPendingOrders()
{
    if (_pendingOrders.empty())
    {
        cout<<"No pending orders."<<endl;
        return;
    }

    cout<<"===== PENDING ORDERS ====="<<endl;

    queue<Order> temp = _pendingOrders;
    int count = 0;

    cout<<fixed<<setprecision(2);
    while (!temp.empty())
    {
        Order o = temp.front();
        temp.pop();
        cout<<"Order #"<<o.id<<": "<<o.item<<" ($"<<o.price<<")"<<endl;
        count++;
    }

    cout<<"==========================="<<endl;
    cout<<"Total pending: "<<count<<endl;
}

void OrderSystem::ViewProcessedOrders()
{
    if (_processedOrders.empty())
    {
        cout<<"No processed orders."<<endl;
        return;
    }

    cout<<"===== PROCESSED ORDERS (most recent first) ====="<<endl;

    stack<Order> temp = _processedOrders;
    int count = 0;

    cout<<fixed<<setprecision(2);
    while (!temp.empty())
    {
        Order o = temp.top();
        temp.pop();
        cout<<"Order #"<<o.id<<": "<<o.item<<" ($"<<o.price<<")"<<endl;
        count++;
    }

    cout<<"================================================="<<endl;
    cout<<"Total processed: "<<count<<endl;
}

int main()
{
    OrderSystem system;
    int choice;

    do
    {
        cout<<"===== ORDER PROCESSING SYSTEM ====="<<endl;
        cout<<"1. Place a new order"<<endl;
        cout<<"2. Process next order"<<endl;
        cout<<"3. Undo last processed order"<<endl;
        cout<<"4. View pending orders"<<endl;
        cout<<"5. View processed orders"<<endl;
        cout<<"6. Quit"<<endl;
        cout<<"===================================="<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
        case 1:
            system.PlaceOrder();
            break;
        case 2:
            system.ProcessOrder();
            break;
        case 3:
            system.UndoLastProcessed();
            break;
        case 4:
            system.ViewPendingOrders();
            break;
        case 5:
            system.ViewProcessedOrders();
            break;
        case 6:
            cout<<"System shutting down. Goodbye!"<<endl;
            break;
        default:
            cout<<"Invalid choice. Please try again."<<endl;
        }

    } while (choice != 6);

    return 0;
}