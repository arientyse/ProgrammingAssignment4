// Name: Ariana Tyson
// Course: CIS-165 Introduction to Programming
// Date Started: May 2, 2018
// Professor Luy

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <cmath>
#include <stdlib.h>

int const STRINGSIZE = 30;
int const LISTSIZE = 10;
int const HEADSIZE = 4;

typedef char STRING30[STRINGSIZE];
typedef STRING30 LISTNAMES[LISTSIZE];
typedef STRING30 HEADINGS[HEADSIZE];

using namespace std;

int main()
{

	int choice;

	char drive[2], disk_file[15], file[9];
	ofstream outfile;

	ifstream infile;

	int minidx;

	LISTNAMES firstname;
	LISTNAMES lastname;
	int daysofrental[LISTSIZE];
	double balancedue[LISTSIZE];

	int highestrental;
	double highbalance;

	double tempnum;
	STRING30 minname;
	STRING30 tempname;

	double total;

	int rentalcount = 0;
	int rentalcountcout = 0;

	HEADINGS heading;


	//Input from File
	system("cls");

	infile.open("invoice2_test2.txt");
	if (infile.is_open())
	{
		infile >> heading[0] >> heading[1] >> heading[2] >> heading[3];
		int i = 0;

		while (!infile.eof())
		{
			infile >> lastname[i];
			infile >> firstname[i];
			infile >> daysofrental[i];
			infile >> balancedue[i];
			i++;
		}
		infile.close();
	}
	else
		cout << "File failed to open." << endl;

	//Process
	//Sorting of Information
	for (int idx = 0; idx < LISTSIZE; idx++)
	{
		minidx = idx;
		strcpy(minname, lastname[idx]);

		for (int j = idx; j < LISTSIZE; j++)
		{
			if (strcmp(lastname[j], minname) == -1)
			{
				minidx = j;
				strcpy(minname, lastname[j]);
			}
		}

		//Last Name
		strcpy(tempname, lastname[idx]);
		strcpy(lastname[idx], minname);
		strcpy(lastname[minidx], tempname);

		//First Name
		strcpy(tempname, firstname[idx]);
		strcpy(firstname[idx], firstname[minidx]);
		strcpy(firstname[minidx], tempname);

		//Days of Rental
		tempnum = daysofrental[idx];
		daysofrental[idx] = daysofrental[minidx];
		daysofrental[minidx] = tempnum;

		//Balance Due
		tempnum = balancedue[idx];
		balancedue[idx] = balancedue[minidx];
		balancedue[minidx] = tempnum;
	}

	for (int idx = 0; idx < LISTSIZE; idx++)
	{
		total += balancedue[idx];
	}

	//Output
	system("cls");

	cout << "Output to Console (1) or Disk File (2)?:   ";
	cin >> choice;
	if (choice == 1)
	{
		system("cls");
		outfile.open("con");
	}
	else
	{
		cout << "which drive: A, B, C, D, E, or F?    ";
		cin >> drive;
		strcpy(disk_file, drive);
		strcat(disk_file, ":");

		cout << "Enter a Results File Name:   ";
		cin >> file;
		strcat(disk_file, file);
		strcat(disk_file, ".txt");
		outfile.open(disk_file);
	}
	outfile << setiosflags(ios::showpoint | ios::fixed) << setprecision(2);

	outfile << left << setw(25) << heading[0] << left << setw(25) << heading[1] << left << setw(25) << heading[2] << left << setw(25) << heading[3] << endl;

	for (int a = 0; a < LISTSIZE; a++)
	{
		outfile << left << setw(25) << lastname[a] << left << setw(25) << firstname[a] << left << setw(25) << daysofrental[a] << left << setw(25) << balancedue[a] << endl;
	}

	outfile << endl << endl;
	outfile << setw(15) << setprecision(2) << showpoint << fixed << "Total Balance Due: $ " << total << endl;
	outfile << endl;

	outfile << "Customer(s) with the Highest Number of Rental Days: ";

	highestrental = daysofrental[0];

	for (int idx = 0; idx < LISTSIZE; idx++)
	{
		if (daysofrental[idx] > highestrental)
			highestrental = daysofrental[idx];
	}


	for (int idx = 0; idx < LISTSIZE; idx++)
	{
		if (daysofrental[idx] == highestrental)
			rentalcount++;
	}

	for (int idx = 0; idx < LISTSIZE; idx++)
	{
		if (daysofrental[idx] == highestrental)
		{
			if (rentalcountcout < rentalcount)
			{
				outfile << firstname[idx] << " " << lastname[idx] << ", " << endl;
			}
			else
				outfile << firstname[idx] << " " << lastname[idx] << endl;
			rentalcountcout++;
		}
	}

	outfile << endl;

	outfile << "Customer(s) with the Highest Balance Due: ";
	highbalance = balancedue[0];

	for (int idx = 0; idx < LISTSIZE; idx++)
	{
		if (balancedue[idx] > highbalance)
			highbalance = balancedue[idx];
	}

	for (int idx = 0; idx < LISTSIZE; idx++)
	{
		if (balancedue[idx] == highbalance)
			outfile << firstname[idx] << " " << lastname[idx] << ", " << endl;
	}
	outfile << endl;


	outfile.close();
	cout << endl << endl;

	system("PAUSE");
	return 0;
}

