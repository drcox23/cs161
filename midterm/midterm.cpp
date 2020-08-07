// Douglas Cox
// Midterm Proficiency Exam
// 07/30/2020

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int input; 
    int evenSum = 0;
    int oddSum = 0;
    int evenCount = 0;
    int oddCount = 0; 

    cout << "Hi! This program is designed to read any positive numbers you input!\n"
        << "The program shall ouput the sum of all the even numbers, sum of all the odd numbers,\n"
        << "count of all the even numbers and count of all the odd numbers. \n \n"
        << "Lets start! Please enter your positive numbers. To show the outputs, please enter -999. \n"
        << "All negative numbers will be ignored. Enjoy! \n" << endl; 

    do
    {
        cin >> input;
        
        while (cin.fail()) // input validation - ensuring the user inputs integers only. 
        {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "Something went wrong, please be sure to enter whole intergers only" << endl;
            cin >> input;
        }

        if (input % 2 == 0 && input >= 0) //checks if input is an even number and is a positive number. If so, increases the count by 1 and adds to the sum. 
        {
            evenCount++; 
            evenSum = evenSum + input; 
        }
        else if (input % 2 == 1 && input > 0) //checks if input is an odd number and is a positive number. If so, increases the count by 1 and adds to the sum. 
        {
            oddCount++;
            oddSum = oddSum + input;
        }

    } while (input != -999); // stops while loop at Sentinel of -999. 

    cout << "\nThe sum of all even numbers is " << evenSum << ".\n"
        << "The sum of all odd number is " << oddSum << ".\n"
        << "The count of all even numbers is " << evenCount << ".\n"
        << "The count of all odd numbers is " << oddCount << ".\n" << endl;

    return (0); 
}


