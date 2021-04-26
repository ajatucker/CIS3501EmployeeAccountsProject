#pragma once
#ifndef SALARYEMPLOYEEPAY
#define SALARYEMPLOYEEPAY
#include <string>
#include "employee.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class salaryEmployeePay : public employee
{
protected:
	float annualPay;
	float weeklyPay;
	int taxRateCode;
	float taxRate;
	float paymentDue;
public:
	salaryEmployeePay();
	void printSalaryEmployeePay(ofstream& of);
	float getAnnualPay();
	float getWeeklyPay();
	int getTaxRateCode();
	float getTaxRate();
	void calcPaymentDue();
	void setAnnualPay(float a, bool& methodStatus);
	void setTaxRateCode(int i, bool& methodStatus);
};

#endif

//Description: default constructor, initializes everything to null
//Pre-condition:  none
//Post-condition: none
salaryEmployeePay::salaryEmployeePay()
{
	annualPay = 0.0;
	weeklyPay = 0.0;
	taxRate = 0.0;
	paymentDue = 0.0;
	taxRateCode = 1;
}

//Description: prints hourly employee info to screen and output file
//Pre-condition: ofstream object 
//Post-condition: none
void salaryEmployeePay::printSalaryEmployeePay(ofstream& ofs)
{
	calcPaymentDue();

	cout << "------------------------------------" << endl;
	ofs << "------------------------------------" << endl;
	cout << "Data for Salary Employee" << endl;
	ofs << "Data for Salary Employee" << endl;
	cout << "First Name:" << getFirstName() << endl;
	ofs << "First Name:" << getFirstName() << endl;
	cout << "Last Name:" << getLastName() << endl;
	ofs << "Last Name:" << getLastName() << endl;
	cout << "Social Security Number: " << getSsn() << endl;
	ofs << "Social Security Number: " << getSsn() << endl;
	cout << "Employee Number:        " << getId() << endl;
	ofs << "Employee Number:        " << getId() << endl;
	cout << "Annual Pay:             " << fixed << setprecision(2) << annualPay << endl;
	ofs << "Annual Pay:             " << fixed << setprecision(2) << annualPay << endl;
	cout << "Weekly Pay:             " << fixed << setprecision(2) << weeklyPay << endl;
	ofs << "Weekly Pay:             " << fixed << setprecision(2) << weeklyPay << endl;
	cout << "Payment Due:             " << fixed << setprecision(2) << paymentDue << endl;
	ofs << "Payment Due:             " << fixed << setprecision(2) << paymentDue << endl;
	cout << "Tax Rate:               " << taxRate << endl;
	ofs << "Tax Rate:               " << taxRate << endl;
	cout << "Tax Rate Code:               " << taxRateCode << endl;
	ofs << "Tax Rate Code:               " << taxRateCode << endl;
	cout << "------------------------------------" << endl;
	ofs << "------------------------------------" << endl;
}

//Description: accessor for annual pay
//Pre-condition:  none
//Post-condition: float
float salaryEmployeePay::getAnnualPay()
{
	return annualPay;
}

//Description: accessor for weekly pay
//Pre-condition:  none
//Post-condition: float
float salaryEmployeePay::getWeeklyPay()
{
	return weeklyPay;
}

//Description: accessor for tax rate
//Pre-condition:  none
//Post-condition: float
float salaryEmployeePay::getTaxRate()
{
	return taxRate;
}

//Description: accessor for tax rate code
//Pre-condition:  none
//Post-condition: integer
int salaryEmployeePay::getTaxRateCode()
{
	return taxRateCode;
}

//Description: mutator for annual pay
//Pre-condition:  float, boolean
//Post-condition: none
void salaryEmployeePay::setAnnualPay(float a, bool& methodStatus)
{
	methodStatus = false;

	if (a > 0)
	{
		annualPay = a;

		weeklyPay = (annualPay / 52);

		methodStatus = true;
	}

}

//Description: mutator for taxRateCode/taxRate
//Pre-condition:  integer, boolean
//Post-condition: none
void salaryEmployeePay::setTaxRateCode(int i, bool& methodStatus)
{
	if (i < 1 || i > 3)
	{
		cout << "Error, tax code can only be 1, 2, 3!" << endl;
		methodStatus = false;
	}
	else
	{
		taxRateCode = i;
		if (i == 1)
		{
			taxRate = .25;
		}
		if (i == 2)
		{
			taxRate = .2;
		}
		if (i == 3)
		{
			taxRate = .15;
		}

		methodStatus = true;
	}
}

//Description: calculates payment due
//Pre-condition:  none
//Post-condition: none
void salaryEmployeePay::calcPaymentDue()
{
	paymentDue = weeklyPay - (weeklyPay * taxRate);
}