#ifndef __SALARIEDEMPLOYEE_H__
#define __SALARIEDEMPLOYEE_H__

#include <string>
#include "Employee.h"

class SalariedEmployee : public Employee {
public:
	SalariedEmployee(const std::string& first, const std::string& last,
		const std::string& ssn, double salary = 0.0);
	virtual ~SalariedEmployee() {}

	void setWeeklySalary(double salary);
	double getWeeklySalary() const;

	virtual double earnings() const override;
	virtual void print() const override;
private:
	double weeklySalary;
};

#endif // !__SALARIEDEMPLOYEE_H__

