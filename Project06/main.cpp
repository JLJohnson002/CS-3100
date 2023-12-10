// 1. Jimmy Johnson
// 2. 12/9/23
// 3. Project 6 Hash Table

#include "HashTable.h"
#include "Database.h"

#include <iostream>
#include <array>
using namespace std;

int main()
{
    // Variables
    int collisions = 0;
    bool running = true;
    Database myDataBase;
    string lastName;
    string firstName;
    int UID;
    string year;
    Record record;
    char response;

    // Loop while program is operating
    while (running)
    {
        cout << endl;
        cout << "Would you like to (I)nsert, (D)elete, or (S)earch for a record, (P)rint the database, or (Q)uit?" << endl;
        cout << "Enter action: ";

        cin >> response;
        cout << endl;

        switch (response)
        {
        case 'I': // Insert
            cout << "Inserting a new record." << endl;

            cout << "Last name: ";
            cin >> lastName;
            cout << "First name: ";
            cin >> firstName;
            cout << "UID: ";
            cin >> UID;
            cout << "Year: ";
            cin >> year;

            record.setFirstName(firstName);
            record.setLastName(lastName);
            record.setUID(UID);
            record.setYear(year);

            if (myDataBase.insert(record, collisions) == true)
            {
                cout << "Record inserted ("
                     << collisions << " collisions during insert)." << endl;
            }
            else
            {
                cout << "Record not inserted" << endl;
            }
            break;

        case 'D': // Delete
            cout << "What is the UID of the record to be deleted? ";
            cin >> UID;
            if (myDataBase.remove(UID) == true)
            {
                cout << "Record deleted." << endl;
            }
            else
            {
                cout << "Record not deleted." << endl;
            }
            break;

        case 'S': // Search
            cout << "Enter UID to search for : ";
            cin >> UID;
            cout << "Searching... ";

            if (myDataBase.find(UID, record, collisions) == true)
            {
                cout << "record found (" << collisions << " collisions during search)" << endl;
                cout << "----------------------------" << endl;
                cout << "Last name: " << record.getLastName() << endl;
                cout << "First name: " << record.getFirstName() << endl;
                cout << "UID: " << record.getUID() << endl;
                cout << "Year: " << record.getYear() << endl;
                cout << "----------------------------" << endl;
            }
            else
            {
                cout << "record not found" << endl;
            }
            break;

        case 'P': // Print
            cout << myDataBase << endl;
            break;

        case 'Q': // Quit
            running = false;
            break;
        }
    }
}