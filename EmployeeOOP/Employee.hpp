#ifndef Employee_hpp
#define Employee_hpp

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Employee {
public:
    Employee(const string& firstname, const string& lastname, double sal);

    virtual ~Employee() = default;
    virtual void save(ofstream& fout) const;
    virtual void display() const;

    int getId() const;

protected:
    string firstName;
    string lastName;
    double salary;
    int id;

private:
    static int nextId;
};

#endif /* Employee_hpp */