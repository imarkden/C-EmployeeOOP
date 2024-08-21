#include "Employee.cpp"
#include <iostream>
#include <fstream>
using namespace std;

class Manager : public Employee {
public:
    Manager(const string& firstname, const string& lastname, double sal, int meetingperweek, int vacationperyear)
        : Employee(firstname, lastname, sal), meetingPerWeek(meetingperweek), vacationPerYear(vacationperyear) {}

    void save(ofstream& fout) const override {
        fout << endl << "Position: Manager " << endl;
        Employee::save(fout);
        fout << "Meeting Per Week: " << meetingPerWeek << endl
             << "Vacation Per Year: " << vacationPerYear << endl << endl;
    }

    void display() const override {
        cout << "Position: Manager " << endl;
        Employee::display();
        cout << "Meetings per Week: " << meetingPerWeek << endl
             << "Vacation Days: " << vacationPerYear << endl;
    }

private:
    int meetingPerWeek;
    int vacationPerYear;
};
