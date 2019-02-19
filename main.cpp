#include <iostream>
#include "myswitch.h"

using namespace std;

typedef void (*fptr)();

template<typename Key, typename Value>
void initialize(mySwitch<Key, Value> &cases);


// Here are the three test statements
void red();
void green();
void blue();

int main()
{
    // Let's make a switch and initialize it
    mySwitch<string, fptr> choices;
    initialize(choices);

    // we will need a string
    string choice;

    do
    {
        cout << "What RBG color are you in the mood for? (enter 0 to quit)" << endl;
        cin >> choice;

        // Do the switch
        choices.switchCase(choice);
        cout << endl;
    }
    while(choice != "0");
}



template<typename Key, typename Value>
void initialize(mySwitch<Key, Value> &cases)
{
    cases.addCase("Red", &red);
    cases.addCase("red", &red);
    cases.addCase("r", &red);
    cases.addCase("R", &red);

    cases.addCase("b", &blue);
    cases.addCase("blue", &blue);
    cases.addCase("Blue", &blue);
    cases.addCase("B", &blue);

    cases.addCase("G", &green);
    cases.addCase("g", &green);
    cases.addCase("Green", &green);
    cases.addCase("green", &green);
}

void red()
{
    cout << "I am the color of cherries." << endl;
}

void green()
{
    cout << "I am the color of brocolli." << endl;
}

void blue()
{
    cout << "I am the color of blueberries." << endl;
}
