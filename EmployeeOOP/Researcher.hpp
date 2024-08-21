#ifndef Employee_hpp
#define Employee_hpp

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Researcher {
public:
    Researcher(const string& firstname, const string& lastname, double sal);

    virtual ~Researcher() = default;
    virtual void save(ofstream& fout) const;
    virtual void display() const;

protected:
    string firstName;
    string lastName;
    double salary;

private:
    static int nextId;
};

#endif /* Employee_hpp */