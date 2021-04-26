#pragma once
#ifndef HOURLYEMPLOYEE
#define HOURLYEMPLOYEE
#include "employee.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class hourlyEmployee : public employee
{
private:
	float hourlyPay;
	int numberOfHours;
	float weeklyPay;
public:
	hourlyEmployee();
	void printHourlyEmployee(ofstream& ofs);
	float getHourlyPay();
	float getWeeklyPay();
	int getNumberOfHours();
	void setWeeklyPay(float h, bool& methodStatus);
	void setNumberOfHours(int h, bool& methodStatus);
};

#endif

//Description: default constructor, initializes everything to null
//Pre-condition:  none
//Post-condition: none
hourlyEmployee::hourlyEmployee()
{
	hourlyPay = 0.0;
	numberOfHours = 0;
	weeklyPay = 0.0;
}

//Description: prints hourly employee info to screen and output file
//Pre-condition: ofstream object 
//Post-condition: none
void hourlyEmployee::printHourlyEmployee(ofstream& ofs)
{
	cout << "------------------------------------" << endl;
	ofs << "------------------------------------" << endl;
	cout << "Data for Hourly Employee" << endl;
	ofs << "Data for Hourly Employee" << endl;
	cout << "First Name:" << getFirstName() << endl;
	ofs << "First Name:" << getFirstName() << endl;
	cout << "Last Name:" << getLastName() << endl;
	ofs << "Last Name:" << getLastName() << endl;
	cout << "Social Security Number: " << getSsn() << endl;
	ofs << "Social Security Number: " << getSsn() << endl;
	cout << "Employee Number:        " << getId() << endl;
	ofs << "Employee Number:        " << getId() << endl;
	cout << "Weekly Pay:             " << fixed << setprecision(2) <<weeklyPay << endl;
	ofs << "Weekly Pay:             " << fixed << setprecision(2) << weeklyPay << endl;
	cout << "Hourly Pay:             " << fixed << setprecision(2) << hourlyPay << endl;
	ofs << "Hourly Pay:             " << fixed << setprecision(2) << hourlyPay << endl;
	cout << "Hours Worked:           " << numberOfHours << endl;
	ofs << "Hours Worked:           " << numberOfHours << endl;
	cout << "------------------------------------" << endl;
	ofs << "------------------------------------" << endl;
}

//Description: accessor for hourly pay
//Pre-condition:  none
//Post-condition: float
float hourlyEmployee::getHourlyPay()
{
	return hourlyPay;
}

//Description: accessor for weekly pay
//Pre-condition:  none
//Post-condition: float
float hourlyEmployee::getWeeklyPay()
{
	return weeklyPay;
}

//Description: accessor for hours worked
//Pre-condition:  none
//Post-condition: integer
int hourlyEmployee::getNumberOfHours()
{
	return numberOfHours;
}

//Description: mutator for hourly pay and weekly pay
//Pre-condition:  float, boolean
//Post-condition: none
void hourlyEmployee::setWeeklyPay(float h, bool& methodStatus)
{
	if (h < 400.00 || h > 3000.00)
	{
		methodStatus = false;
	}
	else
	{
		weeklyPay = h;
		hourlyPay = weeklyPay / 40;
		methodStatus = true;
	}
}

//Description: mutator for hours worked
//Pre-condition:  integer, boolean
//Post-condition: none
void hourlyEmployee::setNumberOfHours(int h, bool& methodStatus)
{
	if (h < 1 || h > 60)
	{
		methodStatus = false;
	}
	else
	{
		numberOfHours = h;
		methodStatus = true;
	}
}