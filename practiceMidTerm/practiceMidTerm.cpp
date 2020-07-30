//Douglas Cox
//07/29/2020
//practiceMidTerm.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Grading Criteria:

1 pt: Program compiles without errors and displays a brief description of the program.
1 pt: Program has complete header comments (Program name, description, programmer’s name, date, sources)
1 pt: Program includes helpful comments in the code
2 pts: Program fundamentals are good: main( ), #includes, appropriate variables with meaningful names, prompts for and accepts user input in the proper format, nice output, code demonstrates techniques we’ve learned in class so far, etc.
2 pts: Program effectively demonstrates selection (if/else, or switch) and looping (while, for, or do...while) to accomplish its objectives
3 pts: Produces the correct results
Question 1 (10 points)
Write a program that

Displays a brief description of the program.
In a loop, …
Prompts for and accepts an integer from the user.
The loop should terminate when the user enters 0.
Counts the number of values entered by the user, not including the 0 that terminated the loop.
Keeps track of the smallest and largest value that the user enters, not including the 0 that terminated the loop.
After the loop, displays the number of values entered, the smallest value and the largest value.
*/

#include <iostream>

using namespace std;

int main()
{
    int value; 
    int min, max; 

    cout << "Hello! This program will determine the smallest and largest intergers input by the user \n"
        << "Please enter any whole integer and press enter. To calculate enter '0' \n" << endl;

    cin >> value; 

    // input validation
    while (cin.fail() || value == 0)
    {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Sorry, something went wrong. Please be sure you enter an integer and the first input can not be '0'" << endl;
        cin >> value;
    }

    min = value;
    max = value;

    do
    {
        cin >> value;

        //input validation
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "Sorry, something went wrong. Please be sure you enter an integer." << endl;
            cin >> value;
        }
        if (value > max)
        {
            max = value;
        }
        else if (value < min)
        {
            min = value;
        }
            
    } while (value != 0);
    
    // display results
    cout << "The smallest integer entered was " << min << ". \n"
        << "The largest integer entered " << max << ". \n \n"
        << "Thank you!" << endl;

    return (0); 
        
}

