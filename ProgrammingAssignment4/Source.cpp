//Name: Ariana Tyson
//Class: CIS-165 Introduction to Programming
//Professor Luy
//Date: 5/2/2018

#include<fstream>
#include<iostream>
#include<string.h>
#include<iomanip>
#include<cmath>
#include<stdlib.h>

const int LISTSIZE = 10;
const int STRINGSIZE = 30;
const int HEADSIZE = 4;

typedef char STRING30[STRINGSIZE];
typedef STRING30 LISTNAMES[LISTSIZE];
typedef STRING30 HEADINGS[HEADSIZE];

using namespace std;



int main()
{

	int choice;

	char drive[2], disk_file[15], file[9];

	
	ofstream outfile;

	system("cls");

	HEADINGS heading;

	LISTNAMES firstname;
	LISTNAMES lastname;
	int daysofrental[LISTSIZE];
	double balancedue[LISTSIZE];

	int i = 0;
	int minidx;
	
	double tempnum;
	double highestbalance;
	int highestrental;

	STRING30 minnames;
	STRING30 tempnames;

	int rentalcount;
	int rentalcountcout;

	double total;



	//Input from File
	ifstream infile;

	infile.open("C:\\users\\aripi\\Documents\\invoice1_test1.txt");

	if (infile.is_open())
	{
		infile >> heading[0] >> heading[1] >> heading[2] >> heading[3];
		while (!infile.eof())
		{
			infile >> lastname[i] >> firstname[i] >> daysofrental[i] >> balancedue[i];
			i++;
		}
		infile.close();
	}
	else
		cout << "File failed to open" << endl;


	//Processing
	//Sorting the Information

	for (int idx = 0; idx < LISTSIZE; idx++)
	{
		minidx = idx;
		strcpy(minnames, lastname[idx]);
		
		for (int j = idx; j < LISTSIZE; j++)
		{
			if (strcmp(lastname[j], minnames) == -1)
			{
				minidx = j;
				strcpy(minnames, lastname[j]);
			}
		}

		//Last Names
		strcpy(tempnames, lastname[idx]);
		strcpy(lastname[idx], minnames);
		strcpy(lastname[minidx], tempnames);

		//First Names
		strcpy(tempnames, firstname[idx]);
		strcpy(firstname[idx], firstname[minidx]);
		strcpy(firstname[minidx], tempnames);

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
		total+= balancedue[idx];
	}

	rentalcount = 0;
	rentalcountcout = 0;

	//Output
	//Sorted

	system ("cls");
	cout << "Output to Console (1) or Disk File (2)? :      ";
	cin >> choice;

	if (choice == 1)
	{
		system("cls");
		outfile.open("con");
	}
	else
	{
		cout << "Which Drive: A, B, C, D, E, or F?       ";
		cin >> drive;
		
		strcpy(disk_file, drive);
		strcat(disk_file, ":");

		cout << "Enter a results file name:     ";
		cin >> file;

		strcat(disk_file, file);
		strcat(disk_file, ".txt");

		outfile.open(disk_file);
	}
	outfile << setiosflags(ios::showpoint | ios::fixed) << setprecision(2);

	
	outfile << heading[0] << " " << heading[1] << " " << heading[2] << " " << heading[3] << endl;

	for (int idx = 0; idx = LISTSIZE; idx++)
	{
		outfile << lastname[idx] << " " << firstname[idx] << " " << daysofrental[idx] << " " << balancedue[idx] << endl;
	}

	outfile << endl << endl;
	outfile << "Total Balance Due: " << total << endl;

	outfile << "Customer(s) with the Highest Number of Rental Days: ";
	
	highestrental = daysofrental[0];

	for (int idx = 0; idx = LISTSIZE; idx++)
	{
		if (daysofrental[idx] > highestrental)
		{
			highestrental = daysofrental[idx];
		}
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
				outfile << lastname[idx] << " " << firstname[idx] << ", ";
			}
			else
			{
				outfile << lastname[idx] << " " << firstname[idx];
			}
			rentalcountcout++;
		}
	}

	outfile << endl;

	outfile << "Customer(s) with the Highest Balance Due: ";

	highestbalance = balancedue[0];

	for (int idx = 0; idx < LISTSIZE; idx++)
	{
		if (balancedue[idx] > highestbalance)
		{
			highestbalance = balancedue[idx];
		}
	}

	for (int idx = 0; idx < LISTSIZE; idx++)
	{
		if (balancedue[idx] == highestbalance)
		{
			outfile << lastname[idx] << " " << firstname[idx] << ", ";
		}
	}
	outfile << endl;

	outfile.close();
	cout << endl << endl;
	
	system("PAUSE");
	return 0;
}
