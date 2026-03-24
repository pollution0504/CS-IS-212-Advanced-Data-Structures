// Name: Noah Poulatian
// Date: 3/9/26
// Assignment: Assignment 4 - Fitness Tracker
#include <iostream>
#include <vector>
#ifndef FitnessTracker
#define FitnessTracker
using namespace std;

enum ExerciseType {
    Cardio,
    Strength,
    Flexibility,
    Sports
};

struct Workout {
    string name;
    ExerciseType type;
    int durationMinutes;
    int caloriesBurned;
};

class FitnessTracker {
    private:
        vector<unique_ptr<Workout>> _workouts;

    public:
        
        void newWorkout(string name, ExerciseType type, int durationMinutes, int caloriesBurned);
};

#endif