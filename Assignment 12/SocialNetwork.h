// Name: Noah Poulatian
// Date: June 10, 2026
// Assignment: Assignment 12 - Social Network

#ifndef SOCIALNETWORK_H
#define SOCIALNETWORK_H
#include "Person.h"
#include <unordered_map>
#include <vector>   
#include <string>

using namespace std;

class SocialNetwork {
    private:
        unordered_map<string, vector<string>> _friends;
    public:
        void AddPerson(const string& name);
        void AddFriendship(const string& person1, const string& person2);
        void ListFriends(const string& name) const;
        bool AreConnected(const string& person1, const string& person2) const;
        void SuggestFriends(const string& name) const;
        Person GetMostConnected() const;
};

#endif