#pragma once
#ifndef AGENCYEMPLOYEEPAY
#define AGENCYEMPLOYEEPAY
#include <iostream>
#include <string>
#include "employee.h"
#include "hourlyEmployeePay.h"
#include <fstream>
#include <iomanip>

using namespace std;

class agencyEmployeePay : public hourlyEmployeePay
{
private:
	string companyToPay;
public:
	agencyEmployeePay();
	void printAgencyEmpPayInfo(ofstream& ofs);
	string getCompanyToPay();
	void setCompanyToPay(string a);
};

#endif

//Description: default constuctor
//Pre-condition: none
//Post-condition: none
agencyEmployeePay::agencyEmployeePay()
{
	companyToPay = " ";
}

//Description: prints agency employee info to file and screen
//Pre-condition: ofstream object
//Post-condition: none
void agencyEmployeePay::printAgencyEmpPayInfo(ofstream& ofs)
{
	cout << "------------------------------------" << endl;
	ofs << "------------------------------------" << endl;
	cout << "Data for Agency Employee" << endl;
	ofs << "Data for Agency Employee" << endl;
	cout << "First Name:" << getFirstName() << endl;
	ofs << "First Name:" << getFirstName() << endl;
	cout << "Last Name:" << getLastName() << endl;
	ofs << "Last Name:" << getLastName() << endl;
	cout << "Social Security Number: " << getSsn() << endl;
	ofs << "Social Security Number: " << getSsn() << endl;
	cout << "Employee Number:        " << getId() << endl;
	ofs << "Employee Number:        " << getId() << endl;
	cout << "Hourly Pay:             " << fixed << setprecision(2) << getHourlyPay() << endl;
	ofs << "Hourly Pay:             " << fixed << setprecision(2) << getHourlyPay() << endl;
	cout << "Hours Worked:           " << getNumberOfHours() << endl;
	ofs << "Hours Worked:           " << getNumberOfHours() << endl;
	cout << "Overtime Pay Rate:      " << fixed << setprecision(2) << getOvertimePay() << endl;
	ofs << "Overtime Pay Rate:      " << fixed << setprecision(2) << getOvertimePay() << endl;
	cout << "Tax Rate:               " << getTaxRate() << endl;
	ofs << "Tax Rate:               " << getTaxRate() << endl;
	cout << "Tax Rate Code:               " << getTaxRateCode() << endl;
	ofs << "Tax Rate Code:               " << getTaxRateCode() << endl;
	cout << "Work Status:            " << getWorkStatus() << endl;
	ofs << "Work Status:            " << getWorkStatus() << endl;
	cout << "Payment Due: " << getPaymentDue() << endl;
	ofs << "Payment Due: " << getPaymentDue() << endl;
	cout << "Company to Pay:         " << companyToPay << endl;
	ofs << "Company to Pay:         " << companyToPay << endl;
	cout << "------------------------------------" << endl;
	ofs << "------------------------------------" << endl;
}

//Description: accessor for agency variable
//Pre-condition:  none
//Post-condition: string
string agencyEmployeePay::getCompanyToPay()
{
	return companyToPay;
}

//Description: mutator for agency variable
//Pre-condition:  string
//Post-condition: none
void agencyEmployeePay::setCompanyToPay(string a)
{
	companyToPay = a;
}