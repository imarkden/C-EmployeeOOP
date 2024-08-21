#include "Employee.cpp"
#include "Manager.hpp"
#include <iostream>
#include <fstream>
using namespace std;

class Manager : public Employee {
    int meetingPerWeek;
    int vacationPerYear;

public:
    //constructor
    Manager(const string& firstname, const string& lastname, double sal, int meetingperweek, int vacationperyear)
        : Employee(firstname, lastname, sal), meetingPerWeek(meetingperweek), vacationPerYear(vacationperyear) {}

    //save manager data
    void save(ofstream& fout) const override {
        fout << "Manager ";
        Employee::save(fout);
        fout << " " << meetingPerWeek << " " << vacationPerYear << endl;
    }

    //display manager data
    void display() const override {
        Employee::display();
        cout << "Meetings per Week: " << meetingPerWeek << endl
            << "Vacation Days: " << vacationPerYear << endl;
    }
};