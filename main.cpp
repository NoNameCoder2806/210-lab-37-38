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
void searchKey(const map<int, list<string>>& hash_table);
void addKey(map<int, list<string>>& hash_table);
void removeKey(map<int, list<string>>& hash_table);
void modifyKey(map<int, list<string>>& hash_table);

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
                searchKey(hash_table);

                // Break;
                break;
            }

            // Case 3: Add a key
            case 3:
            {
                // Call the addKey() function
                addKey(hash_table);

                // Break;
                break;
            }

            // Case 4: Remove a key
            case 4:
            {
                // Call the removeKey() function
                removeKey(hash_table);

                // Break;
                break;
            }

            // Case 5: Modify a key
            case 5:
            {
                // Call the modifyKey() function
                modifyKey(hash_table);

                // Break
                break;
            }

            // Case 6: Exit
            case 6:
            {
                // Display a message
                cout << "Thank you for using this program! Exiting..." << endl;

                // Exit the program
                return 0;
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
    Display the first 100 entries of the hash table
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

        // Check whether the bucket is empty
        if (pair.second.size() == 0)
        {
            // Display the key
            cout << pair.first << " (total: 0)" << endl;
            count++;          // Increment the count

            // Skip to the next key in the map
            continue;
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

/*
    searchKey()
    Search for a key in the hash table and display the total number of elements in the bucket
    Arguments:
        - hash_table: the hash table whose entries we are displaying
    Return: none
*/
void searchKey(const map<int, list<string>>& hash_table)
{
    // Display a message
    cout << " --- Searching for a key --- " << endl;

    // Create a variable to store the key
    int key = 0;

    // Prompt the user to enter the key to search for
    cout << "Please enter the key you want to search for: ";
    cin >> key;

    // Create an iterator and use it to find the key
    auto it = hash_table.find(key);

    // Check whether the key exist by comparing the iterator to the end of the map
    // Explanation: if iterator points to the end of the map, then the key doesn't exist
    if (it != hash_table.end())
    {
        // Check for the size of the list
        if (it->second.size() != 0)
        {
            // Display a message
            cout << "Key found! Total number of strings: " << it->second.size() << endl;
        }
        else          // Otherwise, if the list has no string
        {
            // Display a message
            cout << "Key found! Bucket is currently empty!" << endl;
        }
    }
    else          // Otherwise, the key does not exist
    {
        // Display a message
        cout << "Key not found!" << endl;
    }
}

/*
    addKey()
    Add a key to the hash table
    Arguments:
        - hash_table: the hash table to add the key to
    Return: none
*/
void addKey(map<int, list<string>>& hash_table)
{
    // Display a message
    cout << " --- Adding a key --- " << endl;

    // Create a variable to store the key
    int key = 0;

    // Prompt the user to enter the key to search for
    cout << "Please enter the key you want to search for: ";
    cin >> key;

    // Create an iterator and use it to find the key
    auto it = hash_table.find(key);

    // Check whether the key had existed in the hash table
    if (it != hash_table.end())
    {
        // Display a message
        cout << "Key already existed!" << endl;
    }
    else          // Otherwise, we insert the key
    {
        // Create an empty string list
        list<string> tempList;

        // Insert the key into the table
        hash_table.insert(make_pair(key, tempList));

        // Display a message
        cout << "Added key " << key << " to the hash table!" << endl;
    }
}

/*
    removeKey()
    Remove a key from the hash table
    Arguments:
        - hash_table: the hash table to remove the key from
    Return: none
*/
void removeKey(map<int, list<string>>& hash_table)
{
    // Display a message
    cout << " --- Removing a key --- " << endl;

    // Create a variable to store the key
    int key = 0;

    // Prompt the user to enter the key to search for
    cout << "Please enter the key you want to search for: ";
    cin >> key;

    // Create an iterator and use it to find the key
    auto it = hash_table.find(key);

    // Check whether the key exists in the hash table
    if (it != hash_table.end())
    {
        // If the key exists, we remove it from the hash table
        hash_table.erase(key);

        // Display a message
        cout << "Removed key " << key << " from the hash table!" << endl;
    }
    else          // Otherwise, we do nothing
    {
        // Display a message
        cout << "Key " << key << " does not exist!" << endl;
    }
}

/*
    modifyKey()
    Allows the user to modify the list of the key
    Arguments:
        - hash_table: the hash table whose key we want to modify
    Return: none
*/
void modifyKey(map<int, list<string>>& hash_table)
{
    // Display a message
    cout << " --- Modifying a key --- " << endl;

    // Create a variable to store the key
    int key = 0;

    // Prompt the user to enter the key to search for
    cout << "Please enter the key you want to modify: ";
    cin >> key;

    // Create an iterator and use it to find the key
    auto it = hash_table.find(key);

    // Check whether the key exists in the hash table
    if (it != hash_table.end())
    {
        // If the key exists, we prompt the user to enter a new key
        int newKey = 0;
        cout << "Please enter a new key: ";
        cin >> newKey;

        // Check whether the new key existed
        auto it2 = hash_table.find(newKey);
        if (it2 != hash_table.end())
        {
            // If the key exists, we display a message and do nothing
            cout << "The new key " << newKey << " already exists!" << endl;
        }
        else
        {
            // Otherwise, we copy the bucket
            list<string> newList = it->second;

            // Then we erase the old key
            hash_table.erase(key);

            // And finally, we insert the new key
            hash_table.insert(make_pair(newKey, newList));

            // Display a message
            cout << "Key " << key << " is changed to " << newKey << "!" << endl;
        }
    }
    else          // Otherwise, we do nothing
    {
        // Display a message
        cout << "Key " << key << " does not exist!" << endl;
    }
}
