// Name: Noah Poulatian
// Date: 6/4/2026
// Assignment: Assignment 10 - ER Triage System
#include "ERTriage.h"

using namespace std;

ERTriage::ERTriage(){
	_patientCounter = 0;
}

void ERTriage::AdmitPatient()
{
	Patient newPatient;
	
	cout<<"Enter patient name: ";
	cin.ignore();
	getline(cin, newPatient.name); 
	cout<<"Enter severity (1-5): ";
	cin>>newPatient.severity;
	if(newPatient.severity > 5 || newPatient.severity < 1 ) {
		cout<<"Invalid severity. Must be between 1 and 5."<<endl;
		return;
	}

	_patientCounter++;
	newPatient.id = _patientCounter;
	cout<<"Patient #"<<newPatient.id<<" admitted: "<<newPatient.name<<" (Severity "<<newPatient.severity<<")"<<endl;
	_waitingRoom.push({newPatient.severity, newPatient});
	return;
}

void ERTriage::SeeNextPatient()
{
	if(_waitingRoom.empty()){
		cout<<"No patients waiting."<<endl;
		return;
	}

	Patient patient = _waitingRoom.top().second;
	_waitingRoom.pop(); 
	cout<<"Now seeing Patient #"<<patient.id<<": "<<patient.name<<" (Severity "<<patient.severity<<")"<<endl;
	return;
}

void ERTriage::PeekNextPatient()
{
	if(_waitingRoom.empty()){
		cout<<"No patients waiting."<<endl;
		return;
	}

	Patient patient = _waitingRoom.top().second;
	cout<<"Next up: Patient #"<<patient.id<<": "<<patient.name<<" (Severity "<<patient.severity<<")"<<endl;
	return;
}

void ERTriage::ViewWaitingRoom()
{
	if(_waitingRoom.empty()){
		cout<<"No patients waiting."<<endl;
		return;
	}

	priority_queue<pair<int, Patient>> tempWR = _waitingRoom;
	int tempWRSize = tempWR.size();
	cout<<"===== WAITING ROOM (highest severity first) ====="<<endl;
	while (!tempWR.empty()) {
		Patient patient = tempWR.top().second;
		cout<<"Patient #"<<patient.id<<": "<<patient.name<<" (Severity "<<patient.severity<<")"<<endl;
		tempWR.pop();
	}
	cout<<"================================================="<<endl;
	cout<<"Total waiting: "<<tempWRSize<<""<<endl;
	return;
}

void ERTriage::CountBySeverity()
{
	int severity;
	priority_queue<pair<int, Patient>> tempWR = _waitingRoom;
	int severityCounter = 0;
	cout<<"Enter severity (1-5): ";
	cin>>severity;
	if(severity > 5 || severity < 1 ) {
		cout<<"Invalid severity. Must be between 1 and 5."<<endl;
		return;
	}
	
	while (!tempWR.empty()) {
		Patient patient = tempWR.top().second;
		if (patient.severity == severity) {
			severityCounter++;
		}
		tempWR.pop();
	}
	cout<<"Patients at severity "<<severity<<": "<<severityCounter<<endl;
}
int main() {
	int choice;
	ERTriage EmergencyRoom;
	do {
		cout<<"===== ER TRIAGE SYSTEM ====="<<endl;
		cout<<"1. Admit a new patient"<<endl;
		cout<<"2. See next patient"<<endl;
		cout<<"3. Peek at next patient"<<endl;
		cout<<"4. View waiting room"<<endl;
		cout<<"5. Count patients by severity"<<endl;
		cout<<"6. Quit"<<endl;
		cout<<"============================"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
	
		switch(choice) {
		    case 1:
		        EmergencyRoom.AdmitPatient();
				break;
		    case 2:
		    	EmergencyRoom.SeeNextPatient();
				break;
			case 3:
				EmergencyRoom.PeekNextPatient();
				break;
			case 4:
				EmergencyRoom.ViewWaitingRoom();
				break;
			case 5:
				EmergencyRoom.CountBySeverity();
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