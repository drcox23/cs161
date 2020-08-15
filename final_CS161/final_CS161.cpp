// Douglas Cox
// 08/15/20202
// CS 161 Final

//This program is your final exam.
//Please fill in the functions at the bottom of the file.  (evenCount and insertItem)
//DO NOT CHANGE ANYTHING ELSE.
//main has all the code needed to test your functions.  Once your functions are written, please build and make sure it works fine

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//constants
const int CAP = 100;

//function prototypes
bool openFile(ifstream&);
void readData(ifstream&, int[], int&);
void printData(const int[], int);
void evenCount(const int[], int);
void insertItem(int[], int&, int, int);


int main()
{
	ifstream inFile;
	int list[CAP], size = 0;
	int insert[3] = { 15, 101, 215 }, position[3] = { 5, 2, 18 };

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
	for (int i = 0; i < 3; ++i) {
		insertItem(list, size, insert[i], position[i]);
		cout << "Inserted " << insert[i] << " in position " << position[i] << ":" << endl;
		printData(list, size);
	}

	//call the evenCount function
	evenCount(list, size);
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

//reads the data from the file
void printData(const int list[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << right << setw(10) << i;
		cout << right << setw(10) << list[i] << endl;
	}
	cout << endl;
}

//insert an item (newNum) in the given position (newPos)
void insertItem(int list[], int& size, int newNum, int newPos)
{
	if (newPos < size && newNum > 0) // if newPos is outside of the range OR newNum is negative, no insert is performed. 
	{
		size++; //increment size to allow for insert

		for (int i = size; i >= newPos; i--) //move numbers to new position to allow insert
		{
			list[i] = list[i - 1];
		}
		list[newPos] = newNum; // insert newNum in designated position.
	}
}

//count the even numbers in the list and output in this function
void evenCount(const int list[], int size)
{
	int count = 0;

	// loop through the list and determine if the number is even. If even, increment count.
	for (int i = 0; i < size; i++)
	{
		if (list[i] % 2 == 0)
			count++;
	}

	cout << "The total number of even numbers in the list is " << count << "." << endl;

}
