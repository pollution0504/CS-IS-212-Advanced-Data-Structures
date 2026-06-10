// Name: Noah Poulatian
// Date: 6/4/2026
// Assignment: Assignment 10 - ER Triage Systems
#define PATIENT_H
#ifndef PATIENT_H

struct Patient {
	int id;
	std::string name;
	int severity;
};

bool operator<(const Patient& other) const
{
    return id < other.id;
}

#endif