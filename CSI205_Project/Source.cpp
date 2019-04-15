#include<iostream>
#include<string>
#include "CSI205.h"
using namespace std;

int main() {
	int N, salaries[50][4];  //Declares 'N' as the number of employees and 'salaries' as a two dimensional array to store the salaries of each employee.
	char choice; //Declares 'choice' for the user to select a switch case.
	string companyName, names[50]; //Declares 'companyName' to store the name of the company and 'names' as a one dimensional array to store employee names.
	bool infoEntered = false; //Declares 'infoEntered' to verify that the user entered employee data.

	cout << "Enter the name of the company and its number of employees: ";
	cin >> companyName; //User inputs name of the company.
	if (companyName != "demo") { //Only for testing purposes.
		cin >> N; //User inputs amount of employees as an integer.
		while (N < 1 || N > 50 || cin.fail()) { //Checks if N is a valid integer between 1 and 50. If the conditions are false, continue with the program.
			system("CLS"); //Clears the console for better organization.
			cout << "Please enter the number of employees between 1 and 50" << endl;
			cin.clear(); //Clears cin error flag.
			cin.ignore(10000, '\n'); //Clears cin buffer for the current line.
			cin >> N; //User inputs amount of employees again.
		}
		cout << companyName << " has " << N << " employees." << endl;
	}

	else { //Only for testing purposes, to automatically input data.
		infoEntered = true;
		N = 5;
		//John
		names[0] = "John";
		salaries[0][0] = 1500;
		salaries[0][1] = 2000;
		salaries[0][2] = 1800;
		salaries[0][3] = 2400;
		//Fadi
		names[1] = "Fadi";
		salaries[1][0] = 1350;
		salaries[1][1] = 1100;
		salaries[1][2] = 1400;
		salaries[1][3] = 1000;
		//Mona
		names[2] = "Mona";
		salaries[2][0] = 3000;
		salaries[2][1] = 3500;
		salaries[2][2] = 4000;
		salaries[2][3] = 2900;
		//Paul
		names[3] = "Paul";
		salaries[3][0] = 1200;
		salaries[3][1] = 1050;
		salaries[3][2] = 1400;
		salaries[3][3] = 1150;
		//Sara
		names[4] = "Sara";
		salaries[4][0] = 2150;
		salaries[4][1] = 1400;
		salaries[4][2] = 1300;
		salaries[4][3] = 2000;

	}

	
	while (true) {
		//Prints the list of available options.
		if (infoEntered) { //Checks if employee data is entered.
			cout << "Enter a the corresponding letter for one of the choices: " << endl;
			cout << "A. Input the names and salaries of the employees." << endl
				<< "B. Displays the names and salaries of all employees." << endl
				<< "C. Displays the maximum salary in the company." << endl
				<< "D. Displays the minimum salary in the company." << endl
				<< "E. Displays the average salary of all employees." << endl
				<< "F. Displays the standard deviation of all salaries." << endl
				<< "G. Gives a raise to all employees." << endl
				<< "H. Displays the salary of an employee in ascending order." << endl
				<< "I. Displays the name of the employee with the lowest salary in the company." << endl
				<< "J. Exits the program" << endl;
		}
		else {
			system("CLS"); //Clears the console for better organization.
			cout << "Enter a the corresponding letter for one of the choices: " << endl;
			cout << "A. Input the names and salaries of the employees." << endl;

		}
		cout << endl << "Enter a choice: ";
		cin >> choice; //User inputs the choice
		system("CLS"); //Clears console
		if ((!infoEntered && (choice == 'a' || choice == 'A')) || (infoEntered)) { //Forces user to input data if no data is available.
			switch (choice) {
			case 'A':
			case 'a':
				fillEmployees(names, salaries, N); //Calls the fillEmployees function.
				infoEntered = true;
				break;

			case 'B':
			case 'b':
				printAllEmployees(names, salaries, N); //Calls the printAllEmployees function.
				break;

			case 'C':
			case 'c':
				cout << endl << "The maximum salary is $" << maxSalary(salaries, N) << endl; //Prints the maximum salary by passing the returned value from maxSalary.
				break;

			case 'D':
			case 'd':
				cout << endl << "The minimum salary is $" << minSalary(salaries, N) << endl; //Prints the minimum salary by passing the returned value from minSalary.
				break;

			case 'E':
			case 'e':
				cout << endl << "The average salary is $" << averageSalary(salaries, N) << endl; //Prints the average salary by passing the returned value from avgSalary.
				break;

			case 'F':
			case 'f':
				cout << endl << "The standard deviation is $" << stdDeviation(salaries, N) << endl; //Prints the standard deviation by passing the returned value from stdDeviation.
				break;

			case 'G':
			case 'g':
				int raiseAmount; //Declares the raise amount to be initialised by the user.
				cout << endl << "How much would you like to raise the salaries by?" << endl; 
				cin >> raiseAmount; //User inputs the raise amount.
				while (cin.fail()) { //Checks if 'raiseAmount' is a valid integer.
					system("CLS");
					cout << endl << "Please enter an integer." << endl;
					cin.clear(); //Clears cin error flag.
					cin.ignore(10000, '\n'); //Clears cin buffer for the current line.
					cin >> raiseAmount; //User inputs 'raiseAmount' again.
				}

				raiseSalaries(salaries, N, raiseAmount); //Calls the raiseSalaries function.
				break;

			case 'H':
			case 'h':
			{
				string employee; //Declares 'employee' as a string.
				cout << endl << "Enter the name of the employee: " << endl;
				cin >> employee; //User inputs the specified employee name.
				printSpecificEmployee(names, salaries, N, employee); //Calls the printSpecificEmployee function.
				break;
			}

			case 'I':
			case 'i':
				cout << endl << "The employee with the lowest salary is " << nameOfLowest(names, salaries, N) << " with a salary of " << minSalary(salaries, N) << endl;
				//Calls the nameOfLowest function to display the employee name, and calls the minSalary function to display their salary.
				break;

			case 'J':
			case 'j':
				cout << endl << "Thank you for using our program, good bye..." << endl;
				system("pause");
				return 0; //Displays a message and ends the program.

			default:
				//Warns the user in case 'choice' is invalid.
				cout << endl << "Invalid option." << endl;
				system("pause");
				break;
			}
			cout << "\n\n\n\n\n"; //Just to add some space between the functions and the choices list.
		}
	}
}
