/*********************************************************
* AUTHOR  : Sofia Pineda
* Lab#3   : Function Pointers
* CLASS   : CS 3A
* SECTION : MW: 6 pm - 9: 30 pm
* Due Date: 9 / 27 / 2017
**********************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

typedef void (*fptr)(int *array, int size);
typedef void (*swapper)(int &, int &);

void initialize(fptr menu[]);

void choiceMenu(int *array, int size, fptr toDo);

void display(int *array, int size);
void median(int *array, int size);
void mean(int *array, int size);
void stdDev(int *array, int size);
void regen(int *array, int size);
void quit(int *array, int size);
void reDo(int *array, int size);

void sort(int list[], int size);
void swap(int &x, int &y);
void noSwap(int &, int &);

/**********************************************************
*
* Function Pointers
*_________________________________________________________
* This program generates an array of random numbers and
* then displays a menu of options of Display, Median, Mean,
* and Standard Deviation, Regenerate, and Quit.
*________________________________________________________
***********************************************************/

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int *arra;
    int amt;
    bool run = true;

    fptr menu[127];

    char choice;

    do
    {
        cout << "How many random numbers do you wish to input?" << endl;
        cin >> amt;

    } while (amt < 0);

    arra = new int[amt];

    cout << "Generating List..." << endl;
    regen(arra, amt);

    initialize(menu);

    // Begin While Loop
    do
    {
        cout << endl << "What would you like to do?" << endl;
        cout << "Here is the Menu: " << endl;
        cout << "1. display, 2. median, 3. mean, 4. stdDev, 5. regen, 6. quit" << endl << endl;
        cin >> choice;
        // Run the requested function
        choiceMenu(arra, amt, menu[choice]);

    } while(run);

}

void initialize(fptr menu[])
{
   for(int i = 0; i < 127; ++i)
       menu[i] = reDo;

    menu[49] = display;
    menu[50] = median;
    menu[51] = mean;
    menu[52] = stdDev;
    menu[53] = regen;
    menu[54] = quit;
}

void choiceMenu(int *array, int size, fptr toDo)
{
    cout << "Performing requested function." << endl;
    toDo(array, size);
}

void regen(int *array, int size)
{
    for (int i = 0; i < size; ++i)
        array[i] = rand() % 100;

    display(array, size);
}

void display(int *array, int size)
{
    cout << "Displaying List." << endl << endl;

    for (int i = 0; i < size; ++i)
        cout << setw(4) << array[i];
}

void median(int *array, int size)
{
    // Re-Arrange Array
    sort(array, size);

    cout << "The Median of the array is: " << array[size/2] << endl;
}

void mean(int *array, int size)
{
    int total = 0;
    double mean;

    for (int i = 0; i < size; ++i)
        total += array[i];

    mean = total / size;

    cout << "The Mean of the Array is: " << mean << endl;
}

void stdDev(int *array, int size)
{
    int total = 0;
    double values = 0;
    double mean;

    for (int i = 0; i < size; ++i)
        total += array[i];

    mean = total / size;

    for (int j = 0; j < size; ++j)
        values += sqrt(abs(array[j] - mean));

    values /= size;
    values = sqrt(values);

    cout << "The Standard Deviation of the Array is: " << values << endl;

}

void reDo(int *array, int size)
{
    cout << "Invalid Input. Try again." << endl;
}

void quit(int *array, int size)
{
    cout << "Quitting program. Goodbye." << endl;
    exit(0);
}

void sort(int list[], int size)
{
    static swapper whatToDo[2] = {noSwap, swap};

    for(unsigned int i = 0; i < size; ++i)
        for(unsigned j = 0; j < size; ++j)
            (whatToDo[list[i] < list[j]])(list[i], list[j]);
}


void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void noSwap(int &, int &)
{

}
