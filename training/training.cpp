// Douglas Cox
// Assigment #6
// Sources: [TBD]

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

// function prototypes to be used within the program
void information();
void getInfo(bool& senior, int& months, int& personal);
double calcCost(bool senior, int months, int personal);
void selectOptions(char& selection);

int main()
{
    //local variables to the main function
    char selection;
    bool senior;
    int months;
    int personal;

    // show membership info
    information();

    // prompt user to select program options
    selectOptions(selection);

    // leave program running while selection is not 'b' (quit program)
    do
    {
        if (selection == 'a')
        {
        getInfo(senior, months, personal);
        selectOptions(selection);
        }
    } while (selection != 'b'); 

    return (0);
    
}

void getInfo(bool& senior, int& months, int& personal)
{
    char ageID;
    bool validAge;
    
    cout << "Great! Lets gather some information.\n \n"
        << "Are you a older than 60 years old? (y/n)" << endl;

    cin >> ageID;
    ageID = tolower(ageID);

    //input validation
    do
    {
        if (ageID == 'y' || ageID == 'n')
        {
            validAge = true;
        }
        else
        {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "Something went wrong, please input y or n" << endl;
            cin >> ageID;
            ageID = tolower(ageID);
            validAge = false;
        }
    } while (!validAge);

    if (ageID == 'y')
    {
        senior = true;
    }
    else
    {
        senior = false;
    }

    cout << "How many months of membership would you like?" << endl;

    cin >> months;

    // input validation for membership length 
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Something went wrong, please input a valid integer" << endl;
        cin >> months;
    }

    cout << "How many personal training sessions would you like?" << endl;

    cin >> personal;

    // input validation for personal training 
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Something went wrong, please input a valid integer" << endl;
        cin >> personal;
    }

    cout << fixed << showpoint;
    cout << setprecision(2);

    if (!senior) 
    {
        cout << "\nFor a Non Senior Citizen with a " << months << " month membership and " << personal << " training sessions, the cost is $" << (calcCost(senior, months, personal)) << endl;
    }
    else
    {
        cout << "\nFor a Senior Citizen with a " << months << " month membership and " << personal << " training sessions, the cost is $" << (calcCost(senior, months, personal)) << endl;
    }
        
}

void information()
{
    cout << "Welcome! Below are the details of our membership options: \n \n"
        << "The membership fee is $50 per month \n"
        << "The personal training session fee is $30 per session \n"
        << "The senior citizens discount is 30% off the total (for anyone 60 years or older) \n"
        << "If the membership is bought and paid for 12 or more months, the discount is 15% \n"
        << "If more than five personal training sessions are boughtand paid for, the discount on each session is 20%." << endl;
}

void selectOptions(char& selection)
{
    bool validSelect;
    
    cout << "\nPlease select one of the options by entering the corresponding letter:\n \n"
        << "a. Calculate membership costs\n"
        << "b. Quit this program \n" << endl;

    cin >> selection;
    selection = tolower(selection);
    
    //input validation
    do
    {
        if (selection == 'a' || selection == 'b')
        {
            validSelect = true;
        }
        else
        {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "Something went wrong, please input a or b" << endl;
            cin >> selection;
            selection = tolower(selection);
            validSelect = false;
        }
    } while (!validSelect);
    
}

double calcCost(bool senior, int months, int personal) 
{
    double total;
    bool yearPlusDisc = false;
    bool persTrainDisc = false;

    // set constants for percent discounts and fee costs
    const double YEAR_OR_MORE_DISCOUNT = .15;
    const double PERSONAL_TRAINING_DISCOUNT = .20;
    const double SR_CITIZEN_DISCOINT = .30;
    const double MEMBERSHIP_FEE = 50;
    const double PERS_TRAINING_FEE = 30;

    if (months >= 12)
        yearPlusDisc = true;
    if (personal > 5)
        persTrainDisc = true;

    // various calculations for discounts. 
    if ((senior == true) && (yearPlusDisc == true) && (persTrainDisc == true))
    {
        total = ((1 - SR_CITIZEN_DISCOINT) * (((1 - YEAR_OR_MORE_DISCOUNT) * (months * MEMBERSHIP_FEE)) + ((1 - PERSONAL_TRAINING_DISCOUNT) * (personal * PERS_TRAINING_FEE))));
    }
    else if ((senior == true) && (yearPlusDisc == true) && (persTrainDisc == false))
    {
        total = ((1 - SR_CITIZEN_DISCOINT) * (((1 - YEAR_OR_MORE_DISCOUNT) * (months * MEMBERSHIP_FEE)) + (personal * PERS_TRAINING_FEE)));
    } 
    else if ((senior == true) && (yearPlusDisc == false) && (persTrainDisc == true))
    {
        total = ((1 - SR_CITIZEN_DISCOINT) * ((months * MEMBERSHIP_FEE) + ((1 - PERSONAL_TRAINING_DISCOUNT) * (personal * PERS_TRAINING_FEE))));
    } 
    else if ((senior == false) && (yearPlusDisc == true) && (persTrainDisc == true))
    {
        total = (((1 - YEAR_OR_MORE_DISCOUNT) * (months * MEMBERSHIP_FEE)) + ((1 - PERSONAL_TRAINING_DISCOUNT) * (personal * PERS_TRAINING_FEE)));
    } 
    else if ((senior == true) && (yearPlusDisc == false) && (persTrainDisc == false))
    {
        total = ((1 - SR_CITIZEN_DISCOINT) * ((months * MEMBERSHIP_FEE) + (personal * PERS_TRAINING_FEE)));
    }
    else if ((senior == false) && (yearPlusDisc == false) && (persTrainDisc == true))
    {
        total = ((months * MEMBERSHIP_FEE) + ((1 - PERSONAL_TRAINING_DISCOUNT) * (personal * PERS_TRAINING_FEE)));
    }
    else if ((senior == false) && (yearPlusDisc == true) && (persTrainDisc == false))
    {
        total = (((1 - YEAR_OR_MORE_DISCOUNT) * (months * MEMBERSHIP_FEE)) + (personal * PERS_TRAINING_FEE));
    } else if((senior == false) && (yearPlusDisc == false) && (persTrainDisc == false))
    {
        total = ((months * MEMBERSHIP_FEE) + (personal * PERS_TRAINING_FEE));
    }

    return total;
}


