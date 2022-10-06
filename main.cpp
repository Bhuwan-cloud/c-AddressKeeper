#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void addContacts();
void viewContacts();
void searchContacts();
void editContacts();
void deleteContacts();

int main()
{

    system("cls");

    bool run = true;
    do
    {
        int Option;

        cout << ".............................Address Keeper.............................." << endl;
        cout << "n";
        cout << "What would you like to do ?" << endl;
        cout << " 1) Add Contact " << endl;
        cout << " 2) Edit Contact " << endl;
        cout << " 3) Delete Contacts" << endl;
        cout << " 4) View All Contacts" << endl;
        cout << " 5) Search Contacts" << endl;
        cout << " 6) Exit " << endl;
        cout << " 7) Choose an option " << endl;
        cout << "..........................................................." << endl;

        cin >> Option;

        cin.ignore();

        switch (Option)
        {
        case 1:
            addContacts();
            break;
        case 2:
            editContacts();
            break;
        case 3:
            deleteContacts();
            break;
        case 4:
            viewContacts();
            break;
        case 5:
            searchContacts();
            break;
        case 6:
            run = false;
            break;

        default:
            cout << "Please Choose between 1 to 6" << endl;
        }
        //  recursive main() call
        int main();

    } while (run);

    cout << " program terminated ";
}

// -----------------------------------add Contacts ---------------------------------------------------------------------

void addContacts()
{
    system("cls");

    string Fname, Lname, Address, Contact, list, name, Fname2, Lname2, Address2, Contact2;
    double counter, number;

    cout << " ...................................Address Book ................................." << endl
         << endl;
    cout << "Do not use spaces if entry has 2 or more words ex: KyleAdrian" << endl;
    cout << "Enter 'quit' at First name to quit" << endl
         << endl;
    cout << "Enter First Name: ";

    //  grabing string data

    getline(cin, Fname);

    if (Fname == "quit")
    {
        main();
    }

    cout << "Enter Last Name: ";
    getline(cin, Lname);
    cout << "Enter Address: ";
    getline(cin, Address);
    cout << "Enter Contact Number: ";
    getline(cin, Contact);

    //  writing to file using constructor
    // syntax -->  ifstream object_name ( " file name ");
    ifstream in("AdressKeeper.txt");

    while (in >> counter >> Fname2 >> Lname2 >> Address >> Contact2)
    {
        if (counter == 100)
        {
            cout << " Invalid:  Max numbers of contacts reached ";
            main();
        }
        else
        {
            number = counter;
        }
    }

    //  reading from file

    ofstream out("AddressKeeper.txt", ios::app);
    number = number + 1;
    out << number << " " << Fname << " " << Lname << " " << Address << " " << Contact << endl;

    system("pause");
    system("cls");
}
// ---------------------------------view contacts --------------------------------------------------------------

// Show all entries in the data base.
void viewContacts()
{
    system("cls");
    double counter;
    string Fname, Lname, Address, Contact;
    ifstream addressbook("AddressBook.txt");
    cout << "Entry #" << setw(17) << "First Name" << setw(23) << "Last Name" << setw(23) << "Address" << setw(29) << "Contact" << endl
         << endl;
    while (addressbook >> counter >> Fname >> Lname >> Address >> Contact)
    {
        cout << setw(3) << counter << setw(18) << Fname << setw(25) << Lname << setw(25) << Address << setw(30) << Contact << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
}

// -------------------------------------search Contacts---------------------------------------------

void searchContacts()
{

    system("cls");

    int choice;
    double counter, number;

    string Fname, Lname, Address, Contact, Fname2, Lname2, Address2, Contact2;

    cout << "--------------------------Address Book -----------------------------------" << endl;
    cout << "---Search Address Book---" << endl;
    cout << "1.) First name" << endl;
    cout << "2.) Last name" << endl;
    cout << "3.) Address" << endl;
    cout << "4.) Contact " << endl;
    cout << "Enter Choice" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "ENter first name";
        cin >> Fname;
        cout << endl;
        break;
    case 2:
        cout << "Enter Last Name: ";
        cin >> Lname;
        cout << endl;
        break;
    case 3:
        cout << "Enter Address: ";
        cin >> Address;
        cout << endl;
        break;
    case 4:
        cout << "Enter Contact: ";
        cin >> Contact;
        cout << endl;
        break;

    default:
        cout << "Please Enter choice from 1 to 4";
        break;
    }

    searchContacts();

    ifstream search("AddressBook.txt");

    if (choice == 1)
    {
        while (search >> counter >> Fname2 >> Lname2 >> Address >> Contact2)
        {
            if (Fname == Fname2)
            {
                cout << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl
                     << endl;
            }
        }
    }

    if (choice == 2)
    {
        while (search >> counter >> Fname2 >> Lname2 >> Address >> Contact2)
        {
            if (Lname == Lname2)
            {
                cout << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl
                     << endl;
            }
        }
    }
    if (choice == 3)
    {
        while (search >> counter >> Fname2 >> Lname2 >> Address2 >> Contact2)
        {
            if (Address == Address2)
            {
                cout << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl
                     << endl;
            }
        }
    }
    if (choice == 4)
    {
        while (search >> counter >> Fname2 >> Lname2 >> Address2 >> Contact2)
        {
            if (Contact == Contact2)
            {
                cout << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl
                     << endl;
            }
        }
    }
    system("pause");
    system("cls");
}

// -----------------------------edit contacts----------------------------------------------------
void editContacts()
{
    system("cls");
    int choice;

    double counter, number;

    string Fname, Lname, Address, Contact, Fname2, Lname2, Address2, Contact2, choice2, choice3;

    ifstream edit("AddressBook.txt");

    ofstream temp("Temp.txt", ios::app);

    cout << "PLease type the entry that you wish to edit ";

    cin >> choice;
    cout << endl;

    if (choice == 0 || choice > 100)
    {

        cout << "Error , Wrong Entry ";
        system("pause>0");
        editContacts();
    }
    while (edit >> counter >> Fname2 >> Lname2 >> Address2 >> Contact2)
    {
        cout << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl
             << endl;
        cout << "Is this the contact that you wish to edit? (y or n) ";
        cin >> choice3;
        cout << endl;
    }

    if (choice3 == "n")
    {
        main();
    }
    if (choice3 == "y")
    {
        if (counter < choice)
        {
            temp << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl;
        }
        if (counter == choice)
        {
            cout << "Enter New First name: ";
            cin >> Fname;
            cout << "Enter New Last name: ";
            cin >> Lname;
            cout << "Enter New Address: ";
            cin >> Address;
            cout << "Enter new Contact";

            temp << choice << " " << Fname << " " << Lname << " " << Address << " " << Contact << endl;
        }

        if (counter > choice)
        {
            temp << counter << " " << Fname2 << " " << Lname2 << " "
                 << Address2 << " " << Contact2 << endl;
        }
    }

    edit.close();
    temp.close();

    if (remove("AddressBook.txt") == 0)
    {
        cout << "SuccessFully removing  files " << endl;
    }
    else
    {
        cout << " Error Removing ";
    }

    if (rename("Temp.txt", "AddressBook.txt") == 0)
    {
        cout << "Successfully renaming files ";
    }
    else
    {
        cout << " Error remaining" << endl;
    }

    system("pause");
    system("cls");

    // ---------------------------------------
}

void deleteContacts()
{
    system("cls");
    int choice;
    double counter, number;
    string Fname, Lname, Address, Contact, Fname2, Lname2, Address2, Contact2, choice2, choice3;
    ifstream edit("AddressBook.txt");
    ofstream temp("Temp.txt", ios::app);
    cout << "Please type the Entry number that you wish to delete: ";
    cin >> choice;
    cout << endl;

    while (edit >> counter >> Fname2 >> Lname2 >> Address2 >> Contact2)
    {
        if (counter == choice)
        {
            cout << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl
                 << endl;
            cout << "Is this the contact that you wish to delete? (y or n) ";
            cin >> choice;
            cout << endl;
        }
        if (choice3 == "n")
        {
            main();
        }
        if (counter < choice)
        {
            temp << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl;
        }
        if (counter > choice)
        {
            temp << counter - 1 << " " << Fname << " " << Lname << " " << Address2 << " " << Contact2 << endl;
        }
    }

    edit.close();
    temp.close();

    if (remove("AddressBook.txt") == 0)
    {
        cout << "Successfully removing files ";
    }
    else
    {
        cout << " Error Removing";
    }

    if (rename("temp.txt", "AddressBook.txt") == 0)
    {
        cout << " Successfully Renaming Files ";
    }
    else
    {
        cout << "Error is remaining  ";
    }
    system("pause");
    system("cls");
}
