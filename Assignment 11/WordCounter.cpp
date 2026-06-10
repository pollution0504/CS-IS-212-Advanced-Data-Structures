// Name: Noah Poulatian
// Date: June 10th 2026
// Assignment: Assignment 11 - Word Frequency Counter

#include "WordCounter.h"
#include <sstream>
using namespace std;

void WordCounter::AddWord(std::string word) {
    _counts[word]++;
    return;
}
int WordCounter::AddText(std::string sentence){
    stringstream ss(sentence);
    string word;
    int count = 0;
    while (ss >> word) {
        AddWord(word);
        count++;
    }
    return count;

}
int WordCounter::GetCount(std::string word){
    if (_counts.count(word)) {
        return _counts[word];
    }
    return 0;
}
int WordCounter::GetUniqueWordCount(){
    return _counts.size();
}
WordEntry WordCounter::GetMostFrequent(){
    if (_counts.empty()) {
        return {"", 0};
    }
    WordEntry max;
    max.count = -1;
    for (auto entry : _counts) {
        if (entry.second > max.count) {
            max.word = entry.first;
            max.count = entry.second;
        }
    }
    return max;
}
void WordCounter::PrintReport(){
    if (GetUniqueWordCount() == 0) {
        cout<<"(no words recorded)"<<endl;
        return;
    }
    for (auto entry : _counts) {
        cout<<entry.first<<": "<<entry.second<<endl;
    }
}
int main() {
	int choice;
	WordCounter wordCounter;
    string sentence;
    WordEntry frequent;
	do {
        cout<<"===== WORD FREQUENCY COUNTER ====="<<endl;
        cout<<"1. Add a line of text"<<endl;
        cout<<"2. Look up a word's count"<<endl;
        cout<<"3. Show most frequent word"<<endl;
        cout<<"4. Show unique word count"<<endl;
        cout<<"5. Print full report"<<endl;
        cout<<"6. Quit"<<endl;
        cout<<"=================================="<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Enter a line of text: ";
                cin.ignore();
                getline(cin, sentence);
                cout<<"Added "<<wordCounter.AddText(sentence)<<" words."<<endl;
                break;
            case 2:
                cout<<"Enter a word to look up: ";
                cin>>sentence;
                cout<<"\""<<sentence<<"\" appears "<<wordCounter.GetCount(sentence)<<" times."<<endl;
                break;
            case 3:
                frequent = wordCounter.GetMostFrequent();
                cout<<"Most frequent word: \""<<frequent.word<<"\" ("<<frequent.count<<" times)"<<endl;
                break;
            case 4:
                cout<<"Unique words recorded: "<<wordCounter.GetUniqueWordCount()<<endl;
                break;
            case 5:
                wordCounter.PrintReport();
                break;
            case 6:
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    while (choice != 6);
    
    cout<<"System shutting down. Goodbye!"<<endl;
    return 0;

}