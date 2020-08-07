// Douglas Cox
// Assignment #7 - Weather
// 08/06/2020
// Source: Malik Textbook

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// function prototypes
void loadData(ifstream& inputFile, string months[], int temp[][2], int& rows);
double averageHigh(string months[], int temp[][2], int rows, string& month, int& hightemp);
double averageLow(string months[], int temp[][2], int rows, string& month, int& lowtemp);

int main()
{
    // constant variable for months in a year
    const int MONTHS_IN_YEAR = 12;
    
    ifstream inputFile;
    
    // variables to pass as parameters to functions
    string months[MONTHS_IN_YEAR];
    int temp[MONTHS_IN_YEAR][2];
    string month;
    int hightemp;
    int lowtemp;
    int rows;

    //load data into designated arrays and echo input file
    loadData(inputFile, months, temp, rows);

    // calculate high temp and corresponding month
    averageHigh(months, temp, rows, month, hightemp);

    //calculate low temp and corresponding month
    averageLow(months, temp, rows, month, lowtemp);
    

    return (0);
}

void loadData(ifstream& inputFile, string months[], int temp[][2], int& rows)
{
    const int NUMBER_OF_ROWS = 12;
    const string FILEPATH = "./temps.txt";

    inputFile.open(FILEPATH.c_str());

    // check if input file is valid
    if(!inputFile.is_open())
    {
        cout << "Something went wrong and we cannot find your file.\n"
            <<"Please make sure that the file is in the same directory as this project." << endl;
        return;
    }
    
    // insert data from input file into corresponding arrays
    while (!inputFile.eof())
    {
        for (rows = 0; rows < NUMBER_OF_ROWS; rows++)
        {
            inputFile >> months[rows] >> temp[rows][0] >> temp[rows][1];
            
            cout << setw(12) << months[rows] << setw(4) << temp[rows][0] << setw(4) << temp[rows][1] << endl;
        }
        return;
    }
    inputFile.close();
}

double averageHigh(string months[], int temp[][2], int rows, string& month, int& hightemp)
{
    const int NUMBER_OF_ROWS = 12;
    double calcHigh = temp[0][0];
    int correspondingMonth;

    // determine highest temperature of the year
    for (rows = 0; rows < NUMBER_OF_ROWS; rows++)
    {
        if (temp[rows][0] >= calcHigh)
        {
            calcHigh = temp[rows][0];
            correspondingMonth = rows;
        }
    }

    hightemp = calcHigh;

    cout << "\nThe highest temperature of the year was " << calcHigh << " degrees, "
        << "and was recorded in the month of " << months[correspondingMonth] << ".\n" << endl;

    return calcHigh;
}

double averageLow(string months[], int temp[][2], int rows, string& month, int& lowtemp)
{
    const int NUMBER_OF_ROWS = 12;
    double calcLow = temp[0][1];
    int correspondingMonth;

    // determin lowest temperature of the year
    for (rows = 0; rows < NUMBER_OF_ROWS; rows++)
    {
        if (temp[rows][1] <= calcLow)
        {
            calcLow = temp[rows][1];
            correspondingMonth = rows;
        }
    }

    lowtemp = calcLow;

    cout << "\nThe lowest temperature of the year was " << calcLow << " degrees, "
        << "and was recorded in the month of " << months[correspondingMonth] << ".\n" << endl;

    return calcLow;
}