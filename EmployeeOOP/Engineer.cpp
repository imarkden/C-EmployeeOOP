#include "Employee.cpp"
#include <iostream>
#include <fstream>
using namespace std;

class Engineer : public Employee {
    bool knowsCpp;
    int yearsOfExperience;
    string engineerType;

public:
    //constructor
    Engineer(const string& firstname, const string& lastname, double sal, bool knowcpp, int yearsofexp, const string& engineertype)
        : Employee(firstname, lastname, sal), knowsCpp(knowcpp), yearsOfExperience(yearsofexp), engineerType(engineertype) {}

    //save engineer data with base employee data
    void save(ofstream& fout) const override {
        fout << "Engineer ";
        Employee::save(fout);
        fout << " " << knowsCpp << " " << yearsOfExperience << " " << engineerType << "\n";
    }

    //display engineer
    void display() const override {
        Employee::display();
        cout << "Knows C++: " << (knowsCpp ? "Yes" : "No") << endl
            << "Years of Experience: " << yearsOfExperience << endl
            << "Engineer Type: " << engineerType << endl;
    }

private:
    bool knowsCpp;
    float yearsOfExperience;
    string engineerType;
};