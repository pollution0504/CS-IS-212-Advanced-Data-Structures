// Name: Noah Poulatian
// Date: 6/4/2026
// Assignment: Assignment 10 - ER Triage System
#define ERTRIAGE_H
#ifndef ERTRIAGE_H

#include "Patient.h"

#include <iostream>
#include <string>
#include <queue>
#include <utility>

class ERTriage {
	private:
		std::priority_queue<std::pair<int, Patient>> _waitingRoom;
		int _patientCounter = 0;
	public:
		void AdmitPatient();
		void SeeNextPatient();
		void PeekNextPatient();
		void ViewWaitingRoom();
		void CountBySeverity();
};

#endif