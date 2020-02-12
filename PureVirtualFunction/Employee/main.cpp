#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "ComissionEmployee.h"
#include "BasePlusComissionEmployee.h"
using namespace std;

void virtualViaPoiner(const Employee* const baseClassPtr);
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

    salariedEmployee.print();
    cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
    comissionEmployee.print();
    cout << "\nearned $" << comissionEmployee.earnings() << "\n\n";
    basePlusComissionEmployee.print();
    cout << "\nearned $" << basePlusComissionEmployee.earnings() << "\n\n";
}

void virtualViaPointer(const Employee* const baseClassPtr) {
    baseClassPtr->print();
    cout << "\nearned $" << baseClassPtr->earnings() << "\n\n";
}
void virtualViaReference(const Employee& baseClassRef) {
    baseClassRef.print();
    cout << "\nearned $" << baseClassRef.earnings() << "\n\n";
}