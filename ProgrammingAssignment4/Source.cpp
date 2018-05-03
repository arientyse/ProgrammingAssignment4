//Name: Ariana Tyson
//Class: CIS-165 Introduction to Programming
//Professor Luy
//Date: 5/2/2018

#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<cmath>
#include<stdlib.h>

using namespace std;

const int LISTSIZE = 10;
const int STRINGSIZE = 30;

typedef char STRING30[STRINGSIZE];
typedef STRING30 LISTNAMES[LISTSIZE];
typedef STRING30 TEMPNAME[1];

int main()
{

	LISTNAMES firstname;
	LISTNAMES lastname;

	TEMPNAME minimumperson;

	int daysofrental[LISTSIZE];
	double balancedue[LISTSIZE];

	int i = 0;
	int minidx;

	ifstream in;
	in.open("C:\\users\\aripi\\Documents\\invoice1_test1.txt");

	if (in.is_open())
	{
		while (!in.eof())
		{
			in >> lastname[i] >> firstname[i] >> daysofrental[i] >> balancedue[i];
			i++;
		}
		in.close();
	}
	else
		cout << "File failed to open" << endl;

	//Sorting
	for (int idx = 0; idx < LISTSIZE; idx++)
	{
		minidx = idx;
		strcpy(minimumperson[0], lastname[idx]);
		for (int j = idx; j < LISTSIZE; j++)
		{
			int match = strcmp(lastname[j], minimumperson[0]);
			if (match < 0)
			{
				minidx = j;
				strcpy(minimumperson[0], lastname[j]);
			}
		}
		strcpy(minimumperson[0], lastname[minidx]);
		strcpy(lastname[minidx], lastname[idx]);
		strcpy(lastname[idx], minimumperson[0]);
	}

	//Sorted
	for (int idx = 0; idx < LISTSIZE; idx++)
	{
		cout << left << setw(10);
		cout << lastname[idx];

		cout << setw(10);
		cout << firstname[idx];

		cout << setw(10);
		cout << daysofrental[idx];

		cout << setw(10);
		cout << balancedue[idx];

		cout << endl;
	}
	
	system("PAUSE");
	return 0;
}
