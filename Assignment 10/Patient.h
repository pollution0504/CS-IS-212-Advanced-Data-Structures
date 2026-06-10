// Name: Noah Poulatian
// Date: 6/4/2026
// Assignment: Assignment 10 - ER Triage Systems
#ifndef PATIENT_H
#define PATIENT_H

#include <string>

struct Patient {
	int id;
	std::string name;
	int severity;

	bool operator<(const Patient& other) const
	{
		return id < other.id;
	}
};



#endif