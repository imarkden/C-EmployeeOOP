#include "Employee.hpp"

int Employee::nextId = 1;

Employee::Employee(const string& firstname, const string& lastname, double sal)
    : firstName(firstname), lastName(lastname), salary(sal), id(nextId++) {}

void Employee::save(ofstream& fout) const {
    fout << id << " " << firstName << " " << lastName << " " << salary << "\n";
}

void Employee::display() const {
    cout << "ID: " << id << "\n"
        << "First Name: " << firstName << "\n"
        << "Last Name: " << lastName << "\n"
        << "Salary: " << salary << "\n";
}

int Employee::getId() const {
    return id;
}
