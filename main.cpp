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
const int MIN_CHOICE = 1;
const int MAX_CHOICE = 6;

// Function prototypes
void displayMenu();
int gen_hash_index(string str);
void displayEntries(const map<int, list<string>>& hash_table);

// Main function
int main()
{
    // Create a map
    map<int, list<string>> hash_table;

    // Create int variables
    int key = 0;             // The key of the value
    int count = 0;           // The number of data lines read
    int choice = 0;          // The user's choice

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
    }

    // Implement a loop
    while (true)
    {
        // Display the menu of operations
        displayMenu();

        // Prompt the user to enter their choice
        cout << "Please enter your choice: ";
        cin >> choice;

        // Validate the choice input
        while (choice < MIN_CHOICE || choice > MAX_CHOICE)
        {
            // Prompt the user to enter a valid choice
            cout << "Error! Please enter a valid choice (1-6): ";
            cin >> choice;
        }

        // Perform the operation based on the user's choice
        switch (choice)
        {
            // Case 1: Display the first 100 entries
            case 1:
            {
                // Call the displayEntries() function
                displayEntries(hash_table);
                
                // Break
                break;
            }

            // Case 2: Search for a key
            case 2:
            {
                // Call the searchKey() function

                // Break;
                break;
            }

            // Case 3: Add a key
            case 3:
            {
                // Call the addKey() function

                // Break;
                break;
            }

            // Case 4: Remove a key
            case 4:
            {
                // Call the removeKey() function

                // Break;
                break;
            }

            // Case 5: Modify a key
            case 5:
            {
                // Call the modifyKey() function

                // Break
                break;
            }

            // Case 6: Exit
            case 6:
            {
                // Display a message
                cout << "Thank you for using this program! Exiting..." << endl;

                // Break
                break;
            }
        }
    }

    // Display a header
    cout << "First 100 keys and their buckets:" << endl;

    return 0;
}

// Function implementations
/*
    displayMenu()
    Display a menu of operations
    Arguments: none
    Return: none
*/
void displayMenu()
{
    // Display a header
    cout << " ------- Operations Menu ------- " << endl;

    // Display all the operations
    cout << "1. Display the first 100 entries" << endl;
    cout << "2. Search for a key" << endl;
    cout << "3. Add a key" << endl;
    cout << "4. Remove a key" << endl;
    cout << "5. Modify a key" << endl;
    cout << "6. Exit" << endl;

    // Display a separator
    cout << " ------------------------------- " << endl;
}

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

    // Return the sum value as the key
    return sum;
}

/*
    displayEntries()
    Display the first 100 entries of the map
    Arguments:
        - hash_table: the hash table whose entries we are displaying
    Return: none
*/
void displayEntries(const map<int, list<string>>& hash_table)
{
    // Display a message
    cout << " --- Displaying the first 100 entries --- " << endl;

    // Create an integer counter to keep track of the number of entries
    int count = 0;

    // Display the first 100 entries of the map
    for (const auto& pair : hash_table)
    {
        // If the count is larger than 100
        if (count >= 100)
        {
            break;
        }

        // Display the key
        cout << pair.first << ": ";

        // Count the number of elements that are printed
        int printed = 0;

        // Display all the data in the list
        cout << "[";
        for (auto data : pair.second)
        {
            // Display the elements
            cout << data;
            printed++;          // Increment the number of printed elements

            // Check the total number of elements printed
            if (printed >= 5 && printed < pair.second.size())
            {
                // Close the list
                cout << ", ...] (total: " << pair.second.size() << ")" << endl;
                
                // Break out of the loop
                break;
            }
            else if (printed >= pair.second.size())
            {
                // CLose the list
                cout << "] (total: " << pair.second.size() << ")" << endl;

                // Break out of the loop
                break;
            }
            else
            {
                // Display a comma and a space
                cout << ", ";
            }
        }

        // Increment the count
        count++;
    }

    // Enter a new line
    cout << endl;
}