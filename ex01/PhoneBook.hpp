#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook 
{
    private:
        int nextIndex;
        int contactCount;
        Contact contacts[8];

    public:
        PhoneBook();
        int getContactsCount();
        void PrintAllContacts() const;
        void PrintContact(int index) const;
        void AddContact(const Contact& contact);
};

#endif