// COMSC-210 | Lab 36 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries
#include <iostream>
#include <string>
using namespace std;

// Function prototypes
int sum_ascii(string str);

// Main function
int main()
{
    // char a = 'A';
    // cout << a << endl;
    // cout << (int) a << endl;
    // int b = 66;
    // cout << b << endl;
    // cout << (char) b << endl;

    // Testing strings
    string s1 = "536B9DFC93AF";
    string s2 = "1DA9D64D02A0";
    string s3 = "666D109AA22E";
    string s4 = "E1D2665B21EA";

    // Output results
    cout << "s1: " << sum_ascii(s1) << endl;
    cout << "s2: " << sum_ascii(s2) << endl;
    cout << "s3: " << sum_ascii(s3) << endl;
    cout << "s4: " << sum_ascii(s4) << endl;

    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

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