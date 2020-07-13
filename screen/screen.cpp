// Douglas Cox
// Assignment #4 - Screen. Measuring the area of the TV based on the screen size (diagonal measurement of the screen)
// Leveraged pythagorean theorem from assignment sheet
// Added a while loop and if statements to try and make this more complete
// while loop source: https://www.tutorialspoint.com/cplusplus/cpp_while_loop.htm
// if and OR statement source: https://stackoverflow.com/questions/15209433/or-statement-in-c



#include <iostream>
#include <iomanip>


using namespace std;

int main()
{
    double area1, screenHeight1, screenWidth1, x1; //variables for 4:3 ratio

    double area2, screenHeight2, screenWidth2, x2; //variables for 16:9 ratio

    double screenSize; //screenSize input variable

    int selector = 0;

    cout << fixed << showpoint;

    cout << "What type of TV would you like to view the dimension for? \n \n"
        << "1. Traditional TV area (4:3) \n"
        << "2. LCD TV Area (16:9) \n"
        << "3. Both types of TVs area \n \n"
        << "Please enter the corresponding number for your selection: " << endl;

    cin >> selector; //user enters TV selection   

    while (cin.fail() || selector >= 4) { //validating user's input
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Something went wrong with your input, please try again." << endl;
        cin >> selector;

    } 

    cout << "What is the screen size (diagonal length) of your TV in inches?" << endl;

    cin >> screenSize; //user inputs screen size

    if (selector == 1) {
        x1 = sqrt((pow(screenSize, 2)) / 25); //calculate x in from pythagorean's theorem for a 4:3 TV
        screenHeight1 = (4 * x1); 
        screenWidth1 = (3 * x1); 
        area1 = (screenHeight1 * screenWidth1); // find the area (height * width)

        cout << setprecision(2)
            << "\nThe dimensions of your " << screenSize << " inch, 4:3 ratio TV is:\n" 
            << "Screen height: " << screenHeight1 << " inches \n"
            << "Screen width: " << screenWidth1 << "inches \n"
            << "Screen area: " << area1 << " square inches." << endl;
    }
    else if (selector == 2) {
        x2 = sqrt((pow(screenSize, 2)) / 337); //calculate x in from pythagorean's theorem for a 16:9 TV
        screenHeight2 = (16 * x2); 
        screenWidth2 = (9 * x2); 
        area2 = (screenHeight2 * screenWidth2); // find the area (height * width)

        cout << setprecision(2)
            << "\nThe dimensions of your " << screenSize << " inch, 16:9 ratio TV is: \n"
            << "Screen height: " << screenHeight2 << " inches \n"
            << "Screen width: " << screenWidth2 << "inches \n"
            << "Screen area: " << area2 << " square inches." << endl;
    }
    else if (selector == 3) {
        x1 = sqrt((pow(screenSize, 2)) / 25); //calculate x in from pythagorean's theorem for a 4:3 TV
        screenHeight1 = (4 * x1); 
        screenWidth1 = (3 * x1); 
        area1 = (screenHeight1 * screenWidth1); //find the area (height * width)
        x2 = sqrt((pow(screenSize, 2)) / 337); //calculate x in from pythagorean's theorem for a 16:9 TV
        screenHeight2 = (16 * x2); 
        screenWidth2 = (9 * x2); 
        area2 = (screenHeight2 * screenWidth2); // find the area (height * width)

        cout << setprecision(2)
            << "\nThe dimensions of your " << screenSize << " inch, 4:3 ratio TV is: \n"
            << "Screen height: " << screenHeight1 << " inches \n"
            << "Screen width: " << screenWidth1 << "inches \n"
            << "Screen area: " << area1 << " square inches. \n"
            << "\nThe dimensions of your " << screenSize << " inch, 16:9 ratio TV is: \n"
            << "Screen height: " << screenHeight2 << " inches \n"
            << "Screen width: " << screenWidth2 << "inches \n"
            << "Screen area: " << area2 << " square inches." << endl;
    }
    else {
        cout << "Something went wrong, please start over." << endl; //catch all error
    }

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
