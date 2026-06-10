// Name: Noah Poulatian
// Date: 6/4/2026
// Assignment: Assignment 10 - ER Triage System
#include "ERTriage.h"

using namespace std;

void ERTriage::AdmitPatient()
{
	Patient newPatient;
	
	cout<<"Enter patient name: ";
	cin>>newPatient.name;
	cout<<"Enter severity (1-5): ";
	cin>>newPatient.severity;
	cout<<"Patient"
}
int main() {
	int choice;
	
	do {
		cout<<"===== ER TRIAGE SYSTEM ====="<<endl;
		cout<<"1. Admit a new patient"<<endl;
		cout<<"2. See next patient"<<endl;
		cout<<"3. Peek at next patient"<<endl;
		cout<<"4. View waiting room"<<endl;
		cout<<"5. Count patients by severity"<<endl;
		cout<<"6. Quit"<<endl;
		cout<<"============================"<<endl;
		cout<<"Enter your choice: "<<endl;
		cin>>choice;
	
		switch(choice) {
		    case 1:
		        break;
		    case 2:
		    	break;
		    default:
		        cout << "Invalid choice. Please try again." << endl;
		}		
	}
	while (choice != 6);
	
	cout<<"System shutting down. Goodbye!"<<endl;
	return 0;
}