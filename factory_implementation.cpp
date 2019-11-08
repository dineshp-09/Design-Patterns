/*
A company, create classes for each type of employee and calculate working hours and wages/salaries that will be received.

Example General Manager, IT Manager, Accounting, Marketing, Finance, Operation Managers

Manager and Higher level employees won’t have overtime wage. Overtime wage is 1.5 times higher than the usual wage. 
Working hours are limited as 8 hours. More than this limit will be considered as overtime.

Inputs:
Employee Name, Surname
Title/Role
Salary
Daily Working hour

Outputs:
Date
Employee Name, Surname
Daily Wage.
*/

// Factory Design pattern
 
#include <iostream>
#include <string>

using namespace std;

class EmployeeType {
    protected:
        string fname;
        string lname;
        string role;
        double salary;
        double hours;
        double wage;
    public:
        EmployeeType(string fn, string ln, string rl, double sal, double hrs) {
            fname = fn;
            lname = ln;
            role = rl;
            salary = sal;
            hours = hrs;
            wage = 0.0;
        }
        virtual void calculateWage() = 0;
};

// Higher level employees - no overtime wage
class Officer : public EmployeeType {
    public:
        Officer(string fn, string ln, string rl, double sal, double hrs): EmployeeType(fn, ln, rl, sal, hrs)
        { }
        void calculateWage() {
            wage = salary / 30;
            cout << fname << ", " << lname << endl;
            cout << wage <<endl;
        }
};

// Managers - no overtime wage
class GeneralManager : public EmployeeType {
    public:
        GeneralManager(string fn, string ln, string rl, double sal, double hrs): EmployeeType(fn, ln, rl, sal, hrs)
        { }
        void calculateWage() {
            wage = salary / 30;
            cout << fname << ", " << lname << endl;
            cout << wage <<endl;
        }
};

// Managers - no overtime wage
class ITManager : public EmployeeType {
    public:
        ITManager(string fn, string ln, string rl, double sal, double hrs): EmployeeType(fn, ln, rl, sal, hrs)
        { }
        void calculateWage() {
            wage = salary / 30;
            cout << fname << ", " << lname << endl;
            cout << wage <<endl;
        }
};

// Managers - no overtime wage
class OperationManager : public EmployeeType {
    public:
        OperationManager(string fn, string ln, string rl, double sal, double hrs=0): EmployeeType(fn, ln, rl, sal, hrs)
        { }
        void calculateWage() {
            wage = salary / 30;
            cout << fname << ", " << lname << endl;
            cout << wage <<endl;
        }
};

// overtime wage applied
class Accounting : public EmployeeType {
    double hourly;
    public:
        Accounting(string fn, string ln, string rl, double sal, double hrs): EmployeeType(fn, ln, rl, sal, hrs)
        { }
        void calculateWage() {
            wage = salary / 30;
            hourly = wage / 8;
            if (hours > 8 ) {
                wage = wage + (1.5 * hourly * (hours-8));
            }
            cout << fname << ", " << lname << endl;
            cout << wage <<endl;
        }
};

// overtime wage applied
class Marketing : public EmployeeType {
    double hourly;
    public:
        Marketing(string fn, string ln, string rl, double sal, double hrs): EmployeeType(fn, ln, rl, sal, hrs)
        { }
        void calculateWage() {
            wage = salary / 30;
            hourly = wage / 8;
            if (hours > 8 ) {
                wage = wage + (1.5 * hourly * (hours-8));
            }
            cout << fname << ", " << lname << endl;
            cout << wage <<endl;
        }
};

// overtime wage applied
class Finance : public EmployeeType {
    double hourly;
    public:
        Finance(string fn, string ln, string rl, double sal, double hrs): EmployeeType(fn, ln, rl, sal, hrs)
        { }
        void calculateWage() {
            wage = salary / 30;
            hourly = wage / 8;
            if (hours > 8 ) {
                wage = wage + (1.5 * hourly * (hours-8));
            }
            cout << fname << ", " << lname << endl;
            cout << wage <<endl;
        }
};


class EmployeeTypeFactory {
    public:
        EmployeeType *getType(string fn, string ln, string rl, double sal, double hrs) {
            if (rl.compare("Officer") == 0) {
                return new Officer(fn, ln, rl, sal, hrs);
            } else if(rl.compare("GeneralManager") == 0) {
                return new GeneralManager(fn, ln, rl, sal, hrs);
             } else if(rl.compare("ITManager") == 0) {
                 return new ITManager(fn, ln, rl, sal, hrs);
             } else if(rl.compare("OperationManager") == 0) {
                 return new OperationManager(fn, ln, rl, sal, hrs);
             } else if(rl.compare("Accounting") == 0) {
                 return new Accounting(fn, ln, rl, sal, hrs);
             } else if(rl.compare("Marketing") == 0) {
                 return new Marketing(fn, ln, rl, sal, hrs);
             } else if(rl.compare("Finance") == 0) {
                 return new Finance(fn, ln, rl, sal, hrs);
             } else {
                 return NULL;
             }
        }
};


int main() {
    EmployeeType *emp;
    EmployeeTypeFactory *empFactory = new EmployeeTypeFactory();
    string fn, ln, rl;
    double sal, hrs;
    cout << "Enter First Name: ";
    cin >> fn;
    cout << "Enter Last Name: ";
    cin >> ln;
    cout << "Enter Title/Role\n" \
        "[Officer, GeneralManager, ITManager, OperationManager, Accounting, Marketing, Finance]:";
    cin >> rl;
    cout << "Enter Salary: ";
    cin >> sal;
    cout << "Enter Daily Working hour: ";
    cin >> hrs;
    cout << endl;

    // Functionality for date
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    cout << "Time: ";
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << endl;

    emp = empFactory->getType(fn, ln, rl, sal, hrs);
    if (emp != NULL)
        emp->calculateWage();
    else
        cout << "Title/Role not correct\n";
    return 0;
}

/* Output:
Enter First Name: Dinesh
Enter Last Name: P.
Enter Title/Role
[Officer, GeneralManager, ITManager, OperationManager, Accounting, Marketing, Finance]:ITManager
Enter Salary: 123456
Enter Daily Working hour: 8

Time: 2019-11-8
Dinesh, P.
4115.2
*/
