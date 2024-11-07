#ifndef CONTACTS_MANAGER_H_
#define CONTACTS_MANAGER_H_

using namespace std;

#include "array.h"
#include "contact.h"
#include <iostream>
#include <fstream>

string CONTACT_SEPERATOR = "-----------------------------";

class ContactsManager
{
private:
    Array<Contact> contacts;

    Contact get_contact(int index) const
    {
        return contacts.get(index);
    }

public:
    ContactsManager() {}

    void add_contact()
    {
        Contact contact = Contact::read_contact();
        contacts.push(contact);
    }
    void search_by_last_name() const
    {
        cout << "Enter last name: ";
        string last_name;
        cin >> last_name;

        bool is_found = false;

        for (int i = 0; i < contacts.getSize() && !is_found; i++)
        {
            Contact contact = get_contact(i);
            if (contact.get_last_name() == last_name)
            {
                is_found = true;
                contact.print();
                cout << "-----------------------------" << endl;
            }
        }
    }
    void search_by_category() const
    {
        cout << "Enter category: ";
        string category;
        cin >> category;

        bool is_some_matched = false;

        for (int i = 0; i < contacts.getSize(); i++)
        {
            Contact contact = get_contact(i);
            if (contact.get_category() == category)
            {
                is_some_matched = true;
                contact.print();
                cout << "-----------------------------" << endl;
            }
        }

        if (!is_some_matched)
            cout << "No contacts found" << endl;
    }
    void print_contacts() const
    {
        for (int i = 0; i < contacts.getSize(); i++)
        {
            Contact contact = get_contact(i);
            contact.print();
            cout << "-----------------------------" << endl;
        }

        cout << "No contacts";
    }
    void print_fav_contacts() const
    {
        bool has_favourite = false;

        for (int i = 0; i < contacts.getSize(); i++)
        {
            Contact contact = get_contact(i);
            if (contact.get_is_favourite())
            {
                has_favourite = true;
                contact.print();
                cout << "-----------------------------" << endl;
            }
        }

        if (!has_favourite)
            cout << "No favourite contacts found" << endl;
    }
    void update_contact()
    {
        cout << "Enter index: ";
        int index;
        cin >> index;

        contacts.get(index).update();
    }

    void save_contacts() const
    {
        ofstream outFile("./contacts.txt", ios::trunc);

        if (outFile.is_open())
        {
            for (int i = 0; i < contacts.getSize(); i++)
            {
                Contact contact = get_contact(i);
                outFile << contact.to_string() << endl;
                outFile << CONTACT_SEPERATOR << endl;
            }
            outFile.close();
        }
    }

    void load_contacts()
    {
        // string first_name;
        // string last_name;
        // string phone_number;
        // string category;
        // bool is_favourite;
        // string mail;
        // Address address;

        string input = "";

        ifstream inFile("./contacts.txt");
        string line;
        if (inFile.is_open())
        {
            while (getline(inFile, line))
            {
                if (line == CONTACT_SEPERATOR)
                {
                    Contact contact = Contact(input);
                    contacts.push(contact);
                    input = "";
                }
                else
                    input += line + "\n";
            }
            inFile.close();
        }
    }
};
#endif // CONTACTS_MANAGER_H_