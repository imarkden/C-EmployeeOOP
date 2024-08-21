#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Employee {
public:
    Employee(const string& firstname, const string& lastname, double sal)
        : firstName(firstname), lastName(lastname), salary(sal), id(nextId++) {}

    virtual ~Employee() = default;

    virtual void save(ofstream& fout) const {
        fout << "Employee: " << firstName << " " << lastName << ", Salary: " << salary << ", ID: " << id << endl;
    }

    virtual void display() const {
        cout << "Employee: " << firstName << " " << lastName << ", Salary: " << salary << ", ID: " << id << endl;
    }

    string getLastName() const { return lastName; }
    int getId() const { return id; }

protected:
    string firstName;
    string lastName;
    double salary;
    int id;

private:
    static int nextId;
};