#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "../../domains/domains.h"

///
/// This class stores all the information of the participants of the play.
/// Types of information:
/// - Registration
/// - First name
/// - Last name
/// - Email
/// - Phone number
/// - Password
/// - Role
///

class Participant
{
private:
    Registration _registration;
    Name _firstName;
    Name _lastName;
    Email _email;
    PhoneNumber _phoneNumber;
    Password _password;
    Role _role;

public:
    ///
    /// Calls all the methods set for the objects of the attributes of class Participant, if its objects is already created.
    /// @param registration
    /// @param firstName
    /// @param lastName
    /// @param email
    /// @param phoneNumber
    /// @param password
    /// @param role
    ///

    Participant(const Registration &registration, const Name &firstName, const Name &lastName,
                const Email &email, const PhoneNumber &phoneNumber, const Password &password, const Role &role)
    {
        setRegistration(registration);
        setFirstName(firstName);
        setLastName(lastName);
        setEmail(email);
        setPhoneNumber(phoneNumber);
        setPassword(password);
        setRole(role);
    }

    ///
    /// Calls all the methods set for the objects of the attributes of class Participant.
    /// @param registration
    /// @param firstName
    /// @param lastName
    /// @param email
    /// @param phoneNumber
    /// @param password
    /// @param role
    ///

    Participant(const std::string &registration, const std::string &firstName, const std::string &lastName,
                const std::string &email, const std::string &phoneNumber, const std::string &password, const std::string &role)
    {
        setRegistration(registration);
        setFirstName(firstName);
        setLastName(lastName);
        setEmail(email);
        setPhoneNumber(phoneNumber);
        setPassword(password);
        setRole(role);
    }

    ///
    /// Creates an instance of the class Participant.
    ///

    Participant() {}

    ///
    /// Stores an already created object of class Registration.
    /// @param registration
    ///

    void setRegistration(Registration registration)
    {
        _registration = registration;
    }

    ///
    /// Creates and stores the object of the class registration.
    /// @param registration
    ///

    void setRegistration(std::string registration)
    {
        _registration = Registration(registration);
    }

    ///
    /// Returns the stored object of the class Registration.
    /// @return _registration
    ///

    Registration getRegistration()
    {
        return _registration;
    }

    ///
    /// Stores an already created object of class Name, and sets it as first name.
    /// @param name
    ///

    void setFirstName(Name name)
    {
        _firstName = name;
    }

    ///
    /// Creates and stores the object of the class Name, and sets it as first name.
    /// @param name
    ///

    void setFirstName(std::string name)
    {
        _firstName = Name(name);
    }

    ///
    /// Returns the stored object first name of the class Name.
    /// @return _firstName
    ///

    Name getFirstName()
    {
        return _firstName;
    }

    ///
    /// Stores an already created object of class Name, and sets it as last name.
    /// @param name
    ///

    void setLastName(Name name)
    {
        _lastName = name;
    }

    ///
    /// Creates and stores the object of the class Name, and sets it as last name.
    /// @param name
    ///

    void setLastName(std::string name)
    {
        _lastName = Name(name);
    }

    ///
    /// Returns the stored object last name of the class Name.
    /// @return _lastName
    ///

    Name getLastName()
    {
        return _lastName;
    }

    ///
    /// Returns full name object made of the stored objects _firstName and _lastName.
    /// @return _firstName.get() + " " + _lastName.get()
    ///

    Name getFullName()
    {
        return _firstName.get() + " " + _lastName.get();
    }

    ///
    /// Stores an already created object of class Email.
    /// @param email
    ///

    void setEmail(Email email)
    {
        _email = email;
    }

    ///
    /// Creates and stores the object of the class Email.
    /// @param email
    ///

    void setEmail(std::string email)
    {
        _email = Email(email);
    }

    ///
    /// Returns the stored object of the class Email.
    /// @return _email
    ///

    Email getEmail()
    {
        return _email;
    }

    ///
    /// Stores an already created object of class PhoneNumber.
    /// @param phoneNumber
    ///

    void setPhoneNumber(PhoneNumber phoneNumber)
    {
        _phoneNumber = phoneNumber;
    }

    ///
    /// Creates and stores the object of the class PhoneNumber.
    /// @param phoneNumber
    ///

    void setPhoneNumber(std::string phoneNumber)
    {
        _phoneNumber = PhoneNumber(phoneNumber);
    }

    ///
    /// Returns the stored object of the class PhoneNumber.
    /// @return _phoneNumber
    ///

    PhoneNumber getPhoneNumber()
    {
        return _phoneNumber;
    }

    ///
    /// Stores an already created object of class Password.
    /// @param password
    ///

    void setPassword(Password password)
    {
        _password = password;
    }

    ///
    /// Creates and stores the object of the class Password.
    /// @param password
    ///

    void setPassword(std::string password)
    {
        _password = Password(password);
    }

    ///
    /// Returns the stored object of the class Password.
    /// @return _password
    ///

    Password getPassword()
    {
        return _password;
    }

    ///
    /// Stores an already created object of class Role.
    /// @param role
    ///

    void setRole(Role role)
    {
        _role = role;
    }

    ///
    /// Creates and stores the object of the class Role.
    /// @param role
    ///

    void setRole(std::string role)
    {
        _role = Role(role);
    }

    ///
    /// Returns the stored object of the class Role.
    /// @return _role
    ///

    Role getRole()
    {
        return _role;
    }
};

#endif