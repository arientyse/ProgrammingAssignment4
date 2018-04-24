#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

const int LISTSIZE = 10;
const int STRINGSIZE = 30;

typedef char STRING30[STRINGSIZE];
typedef STRING30 LISTNAMES[LISTSIZE];

int main()
{
	LISTNAMES firstname;
	LISTNAMES lastname;
	int daysofrental[LISTSIZE];
	double balancedue[LISTSIZE];

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

	system("PAUSE");
	return 0;
}
