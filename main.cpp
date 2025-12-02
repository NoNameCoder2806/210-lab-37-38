// COMSC-210 | Lab 37 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Constants
const string DATA_FILE = "data.txt";

// Function prototypes
int sum_ascii(string str);

// Main function
int main()
{
    // Create an int variable to store the sum
    int sum = 0;

    // Create string variables
    string dataFile = DATA_FILE;           // Store the data file's path
    string line = "";                      // Store the line's data

    // Create a file stream and open the file
    ifstream fin;
    fin.open(dataFile);

    // Create a loop and read all the lines in the data file 
    while (getline(fin, line))
    {
        // Add the sum of the line
        sum += sum_ascii(line);
    }

    // Output results
    cout << "sum: " << sum << endl;

    return 0;
}

// Function implementations
/*
    sum_ascii()
    Calculate the sum of all the characters in a string based on the ASCII table
    Arguments:
        - str: the string whose characters' ASCII sum values we need to calculate
    Return:
        - an integer representing the sum of that string's character's ASCII values
*/
int sum_ascii(string str)
{
    // Create an integer variable to store the sum
    int sum = 0;

    // Iterate through the string and calculate the sum of each characters
    for (int i = 0; i < str.length(); i++)
    {
        // Add the ASCII value of the character to the sum
        sum += (int) str.at(i);
    }

    // Return the sum value
    return sum;
}