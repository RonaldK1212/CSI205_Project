#pragma once
#include<iostream>
#include<string>
using namespace std;
void fillEmployees(string names[50], int salaries[50][4], int N);
void printAllEmployees(string names[50], int salaries[50][4], int N);
int maxSalary(int salaries[50][4], int N);
int minSalary(int salaries[50][4], int N);
float averageSalary(int salaries[50][4], int N);
float stdDeviation(int salaries[50][4], int N);
void raiseSalaries(int salaries[50][4], int N, int raiseAmount);
void printSpecificEmployee(string names[50], int salaries[50][4], int N, string employee);
string nameOfLowest(string names[50], int salaries[50][4], int N);