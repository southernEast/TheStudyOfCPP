#ifndef __CLIENTDATA_H__
#define __CLIENTDATA_H__

#include <string>

class ClientData {
public:
	ClientData(int accountNumberVal = 0, const std::string& lastName = "",
		const std::string& firstName = "", double balanceVal = 0);

	void setAccountNumber(int accountNumberVal);
	int getAccountNumber() const;

	void setLastName(const std::string& lastNameStr);
	std::string getLastName() const;

	void setFirstName(const std::string& firstNameStr);
	std::string getFirstName() const;

	void setBalance(double balanceVal);
	double getBalance() const;
private:
	int accountNumber;
	char lastName[15];
	char firstName[10];
	double balance;
};

#endif // !__CLIENTDATA_H__
