// Name: Noah Poulatian
// Date: June 10, 2026
// Assignment: Assignment 12 - Social Network

#include "SocialNetwork.h"
#include <iostream>

using namespace std;

void SocialNetwork::AddPerson(const string& name) {
    if (_friends.find(name) != _friends.end()) {
        cout<<name<<" is already in the network."<<endl;
    }
    else {
        _friends[name] = vector<string>();
        cout<<"Added "<<name<<" to the network."<<endl;
    }
}

void SocialNetwork::AddFriendship(const string& person1, const string& person2) {
    for (const auto f : _friends[person1]) {
        if (f == person2) {
            cout<<person1<<" and "<<person2<<" are already friends."<<endl;
            return;
        }
    }

    _friends[person1].push_back(person2);
    _friends[person2].push_back(person1);
    cout<<person1<<" and "<<person2<<" are now friends."<<endl;
}

void SocialNetwork::ListFriends(const string& name) const {
    if (!_friends.count(name)) {
        cout<<name<<" is not in the network."<<endl;
        return;
    }
    if (_friends.at(name).empty()) {
        cout<<name<<" has no friends yet."<<endl;
        return;
    }
    cout<<name<<"'s friends:"<<endl;
    for (const auto& f : _friends.at(name))
        cout<<"  "<<f<<endl;
}

bool SocialNetwork::AreConnected(const string& person1, const string& person2) const {
    for (const auto f : _friends.at(person1)) {
        if (f == person2) {
            return true;
        }
    }
    return false; 
}

void SocialNetwork::SuggestFriends(const string& name) const {
    return;    
}

Person SocialNetwork::GetMostConnected() const {
    Person result{"", 0};
    for (const auto& pair : _friends) {
        if (pair.second.size() > result.friendCount) {
            result.name = pair.first;
            result.friendCount = pair.second.size();
        }
    }
    return result;
}


int main() {
    SocialNetwork network;
    int choice;
    string name1, name2;

    do {
        cout<<"===== SOCIAL NETWORK ====="<<endl;
        cout<<"1. Add a person"<<endl;
        cout<<"2. Add a friendship"<<endl;
        cout<<"3. List a person's friends"<<endl;
        cout<<"4. Check if two people are connected"<<endl;
        cout<<"5. Suggest friends for a person"<<endl;
        cout<<"6. Show most connected person"<<endl;
        cout<<"7. Quit"<<endl;
        cout<<"=========================="<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch (choice) {
            case 1:
                cout<<"Enter a name: ";
                cin>>name1;
                network.AddPerson(name1);
                break;
            case 2:
                cout<<"Enter the first name: ";
                cin>>name1;
                cout<<"Enter the second name: ";
                cin>>name2;
                network.AddFriendship(name1, name2);
                break;
            case 3:
                cout<<"Enter a name: ";
                cin>>name1;
                network.ListFriends(name1);
                break;
            case 4:
                cout<<"Enter the first name: ";
                cin>>name1;
                cout<<"Enter the second name: ";
                cin>>name2;
                if (network.AreConnected(name1, name2)) {
                    cout<<name1<<" and "<<name2<<" are connected."<<endl;
                } else {
                    cout<<name1<<" and "<<name2<<" are not connected."<<endl;
                }
                break;
            case 5:
                cout<<"Enter a name: ";
                cin>>name1;
                network.SuggestFriends(name1);
                break;
            case 6: {
                Person mostConnected = network.GetMostConnected();
                if (mostConnected.name.empty()) {
                    cout<<"The network is empty."<<endl;
                } else {
                    cout<<mostConnected.name<<" has the most friends with "<<mostConnected.friendCount<<" friends."<<endl;
                }
                break;
            }
            case 7:
                cout<<"System shutting down. Goodbye!"<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    } while (choice != 7);

    cout<<"System shutting down. Goodbye!"<<endl;
    return 0;
}
