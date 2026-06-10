// Name: Noah Poulatian
// Date: June 10th 2026
// Assignment: Assignment 11 - Word Frequency Counter
#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include "WordEntry.h"
#include <string>
#include <unordered_map>
#include <vector>

class WordCounter {
    private:
        std::unordered_map<std::string, int> _counts;
    public:
        void AddWord(std::string word);
		int AddText(std::string sentence);
		int GetCount(std::string word);
		int GetUniqueWordCount();
		WordEntry GetMostFrequent();
		void PrintReport();
};

#endif