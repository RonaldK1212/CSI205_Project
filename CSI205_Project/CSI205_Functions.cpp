#include<iostream>
#include<string>
using namespace std;
//A
void fillEmployees(string names[50], int salaries[50][4], int N) {
	for (int i = 0; i < N; i++) { //Loops through the first dimension of the arrays to fill 'names'.
		cout << "Enter name and salaries of employee "<< i+1 <<" in the four quarters: ";
		cin >> names[i]; //User inputs the employee names.
		for (int j = 0; j < 4; j++) { //Loops through the second dimension of the 'salaries' array to fill salary data.
			cin >> salaries[i][j]; //User inputs the employee salaries.
			while (cin.fail()) { //Checks if 'salaries' is a valid integer.
				system("CLS");
				cout << endl << "Please enter an integer." << endl;
				cin.clear(); //Clears cin error flag.
				cin.ignore(10000, '\n'); //Clears cin buffer for the current line.
				cin >> salaries[i][j]; //User inputs 'salaries' again.
			}
		}
	}
}

//B
void printAllEmployees(string names[50], int salaries[50][4], int N) {
	cout << endl <<"Name\t\tQuarter1\tQuarter2\tQuarter3\tQuarter4" << endl << "-------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++) { //Loops through the first dimension to print the employee names.
		cout << names[i] << "\t\t"; //Outputs the employee names.
		for (int j = 0; j < 4; j++) { //Loops through the second dimension to print the employee salaries.
			cout << "$" <<salaries[i][j] << "\t\t"; //Outputs the employee salaries.
		}
		cout << endl;
	}
}

//C
int maxSalary(int salaries[50][4], int N) {
	int maxSalaryVal = 0;
	for (int i = 0; i < N; i++) { //Loops through the first dimension to pass through all the employees.
		for (int j = 0; j < 4; j++) { //Loops through the second dimension to look for the maximum salary.
			if (salaries[i][j] > maxSalaryVal) maxSalaryVal = salaries[i][j];
		}
	}
	return maxSalaryVal; //Returns the maximum salary.
}


//D
int minSalary(int salaries[50][4], int N) {
	int minSalaryVal = salaries[0][0];
	for (int i = 0; i < N; i++) { //Loops through the first dimension to pass through all the employees.
		for (int j = 0; j < 4; j++) { //Loops through the second dimension to look for the minimum salary.
			if (salaries[i][j] < minSalaryVal) minSalaryVal = salaries[i][j];
		}
	}
	return minSalaryVal; //Returns the minimum salary.
}

//E
float averageSalary(int salaries[50][4], int N) {
	float averageSalaryVal = 0;
	for (int i = 0; i < N; i++) { //Loops through the first dimension to pass through all the employees.
		for (int j = 0; j < 4; j++) { //Loops through the second dimension to find the average of all salaries.
			averageSalaryVal += salaries[i][j] / (N * 4.0); //Calculates the average of the salaries.
		}
	}
	//cout << endl << "The average salary is $" << averageSalary << endl;
	return averageSalaryVal; //Returns the average salary.
}

//F
float stdDeviation(int salaries[50][4], int N) {

	float variance = 0, stdDeviationVal;
	float avgSalaryVal = averageSalary(salaries, N); //Calls the averageSalary function to declare and initialize the avgSalaryVal variable.

	for (int i = 0; i < N; i++) { //Loops through the first dimension to pass through all the employees.
		for (int j = 0; j < 4; j++) { //Loops through the second dimension to collect data for the variance.
			variance += pow(salaries[i][j] - avgSalaryVal, 2); //Calls the pow() function to square the difference between a salary and the average, then sums them up.
		}
	}
	variance = variance / (N * 4.0 - 1); //Does the final calculation for the variance to be valid.
	stdDeviationVal = sqrt(variance); //Calls the sqrt() function to find the standard population deviation.
	return stdDeviationVal; //Returns the standard deviation.
}


//G
void raiseSalaries(int salaries[50][4], int N, int raiseAmount) {
	for (int i = 0; i < N; i++) { //Loops through the first dimension of the array to pass through all of the employees.
		for (int j = 0; j < 4; j++) { //Loops through the second dimension of the array to pass through all of the salaries.
			salaries[i][j] += raiseAmount; //Adds 'raiseAmount' to all of the salaries.
		}
	}
	cout << "The raise of $" << raiseAmount << " is successfully added to all employees"; //Outputs a confirmation message.
}

//H
void printSpecificEmployee(string names[50], int salaries[50][4], int N, string employee) {
	int ascending[4], temp, ID = -1;
	//Creates the 'ascending' array to store a specified employee's salaries. 
	//Creates 'temp' to store temporary values to swap values while sorting.
	//Creates 'ID' to identify the employee using their index.
	while (ID == -1) {
		for (int i = 0; i < N; i++) { //Loops through the first dimension of the array to pass through all of the employees.
			if (employee.compare(names[i]) == 0) { //Compares the 'employee' string to all of the employees to find a match.
				ID = i; //Sets the 'ID' of the employee as their respective names index.
				break;
			}
		}

		if (ID == -1) {
			system("CLS");
			cout << endl << "Please enter an existing employee name." << endl;
			cin >> employee;
			continue;
		}
	}

	for (int i = 0; i < 4; i++) { //Loops through the second dimension of the salaries array to pass through the specified employee's salaries.
		ascending[i] = salaries[ID][i]; //Copies the values from 'salaries' to 'ascending', to avoid altering the 'salaries' array.
	}

	for (int i = 0; i < 3; i++) { //Loops through the second dimension of the salaries array to pass through all except the final index.
		for (int j = i + 1; j < 4; j++) { //Loops through the second dimension of the salaries array starting from 'i + 1' to the final index.
			if (ascending[i] > ascending[j]) { //Checks if the previous value is greater than the one after it.
				//Swaps the values if the previous one is greater than the next.
				temp = ascending[i]; 
				ascending[i] = ascending[j]; 
				ascending[j] = temp; 
			}
		}
	}

	system("CLS"); //Clears the console.
	cout <<endl<< "The salaries of "<< employee << " are:  ";
	for (int i = 0; i < 4; i++) { //Loops through the array to print the 'ascending' array.
		cout << "$"<<ascending[i] << "  "; //Outputs the sorted array.
	}
	cout << endl;
}

//I
string nameOfLowest(string names[50], int salaries[50][4], int N) {
	int minSalaryID, minSalary = salaries[0][0];
	for (int i = 0; i < N; i++) { //Loops through the first dimension of the 'salaries' array to pass through all of the employees.
		for (int j = 0; j < 4; j++) { //Loops through the second dimension of the 'salaries' array to find the lowest salary.
			if (minSalary >= salaries[i][j]) {
				minSalary = salaries[i][j];
				minSalaryID = i; //Sets the 'minSalaryID' as the index of the lowest employee.
			}
		}
	}

	return names[minSalaryID]; //Returns the name of the employee by passing their index into the 'names' array.
}

