#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

std::string ReadField(const std::string& prompt)
{
    std::string input;

    do
    {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (input.empty())
            std::cout << "Field cannot be empty." << std::endl;

    } while (input.empty());

    return input;
}

Contact ReadNewContact()
{
    std::string first = ReadField("First name: ");
    std::string last = ReadField("Last name: ");
    std::string nickname = ReadField("Nickname: ");
    std::string phone = ReadField("Phone number: ");
    std::string secret = ReadField("Darkest secret: ");

    return Contact(first, last, nickname, phone, secret);
}

int main()
{
    std::string cmd;
    PhoneBook phoneBook;

    while(true)
    {
        std::cout << "> ";
        std::getline(std::cin, cmd);

        if (cmd == "ADD")
        {
            phoneBook.AddContact(ReadNewContact());
        }
        else if (cmd == "SEARCH")
        {
            if (phoneBook.getContactsCount() == 0)
            {
                std::cout << "PhoneBook is empty." << std::endl;
            }
            else
            {
                phoneBook.PrintAllContacts();

                int index;
                std::string input;

                while (true)
                {
                    input = ReadField("Enter index: ");

                    std::stringstream ss(input);

                    if ((ss >> index) &&
                        (ss >> std::ws).eof() &&
                        index >= 0 &&
                        index < phoneBook.getContactsCount())
                    {
                        break;
                    }

                    std::cout << "Invalid index." << std::endl;
                }

                phoneBook.PrintContact(index);
            }
        }
        else if(cmd == "EXIT")
        {
            return 0;
        }
    }
}