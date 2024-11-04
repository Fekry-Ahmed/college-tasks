#include <iostream>
#include "contacts_manager.h"
#include "utils.h"
#include <vector>

class Application
{
public:
    void run()
    {
        cout << "Welcome to Contacts app\n";

        vector<string> menu;
        menu.push_back("New contact");              // 1
        menu.push_back("Search by last name");      // 2
        menu.push_back("Search by category");       // 3
        menu.push_back("Print all contacts");       // 4
        menu.push_back("Print favourite contacts"); // 5
        menu.push_back("Save to file");             // 6
        menu.push_back("Load from file");           // 7
        menu.push_back("Delete a contact");         // 8
        menu.push_back("Update contacts");          // 9
        menu.push_back("Share contact with other"); // 10
        menu.push_back("Reverse contacts book");    // 11
        menu.push_back("Exit");                     // 12

        ContactsManager contacts_manager;

        while (true)
        {
            int choice = show_read_menu(menu, "Menu");

            if (choice == 1)
                contacts_manager.add_contact();
            else if (choice == 2)
                contacts_manager.search_by_last_name();
            else if (choice == 3)
                contacts_manager.search_by_category();
            else if (choice == 4)
                contacts_manager.print_contacts();
            else if (choice == 5)
                contacts_manager.print_fav_contacts();
            else if (choice == 6)
                cout << "contacts_manager.save_contacts();";
            else if (choice == 7)
                cout << "contacts_manager.load_contacts();";
            else if (choice == 8)
                cout << "Delete a contact";
            else if (choice == 9)
                contacts_manager.update_contact();
            else if (choice == 10)
                cout << "Not implemented";
            else if (choice == 11)
                cout << "Reverse contacts book";
            else
                break;
        }
    }
};

int main()
{
    Application app;
    app.run();

    return 0;
}
