//Program Name: Program 0
//Programmer Name: Alexis Tucker
//Description: User will input data for various different types of employees, the program will
//demonstrate inheritance and do calculations based on the user input
//Date Created: 1/18/2021
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "employee.h"
#include "hourlyEmployee.h"
#include "hourlyEmployeePay.h"
#include "salaryEmployeePay.h"
#include "agencyCompanyPay.h"

using namespace std;

//Description: takes/checks user input
//Pre-condition: none
//Post-condition: none
int userInputCheck();

//Description: prints out menu items
//Pre-condition: none
//Post-condition: none, prints out menu
void menu();

/*
Desc: checks the validity of the user's input to loop through the program again
Pre-condition: none, will be checked automatically
Post-condition: returns a char value
*/
char sentinelCheck();

// Description: purpose is to make sure the printed output can be seen by user
//Pre-condition: none
//Post-condition: prints to output file
void wait();

int main()
{
	int intInput;
	float floatInput;
	string stringInput;
	char charInput;
	bool methodStatus = false;
	char sentinel = 'y';
	int userIn;

	employee emp;
	salaryEmployeePay salaryEmp;
	hourlyEmployee hourlyEmp;
	hourlyEmployeePay hourlyEmpPay;
	agencyEmployeePay agencyEmp;

	ofstream output("pay.dat", ios::out);

	while (sentinel == 'y' || sentinel == 'Y')
	{
		do
		{
			menu();
			userIn = userInputCheck();

			switch (userIn)
			{
			case 1: //employee
				cout << "\nEnter first name:";
				cin >> stringInput;
				emp.setFirstName(stringInput);

				cout << "\nEnter last name:";
				cin >> stringInput;
				emp.setLastName(stringInput);

				cout << "\nEnter SSN:";
				cin >> stringInput;
				emp.setSsn(stringInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\nError, please enter ssn in correct format: xxx-xx-xxxx";
					cout << "\nEnter SSN:";
					cin >> stringInput;
					emp.setSsn(stringInput, methodStatus);
				}
				cin.ignore();

				cout << "\nEnter ID:";
				cin >> stringInput;
				emp.setId(stringInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\n Error, please enter id in correct format: xxx-L";
					cout << "\nEnter ID:";
					cin >> stringInput;
					emp.setId(stringInput, methodStatus);
				}
				cin.ignore();

				emp.printEmployee(output);

				wait();
				break;
			case 2: //salary employee
				cout << "\nEnter first name:";
				cin >> stringInput;
				salaryEmp.setFirstName(stringInput);

				cout << "\nEnter last name:";
				cin >> stringInput;
				salaryEmp.setLastName(stringInput);

				cout << "\nEnter SSN:";
				cin >> stringInput;
				salaryEmp.setSsn(stringInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\nError, please enter ssn in correct format: xxx-xx-xxxx";
					cout << "\nEnter SSN:";
					cin >> stringInput;
					salaryEmp.setSsn(stringInput, methodStatus);
				}
				cin.ignore();

				cout << "\nEnter ID:";
				cin >> stringInput;
				salaryEmp.setId(stringInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\n Error, please enter id in correct format: xxx-L";
					cout << "\nEnter ID:";
					cin >> stringInput;
					salaryEmp.setId(stringInput, methodStatus);
				}
				cin.ignore();

				cout << "\nEnter Annual Pay:";
				cin >> floatInput;
				salaryEmp.setAnnualPay(floatInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\nError, please enter valid annual pay.";
					cout << "\nEnter Annual Pay:";
					cin >> floatInput;
					salaryEmp.setAnnualPay(floatInput, methodStatus);
				}

				cout << "\nEnter Tax Code:";
				cin >> intInput;
				salaryEmp.setTaxRateCode(intInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\nError, please enter a number 1-3.";
					cout << "\nEnter Tax Code:";
					cin >> intInput;
					salaryEmp.setTaxRateCode(intInput, methodStatus);
				}

				salaryEmp.printSalaryEmployeePay(output);

				wait();
				break;
			case 3://hourly employee
				cout << "\nEnter first name:";
				cin >> stringInput;
				hourlyEmp.setFirstName(stringInput);

				cout << "\nEnter last name:";
				cin >> stringInput;
				hourlyEmp.setLastName(stringInput);

				cout << "\nEnter SSN:";
				cin >> stringInput;
				hourlyEmp.setSsn(stringInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\nError, please enter ssn in correct format: xxx-xx-xxxx";
					cout << "\nEnter SSN:";
					cin >> stringInput;
					hourlyEmp.setSsn(stringInput, methodStatus);
				}
				cin.ignore();

				cout << "\nEnter ID:";
				cin >> stringInput;
				hourlyEmp.setId(stringInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\n Error, please enter id in correct format: xxx-L";
					cout << "\nEnter ID:";
					cin >> stringInput;
					hourlyEmp.setId(stringInput, methodStatus);
				}
				cin.ignore();

				cout << "\nEnter Weekly Pay: ";
				cin >> floatInput;
				hourlyEmp.setWeeklyPay(floatInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\nError, pay must be greater than 0.";
					cout << "\nEnter Weekly Pay: ";
					cin >> floatInput;
					hourlyEmp.setWeeklyPay(floatInput, methodStatus);
				}

				cout << "\nEnter Number of Hours Worked:";
				cin >> intInput;
				hourlyEmp.setNumberOfHours(intInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\nError, enter hours 1-60.";
					cout << "\nEnter Number of Hours Worked:";
					cin >> intInput;
					hourlyEmp.setNumberOfHours(intInput, methodStatus);
				}

				hourlyEmp.printHourlyEmployee(output);

				wait();
				break;
			case 4://hourly employee pay
				cout << "\nEnter first name:";
				cin >> stringInput;
				hourlyEmpPay.setFirstName(stringInput);

				cout << "\nEnter last name:";
				cin >> stringInput;
				hourlyEmpPay.setLastName(stringInput);

				cout << "\nEnter SSN:";
				cin >> stringInput;
				hourlyEmpPay.setSsn(stringInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\nError, please enter ssn in correct format: xxx-xx-xxxx";
					cout << "\nEnter SSN:";
					cin >> stringInput;
					hourlyEmpPay.setSsn(stringInput, methodStatus);
				}
				cin.ignore();

				cout << "\nEnter ID:";
				cin >> stringInput;
				hourlyEmpPay.setId(stringInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\n Error, please enter id in correct format: xxx-L";
					cout << "\nEnter ID:";
					cin >> stringInput;
					hourlyEmpPay.setId(stringInput, methodStatus);
				}
				cin.ignore();

				cout << "\nEnter Weekly Pay: ";
				cin >> floatInput;
				hourlyEmpPay.setWeeklyPay(floatInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\nError, pay must be greater than 0.";
					cout << "\nEnter Weekly Pay: ";
					cin >> floatInput;
					hourlyEmpPay.setWeeklyPay(floatInput, methodStatus);
				}

				cout << "\nEnter Number of Hours Worked:";
				cin >> intInput;
				hourlyEmpPay.setNumberOfHours(intInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\nError, enter hours 1-60.";
					cout << "\nEnter Number of Hours Worked:";
					cin >> intInput;
					hourlyEmpPay.setNumberOfHours(intInput, methodStatus);
				}

				cout << "\nEnter Tax Code:";
				cin >> intInput;
				hourlyEmpPay.setTaxRateCode(intInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\nError, please enter a number 1-3.";
					cout << "\nEnter Tax Code:";
					cin >> intInput;
					hourlyEmpPay.setTaxRateCode(intInput, methodStatus);
				}

				hourlyEmpPay.setOvertimePay(hourlyEmpPay.getHourlyPay());

				cout << "\nEnter Workstatus:";
				cin >> charInput;
				hourlyEmpPay.setWorkStatus(charInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\nError, workstatus can only be P or F.";
					cout << "\nEnter Workstatus:";
					cin >> charInput;
					hourlyEmpPay.setWorkStatus(charInput, methodStatus);
				}

				hourlyEmpPay.printHourlyEmployeePay(output);

				wait();
				break;
			case 5://agency employee
				cout << "\nEnter first name:";
				cin >> stringInput;
				agencyEmp.setFirstName(stringInput);

				cout << "\nEnter last name:";
				cin >> stringInput;
				agencyEmp.setLastName(stringInput);

				cout << "\nEnter SSN:";
				cin >> stringInput;
				agencyEmp.setSsn(stringInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\nError, please enter ssn in correct format: xxx-xx-xxxx";
					cout << "\nEnter SSN:";
					cin >> stringInput;
					agencyEmp.setSsn(stringInput, methodStatus);
				}
				cin.ignore();

				cout << "\nEnter ID:";
				cin >> stringInput;
				agencyEmp.setId(stringInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\n Error, please enter id in correct format: xxx-L";
					cout << "\nEnter ID:";
					cin >> stringInput;
					agencyEmp.setId(stringInput, methodStatus);
				}
				cin.ignore();

				cout << "\nEnter Weekly Pay: ";
				cin >> floatInput;
				agencyEmp.setWeeklyPay(floatInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\nError, pay must be greater than 0.";
					cout << "\nEnter Weekly Pay: ";
					cin >> floatInput;
					agencyEmp.setWeeklyPay(floatInput, methodStatus);
				}

				cout << "\nEnter Number of Hours Worked:";
				cin >> intInput;
				agencyEmp.setNumberOfHours(intInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\nError, enter hours 1-60.";
					cout << "\nEnter Number of Hours Worked:";
					cin >> intInput;
					agencyEmp.setNumberOfHours(intInput, methodStatus);
				}

				agencyEmp.setOvertimePay(hourlyEmpPay.getHourlyPay());

				cout << "\nEnter Tax Code:";
				cin >> intInput;
				agencyEmp.setTaxRateCode(intInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\nError, please enter a number 1-3.";
					cout << "\nEnter Tax Code:";
					cin >> intInput;
					agencyEmp.setTaxRateCode(intInput, methodStatus);
				}

				cout << "\nEnter Workstatus:";
				cin >> charInput;
				agencyEmp.setWorkStatus(charInput, methodStatus);
				while (methodStatus == false)
				{
					cout << "\nError, workstatus can only be P or F.";
					cout << "\nEnter Workstatus:";
					cin >> charInput;
					agencyEmp.setWorkStatus(charInput, methodStatus);
				}

				cout << "\nEnter Company to Pay:";
				cin >> stringInput;
				agencyEmp.setCompanyToPay(stringInput);

				agencyEmp.printAgencyEmpPayInfo(output);

				wait();
				break;
			}
		} while (userIn != 6);
		
		sentinel = sentinelCheck();
	}

	output.close();
}

void wait()
{
	int wait = 0;
	cout << "\n(Enter 0 to continue)" << endl;
	cin >> wait;
	while (wait != 0)
	{
		cout << "ERROR: enter 0" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> wait;
	}
}

char sentinelCheck()
{
	char userInput = ' ';//the user's input, which is checked, to decide whether to loop
	bool inputCheck = false; //used to loop through

	cout << "Enter y or n to continue or quit: ";
	cin >> userInput;
	do
	{
		if (userInput == 'y' || userInput == 'Y' || userInput == 'n' || userInput == 'N')
		{
			return userInput;
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Sorry, that wasn't a valid answer. Please enter y or n: ";
			cin >> userInput;
		}
	} while (inputCheck == false);
}

void menu()
{
	system("cls");
	cout << "Which type of employee would you like to create?" << endl;
	cout << "______________________________" << endl;
	cout << "1) Add Employee" << endl;
	cout << "2) Add Salary Employee" << endl;
	cout << "3) Add Hourly Employee" << endl;
	cout << "4) Add Hourly Employee Pay" << endl;
	cout << "5) Add Agency Employee" << endl;
	cout << "6) Exit" << endl;
	cout << "______________________________" << endl;
	cout << "Choose a number 1-6." << endl;
	cout << "______________________________" << endl;
}

int userInputCheck()
{
	int u = 0;

	cin >> u;

	while (u < 1 || u > 6)
	{
		cout << "ERROR: Please enter a number 1-6." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> u;
	}
	cin.ignore();

	return u;
}