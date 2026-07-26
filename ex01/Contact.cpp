#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(
    std::string first,
    std::string last,
    std::string nick,
    std::string phone,
    std::string secret)
{
    firstName = first;
    lastName = last;
    nickname = nick;
    phoneNumber = phone;
    darkestSecret = secret;
}

std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickname() const
{
    return nickname;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Contact::getdarkeSecret() const
{
    return darkestSecret;
}
