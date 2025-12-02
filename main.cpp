// COMSC-210 | Lab 37 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
using namespace std;

// Constants
const string DATA_FILE = "data.txt";
const int MODULO = 97; 

// Function prototypes
int gen_hash_index(string str);

// Main function
int main()
{
    // Create a map
    map<int, list<string>> hash_table;

    // Create int variables
    int key = 0;            // The key of the value
    int count = 0;          // The number of data lines read

    // Create string variables
    string dataFile = DATA_FILE;           // Store the data file's path
    string line = "";                      // Store the line's data

    // Create a file stream and open the file
    ifstream fin;
    fin.open(dataFile);

    // Create a loop and read all the lines in the data file 
    while (getline(fin, line))
    {
        // Get the hash key
        key = gen_hash_index(line);

        // Insert the data into the map
        hash_table[key].push_front(line);
        count++;          // Increment the count

        // Display the first 100 entries
        if (count <= 100)
        {
            // Display the key and value
            cout << count << ": [Key: " << key << ", value: " << line << "]" << endl;
        }
    }

    return 0;
}

// Function implementations
/*
    gen_hash_index()
    Calculate the sum of all the characters in a string based on the ASCII table
    Arguments:
        - str: the string whose characters' ASCII sum values we need to calculate
    Return:
        - an integer representing the sum of that string's character's ASCII values
*/
int gen_hash_index(string str)
{
    // Create an integer variable to store the sum
    int sum = 0;

    // Iterate through the string and calculate the sum of each characters
    for (int i = 0; i < str.length(); i++)
    {
        // Add the ASCII value of the character to the sum
        sum += (int) str.at(i);
    }

    // Return the sum value mod 97 (return the hash key)
    return sum % MODULO;
}