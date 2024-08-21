#include "pch.h"
#include "Employee.hpp"
#include "Manager.hpp"
#include "Engineer.hpp"
#include "Researcher.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include "Manager.cpp"
#include "Engineer.cpp"
#include "Researcher.cpp"

using namespace std;

// Main program prototypes
void SaveEmployee(const vector<unique_ptr<Employee>>& database, const string& filename);
void RemoveEmployee(vector<unique_ptr<Employee>>& database);
void NewEmployee(vector<unique_ptr<Employee>>& database);
void DisplayEmployee(const vector<unique_ptr<Employee>>& database);

int main() {
    vector<unique_ptr<Employee>> database;
    int choice;

    while (true) {
        cout << "1) Add an Employee" << endl
            << "2) Delete an Employee" << endl
            << "3) Save Database" << endl
            << "4) Display Employees" << endl
            << "5) Exit" << endl;
        cin >> choice;
        while (cin.fail() || choice < 1 || choice > 5) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input." << endl
                << "Choose from 1 to 5." << endl;
            cin >> choice;
        }
        switch (choice) {
        case 1:
            NewEmployee(database);
            break;
        case 2:
            if (database.empty()) {
                cout << "Database is empty. Cannot delete." << endl;
            }
            else {
                RemoveEmployee(database);
            }
            break;
        case 3:
            SaveEmployee(database, "database.txt");
            break;
        case 4:
            DisplayEmployee(database);
            break;
        case 5:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }

    return 0;
}

void NewEmployee(vector<unique_ptr<Employee>>& database) {
    int choice;
    cout << "Add an Employee:" << endl
        << "1) Manager" << endl
        << "2) Engineer" << endl
        << "3) Researcher" << endl;
    cin >> choice;
    while (cin.fail() || choice < 1 || choice > 3) {
        cin.clear();
        cin.ignore();
        cout << "Invalid input." << endl
            << "Choose from 1 to 3." << endl;
        cin >> choice;
    }

    string firstName, lastName;
    double salary;
    cin.ignore();

    do {
        cout << "Enter first name: ";
        getline(cin, firstName);
        if (!isAlphabetic(firstName)) {
            cout << "Invalid input. First name should only contain letters." << endl;
        }
    } while (!isAlphabetic(firstName));

    do {
        cout << "Enter last name: ";
        getline(cin, lastName);
        if (!isAlphabetic(lastName)) {
            cout << "Invalid input. Last name should only contain letters." << endl;
        }
    } while (!isAlphabetic(lastName));

    cout << "Enter salary: ";
    cin >> salary;
    while (cin.fail()) {
        cin.ignore();
        cin.clear();
        cout << "Invalid input." << endl
            << "Enter salary: ";
        cin >> salary;
    }

    switch (choice) {
    case 1: {
        int meetingPerWeek, vacationPerWeek;
        cout << "Enter number of meetings per week: ";
        cin >> meetingPerWeek;
        cout << "Enter number of vacation days per year: ";
        cin >> vacationPerWeek;
        database.push_back(make_unique<Manager>(firstName, lastName, salary, meetingPerWeek, vacationPerWeek));
        break;
    }
    case 2: {
        bool knowCpp;
        int yearsOfExperience;
        string engineerType;
        cout << "Knows C++ (1 for yes, 0 for no): ";
        cin >> knowCpp;
        cout << "Enter years of experience: ";
        cin >> yearsOfExperience;
        cin.ignore();
        cout << "Enter engineer type: ";
        getline(cin, engineerType);
        database.push_back(make_unique<Engineer>(firstName, lastName, salary, knowCpp, yearsOfExperience, engineerType));
        break;
    }
    case 3: {
        string phdSchool, phdTopic;
        cin.ignore();
        cout << "Enter PhD school: ";
        getline(cin, phdSchool);
        cout << "Enter PhD topic: ";
        getline(cin, phdTopic);
        database.push_back(make_unique<Researcher>(firstName, lastName, salary, phdSchool, phdTopic));
        break;
    }
    default:
        cout << "Invalid choice." << endl;
        break;
    }
}


void RemoveEmployee(vector<unique_ptr<Employee>>& database) {
    int id;
    cout << "Enter ID of employee to delete: ";
    cin >> id;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Invalid ID." << endl;
        cout << "Enter ID of employee to delete: ";
        cin >> id;
    }
    auto data = remove_if(database.begin(), database.end(),
        [id](const unique_ptr<Employee>& e) { return e->getId() == id; });

    if (data != database.end()) {
        database.erase(data, database.end());
        cout << "Employee deleted." << endl;
    }
    else {
        cout << "Employee with ID " << id << " not found." << endl;
    }
}

void SaveEmployee(const vector<unique_ptr<Employee>>& database, const string& filename) {
    ofstream fout(filename);
    if (!fout) {
        cerr << "File could not open." << endl;
        return;
    }
    for (const auto& e : database) {
        fout << "\t";
        e->save(fout);
    }
    cout << "Database saved to " << filename << endl;
}

void DisplayEmployee(const vector<unique_ptr<Employee>>& database) {

    for (auto& e : database) {
        cout << "{" << endl;
        e->display();
        cout << "}";
        cout << endl;
    }
}

bool isAlphabetic(const string& str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}