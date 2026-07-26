#include "PhoneBook.hpp"
#include <iostream>


PhoneBook::PhoneBook()
{
    nextIndex = 0;
    contactCount = 0;
}

int PhoneBook::getContactsCount()
{
    return contactCount;
}

std::string processString(const std::string& str)
{
    if(str.length() <= 10)
        return str;
    
    return (str.substr(0, 9) + ".");
}

void PhoneBook::PrintAllContacts() const
{
    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last Name" << "|";
    std::cout << std::setw(10) << "nickname" << std::endl;

    for(int i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << processString(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << processString(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << processString(contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::PrintContact(int index) const
{
    std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].getdarkeSecret() << std::endl;
}

void PhoneBook::AddContact(const Contact& contact)
{
    contacts[nextIndex] = contact;
    
    if (contactCount != 8)
        contactCount++;

    nextIndex = (nextIndex + 1) % 8;
}