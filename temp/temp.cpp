// Douglas Cox
// Assignment 8
// 08/13/2020
// Source: Malik textbook && reused some lines of code from previous assignment, but tailored it to fit structs.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// determine struct members
struct Temperature
{
    string month;
    int high;
    int low;
};

// function prototypes
void loadData(ifstream& inputFile, Temperature[], int& size);
void averageHigh(Temperature[], int size);
void averageLow(Temperature[], int size); 

int main()
{
    const int MONTHS_YEAR = 12;
    int size = 12;

    //initialize input file
    ifstream inputFile;

    // initialize struct
    Temperature tempData[MONTHS_YEAR]; 

    loadData(inputFile, tempData, size);

    averageHigh(tempData, size);

    averageLow(tempData, size);

    return 0;
}

void loadData(ifstream& inputFile, Temperature temp [], int& size)
{
    const string FILE = "./temps.txt";
    const int MONTHS = 12;
    
    inputFile.open(FILE.c_str());

    if(!inputFile.is_open())
    {
        cout << "Something went wrong and we cannot find your file.\n"
            << "Please make sure that the file is in the same directory as this project." << endl;
        return;
    }
    else {
        cout << "Below is the data from the input file" << endl;
    }

    //read input file
    while (!inputFile.eof())
    {
        for (size = 0; size < MONTHS; size++)
        {
            inputFile >> temp[size].month >> temp[size].high >> temp[size].low;

            cout << setw(12) << temp[size].month << setw(4) << temp[size].high << setw(4) << temp[size].low << endl;
        }
        return;
    }
    inputFile.close();

    return;
}

void averageHigh(Temperature temp [], int size)
{
    const int NUMBER_OF_ROWS = 12;

    int calcHigh = temp[0].high;
    string correspondingMonth;

    // determine highest temperature of the year
    for (size = 0; size < NUMBER_OF_ROWS; size++)
    {
        if (temp[size].high >= calcHigh)
        {
            calcHigh = temp[size].high;
            correspondingMonth = temp[size].month;
        }
    }

    cout << "\nThe highest temperature of the year was " << calcHigh << " degrees, "
        << "and was recorded in the month of " << correspondingMonth << ".\n" << endl;

    return;
}

void averageLow(Temperature temp[], int size)
{
    const int NUMBER_OF_ROWS = 12;

    int calcLow = temp[0].low;
    string correspondingMonth;

    // determine lowest temperature of the year
    for (size = 0; size < NUMBER_OF_ROWS; size++)
    {
        if (temp[size].low <= calcLow)
        {
            calcLow = temp[size].low;
            correspondingMonth = temp[size].month;
        }
    }

    cout << "The lowest temperature of the year was " << calcLow << " degrees, "
        << "and was recorded in the month of " << correspondingMonth << ".\n" << endl;

    return;
}

