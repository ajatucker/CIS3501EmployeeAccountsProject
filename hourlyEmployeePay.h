#pragma once
#ifndef HOURLYEMPLOYEEPAY
#define HOURLYEMPLOYEEPAY
#include "employee.h"
#include "hourlyEmployee.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

class hourlyEmployeePay : public hourlyEmployee
{
private:
	float overtimePayRate;
	int taxRateCode;
	float taxRate;
	char workStatus;
	float paymentDue;
public:
	hourlyEmployeePay();
	void printHourlyEmployeePay(ofstream& ofs);
	float getOvertimePay();
	float getTaxRate();
	int getTaxRateCode();
	char getWorkStatus();
	float getPaymentDue();
	void setOvertimePay(float p);
	void setTaxRateCode(int t, bool& methodStatus);
	void setWorkStatus(char c, bool& methodStatus);
};


#endif

//Description: default constructor, initializes everything to null
//Pre-condition:  none
//Post-condition: none
hourlyEmployeePay::hourlyEmployeePay()
{
	overtimePayRate = 0.0;
	taxRate = 0.0;
	paymentDue = 0.0;
	taxRateCode = 1;
	workStatus = 'p';
}

//Description: prints hourly employee info to screen and output file
//Pre-condition: ofstream object 
//Post-condition: none
void hourlyEmployeePay::printHourlyEmployeePay(ofstream& ofs)
{
	cout << "------------------------------------" << endl;
	ofs << "------------------------------------" << endl;
	cout << "Data for Hourly Employee Pay" << endl;
	ofs << "Data for Hourly Employee Pay" << endl;
	cout << "First Name:" << getFirstName() << endl;
	ofs << "First Name:" << getFirstName() << endl;
	cout << "Last Name:" << getLastName() << endl;
	ofs << "Last Name:" << getLastName() << endl;
	cout << "Social Security Number: " << getSsn() << endl;
	ofs << "Social Security Number: " << getSsn() << endl;
	cout << "Employee Number:        " << getId() << endl;
	ofs << "Employee Number:        " << getId() << endl;
	cout << "Weekly Pay:             " << fixed << setprecision(2) << getWeeklyPay() << endl;
	ofs << "Weekly Pay:             " << fixed << setprecision(2) << getWeeklyPay() << endl;
	cout << "Hourly Pay:             " << fixed << setprecision(2) << getHourlyPay() << endl;
	ofs << "Hourly Pay:             " << fixed << setprecision(2) << getHourlyPay() << endl;
	cout << "Hours Worked:           " << getNumberOfHours() << endl;
	ofs << "Hours Worked:           " << getNumberOfHours() << endl;
	cout << "Overtime Pay Rate:      " << fixed << setprecision(2) << overtimePayRate << endl;
	ofs << "Overtime Pay Rate:      " << fixed << setprecision(2) << overtimePayRate << endl;
	cout << "Tax Rate:               " << taxRate << endl;
	ofs << "Tax Rate:               " << taxRate << endl;
	cout << "Tax Rate Code:          " <<  taxRateCode << endl;
	ofs << "Tax Rate Code:          " <<  taxRateCode << endl;
	cout << "Work Status:            " << workStatus << endl;
	ofs << "Work Status:            " << workStatus << endl;
	cout << "Payment Due: " << paymentDue << endl;
	ofs << "Payment Due: " << paymentDue << endl;
	cout << "------------------------------------" << endl;
	ofs << "------------------------------------" << endl;
}

//Description: accessor for overtime pay rate
//Pre-condition:  none
//Post-condition: float
float hourlyEmployeePay::getOvertimePay()
{
	return overtimePayRate;
}

float hourlyEmployeePay::getPaymentDue()
{
	return paymentDue;
}

//Description: accessor for tax rate
//Pre-condition:  none
//Post-condition: float
float hourlyEmployeePay::getTaxRate()
{
	return taxRate;
}

int hourlyEmployeePay::getTaxRateCode()
{
	return taxRateCode;
}

//Description: accessor for work status
//Pre-condition:  none
//Post-condition: character
char hourlyEmployeePay::getWorkStatus()
{
	return workStatus;
}

//Description: mutator for the overtime pay rate, alsoo calculates paymentDue
//Pre-condition:  float
//Post-condition: none
void hourlyEmployeePay::setOvertimePay(float p)
{
	overtimePayRate = p * 1.5;

	if (getNumberOfHours() > 40)
	{
		paymentDue = getWeeklyPay() + (overtimePayRate * (getNumberOfHours() % 40)) - (taxRate * (getWeeklyPay() + (overtimePayRate * (getNumberOfHours() % 40))));
	}
	else
	{
		paymentDue = (getNumberOfHours() * getHourlyPay()) - (getNumberOfHours() * getHourlyPay() * taxRate);
	}
}

//Description: mutator for tax code
//Pre-condition:  integer, boolean
//Post-condition: none
void hourlyEmployeePay::setTaxRateCode(int i, bool& methodStatus)
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

//Description: mutator for work status
//Pre-condition:  character, boolean
//Post-condition: none
void hourlyEmployeePay::setWorkStatus(char c, bool& methodStatus)
{
	if (toupper(c) == 'P' || toupper(c) == 'F')
	{
		workStatus = toupper(c);
		methodStatus = true;
	}
	else
	{
		methodStatus = false;
	}
}