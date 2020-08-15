//This program is your final exam.
//Please fill in the functions at the bottom of the file.  (oddCount and insertItem)
//DO NOT CHANGE ANYTHING ELSE.
//main has all the code needed to test your functions.  Once your functions are written, please build and make sure it works fine

#include <iostream>
#include <fstream>
using namespace std;

//constants
const int CAP = 100;

//function prototypes
bool openFile(ifstream&);
void readData(ifstream&, int[], int&);
void printData(const int[], int);
void oddCount(const int[], int);
void insertItem(int[], int&, int, int);


int main()
{
	ifstream inFile;
	int list[CAP], size = 0;

	if (!openFile(inFile))
	{
		cout << "Program terminating!! File not found!" << endl;
		return -1;
	}
	//read the data from the file
	readData(inFile, list, size);
	inFile.close();
	cout << "Data in file:" << endl;
	printData(list, size);
	//insert a few items
	insertItem(list, size, 15, 5);
	cout << "Inserted in position 5:" << endl;
	printData(list, size);
	insertItem(list, size, 101, 2);
	cout << "Inserted in position 5:" << endl;
	printData(list, size);
	insertItem(list, size, 215, 12);
	cout << "Inserted in position 5:" << endl;
	printData(list, size);
	//call the oddCount function
	oddCount(list, size);
	//end program
	cin.ignore(100, '\n');
	cout << "Press any key to continue...";
	getchar();

	return 0;
}

//function to open file
bool openFile(ifstream& inFile)
{
	inFile.open("numbers.txt");
	if (!inFile)
	{
		return false;
	}
	return true;
}

//reads the data from the file
void readData(ifstream& inFile, int list[], int& size)
{
	while (!inFile.eof())
	{
		inFile >> list[size++];
	}
}

//print the contents of the array
void printData(const int list[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i << ":" << list[i] << endl;
	}
	cout << endl;
}


//insert an item (newNum) in the given position (newPos)
void insertItem(int list[], int& size, int newNum, int newPos)
{
	

	if (newPos >= size)
	{
		list[size] = newNum;
		size++;
	}
	else
	{
		size++;

		for (int i = size; i > newPos; i--)
		{
			list[i] = list[i - 1];
		}
		list[newPos] = newNum;
	}

	

}

//count the odd numbers in the list and output in this function
void oddCount(const int list[], int size)
{
	int count = 0;

	for  (int i = 0; i < size; i++)
	{
		if (list[i] % 2 == 1)
			count++;
	}

	cout << "Number of odd numbers in the list is " << count << "." << endl;
}