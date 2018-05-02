#include<iostream>
#include<fstream>
#include<iomanip>

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

	int minidx;
	int i = 0;

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

	//Unsorted Names
	for (int idx = 0; idx < LISTSIZE; idx++)
	{
		cout << setw(10);
		cout << firstname[idx];

		cout << setw(10);
		cout << lastname[idx];

		cout << setw(10);
		cout << daysofrental[idx];

		cout << setw(10);
		cout << balancedue[idx];

		cout << endl;
	}

	//Sorted Names
	for (int idx = 0; idx < LISTSIZE; idx++)
	{
		minidx = i;
		strcpy(minimumperson[0], firstname[idx]);
		for (int j = i; j < 5; j++)
		{
			int match = strcmp(firstname[j], minimumperson[0]);
			if (match < 0)
			{
				minidx = j;
				strcpy(minimumperson[0], firstname[j]);
			}

		}

		strcpy(minimumperson[0], firstname[minidx]);
		strcpy(firstname[minidx], firstname[idx]);
		strcpy(firstname[idx], minimumperson[0]);

	}

	//Sorted
	for (int idx = 0; idx < LISTSIZE; idx++)
	{
		cout << setw(10) << firstname[idx];
		cout << setw(10) << lastname[idx];
		cout << setw(10) << daysofrental[idx];
		cout << setw(10) << balancedue[idx];
	}

	system("PAUSE");
	return 0;
}
