#ifndef CONTACTS_MANAGER_H_
#define CONTACTS_MANAGER_H_

using namespace std;

#include "array.h"
#include "contact.h"
#include <iostream>

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

    Contact search_contact(const string &name) const
    {
        for (int i = 0; i < contacts.getSize(); i++)
        {
            Contact contact = get_contact(i);
            // if (contact.get_name() == name)
            return contact;
        }

        throw std::runtime_error("Contact: `" + name + "` not found: "); // Should really throw an error?
    }
};

#endif // CONTACTS_MANAGER_H_