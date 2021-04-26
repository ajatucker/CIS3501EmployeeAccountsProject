#pragma once
#ifndef EMPLOYEE
#define EMPLOYEE
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class employee
{
protected:
	string firstName;
	string lastName;
	string ssn;
	string hideSsn;
	string id;
public:
	employee();
	void printEmployee(ofstream& ofs);
	string getFirstName();
	string getLastName();
	string getSsn();
	string getId();
	void setFirstName(string s);
	void setLastName(string s);
	void setSsn(string s, bool& methodStatus);
	void setId(string input, bool& methodStatus);
};

#endif // !EMPLOYEE

//Description: default constructor, initializes everything to null
//Pre-condition:  none
//Post-condition: none
employee::employee()
{
	firstName = " ";
	lastName = " ";
	ssn = " ";
	hideSsn = " ";
	id = " ";
}

//Description: prints employee info to screen and output file
//Pre-condition: ofstream object 
//Post-condition: none
void employee::printEmployee(ofstream& ofs)
{
	cout << "------------------------------------" << endl;
	ofs << "------------------------------------" << endl;
	cout << "Data for Employee" << endl;
	ofs << "Data for Employee" << endl;
	cout << "First Name:" << firstName << endl;
	ofs << "First Name:" << firstName << endl;
	cout << "Last Name:" << lastName << endl;
	ofs << "Last Name:" << lastName << endl;
	cout << "SSN: " << hideSsn << endl;
	ofs << "SSN: " << hideSsn << endl;
	cout << "ID:" << id << endl;
	ofs << "ID:" << id << endl;
	cout << "------------------------------------" << endl;
	ofs << "------------------------------------" << endl;
}

//Description: accessor for first name
//Pre-condition:  none
//Post-condition: string
string employee::getFirstName()
{
	return firstName;
}

//Description: accessor for last name
//Pre-condition:  none
//Post-condition: string
string employee::getLastName()
{
	return lastName;
}

//Description: accessor for ssn/hideSsn
//Pre-condition:  none
//Post-condition: string
string employee::getSsn()
{
	return hideSsn;
}

//Description: accessor for id
//Pre-condition:  none
//Post-condition: string
string employee::getId()
{
	return id;
}

//Description: mutator for first name
//Pre-condition:  string
//Post-condition: none
void employee::setFirstName(string s)
{
	firstName = s;
}

//Description: mutator for last name
//Pre-condition:  string
//Post-condition: none
void employee::setLastName(string s)
{
	lastName = s;
}

//Description: mutator for ssn
//Pre-condition:  string, boolean
//Post-condition: none
void employee::setSsn(string s, bool& methodStatus)
{
	methodStatus = false;
	if (s.size() == 11)
	{
		for (int i = 0; i < 11; i++)
		{
			if (s[3] != '-' || s[6] != '-')
			{
				return;
			}
			if (isalpha(s[i]))
			{
				return;
			}
		}

		methodStatus = true;
		ssn = s;
		hideSsn = s;

		for (int i = 0; i < 6; i++)
		{
			if (i != 3)
			{
				hideSsn[i] = 'x';
			}
		}
	}
}
//Description: mutator for id
//Pre-condition: string, boolean
//Post-condition: none
void employee::setId(string input, bool& methodStatus)
{
	methodStatus = false;
	if (input.size() == 5)
	{
		if (isalpha(input[0]) || isalpha(input[1]) || isalpha(input[2]))
		{
			cout << "Error, letter(s) found!" << endl;
			return;
		}
		if (input[3] != '-')
		{
			cout << "Error, incorrect format!" << endl;
			return;
		}
		if (toupper(input[4]) < 'A' || toupper(input[4]) > 'M')
		{
			cout << "Error, the final letter must be A-M!" << endl;
			return;
		}
		input[4] = toupper(input[4]);

		methodStatus = true;
		id = input;
	}

}