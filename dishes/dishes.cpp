// Douglas Cox
// Assignment 5 - dishes
// Sources: D.S. Malik Ch 5.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    //store file path input by user
    string filePath;

    //variables from input file
    int dish, additionalTime, totalTimeAllowed; 
    
    //declare stream variables
    ifstream inputFile;
    ofstream outputFile;

    cout << "Please input the full PATH of data file (no quotations marks)" << endl;
    cin >> filePath;

    inputFile.open(filePath);

    //** check to see if the input file can be found **
    while (!inputFile.is_open()) 
    {
        cout << "Something went wrong and we cannot find your file.\nPlease enter the Path again again." << endl;
        cin >> filePath;
        inputFile.open(filePath);
    }

    outputFile.open("DC_assignment5_output.txt");
    
    //** echo input file **
    cout << "Below is what is in the input file:" << endl;
    while (!inputFile.eof())
    {
        inputFile >> dish >> additionalTime >> totalTimeAllowed;
        cout << right << setw(10) << dish << setw(10) << additionalTime << setw(10) << totalTimeAllowed << endl;
    }

    inputFile.close(); //close input file since while loop has read it.
    inputFile.open(filePath); //reopen input file

    cout << "\n \nHere are the calculations of what can be cooked:\n" << endl;
    while (!inputFile.eof())
    {
        inputFile >> dish >> additionalTime >> totalTimeAllowed; //assign input values to variables

        int totalDishes = 0;
        int nextDish = 0;
        int availTime = totalTimeAllowed;

        // ** calculate if there is enough time to make an additional dish **
        while (availTime >= nextDish)
            {   
                nextDish = dish + (additionalTime * totalDishes);
                totalDishes++;
                availTime = availTime - nextDish;
            }
           
        // ** write to output file **
        outputFile << right << setw(10) << dish << setw(10) << additionalTime << setw(10) << totalTimeAllowed << setw(30) << "total possible dishes: " << totalDishes << setw(10) << endl;

        cout << right << setw(10) << dish << setw(10) << additionalTime << setw(10) << totalTimeAllowed << setw(30) << "total possible dishes: " << totalDishes << setw(10) << endl;
        
    }
    
    outputFile.close();
    inputFile.close();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
