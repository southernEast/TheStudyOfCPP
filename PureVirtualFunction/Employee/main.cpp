#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "ComissionEmployee.h"
#include "BasePlusComissionEmployee.h"
using namespace std;

void virtualViaPointer(const Employee* const baseClassPtr);
void virtualViaReference(const Employee& baseClassRef);

int main()
{
    cout << fixed << setprecision(2);

    SalariedEmployee salariedEmployee(
        "John", "Smith", "111-11-1111", 800
    );
    ComissionEmployee comissionEmployee(
        "Sue", "Jones", "333-33-3333", 10000, 0.06
    );
    BasePlusComissionEmployee basePlusComissionEmployee(
        "Bob", "Lewis", "444-44-4444", 5000, 0.04, 300
    );

    vector<Employee*> employees(3);

    employees[0] = &salariedEmployee;
    employees[1] = &comissionEmployee;
    employees[2] = &basePlusComissionEmployee;

    for (const Employee* employeePtr : employees)
        virtualViaPointer(employeePtr);

   
}

void virtualViaPointer(const Employee* const baseClassPtr) {
    baseClassPtr->print();
    cout << "\nearned $" << baseClassPtr->earnings() << "\n";
    cout << typeid(baseClassPtr).name() << endl;
}
void virtualViaReference(const Employee& baseClassRef) {
    baseClassRef.print();
    cout << "\nearned $" << baseClassRef.earnings() << "\n\n";
}