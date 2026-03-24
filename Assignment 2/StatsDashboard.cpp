 // Name: Noah Poulatian
// Date: 2/23/26
// Assignment: Assignment 2 - Personal Stats Dashboard
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// ask user for information
// if any invalid information, end the program with -1
// print stat chart with name, age, gpa, letter grade, and a bar chart of gpa

// input -> double / output -> string
string GetLetterGrade(double gpa);

// input -> double / output -> void
void PrintBarChart(double gpa);

int main(){
    string name;
    int birthYear;
    double gpa;
    int CURRENT_YEAR = 2026;
    
    cout<<"Enter your name: ";
    getline(cin, name);

    cout<<"Enter your birth year: ";
    cin>>birthYear;

    if(birthYear<0) {
        cout<<"Invalid year: Please input a valid year";
        return -1;
    }

    cout<<"Enter your GPA (0.0 - 4.0): ";
    cin>>gpa;

    if(gpa<0 || gpa>4) {
        cout<<"Invalid GPA. Must be between 0.0 and 4.0.";
        return -1;
    }

    cout<<"==================================="<<endl;
    cout<<"       PERSONAL STATS DASHBOARD"<<endl;
    cout<<"==================================="<<endl;
    cout<<"Name:\t\t "<<name<<endl;
    cout<<"Age:\t\t "<<(CURRENT_YEAR-birthYear)<<endl;
    cout<<"GPA:\t\t "<<setprecision(2)<<fixed<<gpa<<endl;
    cout<<"Letter Grade:\t "<<GetLetterGrade(gpa)<<endl;
    cout<<"==================================="<<endl;
    cout<<"GPA Bar Chart:"<<endl;
    PrintBarChart(gpa);
    cout<<"==================================="<<endl;

    return 0;
}

string GetLetterGrade(double gpa) {
    if(gpa>1){
        if(gpa>2){
            if(gpa>3){
                if(gpa>=3.5){
                    return "A";
                }
                return "B";
            }
            return "C";
        }
        return "D";
    }
    return "F";
}

void PrintBarChart(double gpa) {
    double number_of_hash = gpa/0.25;
    for(int i = 0; i<number_of_hash; i++){
        cout<<"#";
    }
    cout<<" ("<<gpa<<")"<<endl;
}
