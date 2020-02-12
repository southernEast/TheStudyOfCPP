#ifndef __BASEPLUSCOMISSIONEMPLOYEE_H__
#define __BASEPLUSCOMISSIONEMPLOYEE_H__

#include <string>
#include "ComissionEmployee.h"

class BasePlusComissionEmployee : public ComissionEmployee {
public:
	BasePlusComissionEmployee(
		const std::string& first, const std::string& last,
		const std::string& ssn, double sales = 0.0,
		double rate = 0.0, double salary = 0.0);
	virtual ~BasePlusComissionEmployee() {}

	void setBaseSalary(double salary);
	double getBaseSalary() const;

	virtual double earnings() const override;
	virtual void print() const override;
private:
	double baseSalary;
};

#endif // !__BASEPLUSCOMISSIONEMPLOYEE_H__

