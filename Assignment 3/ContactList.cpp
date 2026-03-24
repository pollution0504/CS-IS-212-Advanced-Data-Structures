// Name: Noah Poulatian
// Date: 03/02/2026
// Assignment: Assignment 3 - Contact List Manager
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
// const: doesn't change the value of the variable / vector
// &: reference
void AddContact(vector<unique_ptr<string>>& contacts);
void DisplayContacts(const vector<unique_ptr<string>>& contacts);
void SearchContacts(const vector<unique_ptr<string>>& contacts);
void RemoveContact(vector<unique_ptr<string>>& contacts);

int main() {

    vector<unique_ptr<string>> contacts;
    bool hasQuit = false;
    do
    {
        int choice;
        cout<<"===== CONTACT LIST MANAGER ====="<<endl;
        cout<<"1. Add a contact"<<endl;
        cout<<"2. Display all contacts"<<endl;
        cout<<"3. Search contacts"<<endl;
        cout<<"4. Remove a contact"<<endl;
        cout<<"5. Quit"<<endl;
        cout<<"================================="<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        if (choice == 1)
            AddContact(contacts);
        
        else if (choice == 2)
            DisplayContacts(contacts);

        else if (choice == 3)
            SearchContacts(contacts);

        else if (choice == 4)
            RemoveContact(contacts);
        
        else if (choice == 5) {
            cout<<"Goodbye!";
            hasQuit = true;
        }
        
        else
            cout<<"Invalid choice. Please try again."<<endl;

    } while (!hasQuit);

    return 0;
}

void AddContact(vector<unique_ptr<string>>& contacts) {
    string contactName;
    string contactPhoneNumber;
    string contactEmail;

    cout<<"Enter name: ";
    cin>>contactName;
    cout<<"Enter phone number: ";
    cin>>contactPhoneNumber;
    cout<<"Enter email: ";
    cin>>contactEmail;

    string fullContact = contactName+" | "+contactPhoneNumber+" | "+contactEmail;
    auto newContact = make_unique<string>(fullContact);

    contacts.push_back(std::move(newContact));

    cout<<"Contact added: "<<fullContact<<endl;

}

void DisplayContacts(const vector<unique_ptr<string>>& contacts) {
    if (contacts.empty())
    {
        cout<<"No contacts to display."<<endl;
        return;
    }
    else {
        cout<<"===== CONTACT LIST ====="<<endl;
        for (int i = 0; i < contacts.size(); i++) {
            cout<<(i+1)<<". "<<contacts[i]<<endl;
        }
        cout<<"========================"<<endl;
        cout<<"Total contacts: "<<contacts.size()<<endl;
        cout<<"========================"<<endl;
    }

    return;
}

void SearchContacts(const vector<unique_ptr<string>>& contacts) {
    return;
}

void RemoveContact(vector<unique_ptr<string>>& contacts) {
    return;
}


