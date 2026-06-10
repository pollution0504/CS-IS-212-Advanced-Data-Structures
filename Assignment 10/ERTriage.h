// Name: Noah Poulatian
// Date: 6/4/2026
// Assignment: Assignment 10 - ER Triage System
#ifndef ERTRIAGE_H
#define ERTRIAGE_H

#include "Patient.h"

#include <iostream>
#include <string>
#include <queue>
#include <utility>

class ERTriage {
	private:
		std::priority_queue<std::pair<int, Patient>> _waitingRoom;
		int _patientCounter;
	public:
		ERTriage();
		void AdmitPatient();
		void SeeNextPatient();
		void PeekNextPatient();
		void ViewWaitingRoom();
		void CountBySeverity();
};

#endif