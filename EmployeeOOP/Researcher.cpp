#include "Employee.cpp"
#include <iostream>
#include <fstream>
using namespace std;

class Researcher : public Employee {
    string phdSchool;
    string phdTopic;
public:

    //constructor
    Researcher(const string& firstname, const string& lastname, double sal, const string& phdschool, const string& phdtopic)
        : Employee(firstname, lastname, sal), phdSchool(phdschool), phdTopic(phdtopic) {}

    //save researcher data
    void save(ofstream& fout) const override {
        fout << "Researcher ";
        Employee::save(fout);
        fout << " " << phdSchool << " " << phdTopic << endl;
    }

    //display researcher data
    void display() const override {
        Employee::display();
        cout << "PhD School: " << phdSchool << endl
            << "PhD Topic: " << phdTopic << endl;
    }

private:
    string phdShool;
    string phdTopic;
};