// Assignement #2 - Ohm - output 
// Ohm's law is Voltage = Current x Resistance (also referred to as volts = amps * ohms) - depicted as E = I*R

#include <iostream>
using namespace std;

int main()
{
    double amps, ohms, volts;
    
    cout << "Lets determine how many volts are needed to supply the circuit! \n"
         << "Enter how many amps you will be supplying" << endl; 
    cin >> amps; //user enters amps
    cout << "Now enter how many ohms or resistance will be in place." << endl;
    cin >> ohms; //user enter ohms

    volts = amps * ohms; //calculate volts

    cout << "The amount of volts needed to run the circuit is " << volts << " ." << endl; //display volts
        
    return (0);
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
