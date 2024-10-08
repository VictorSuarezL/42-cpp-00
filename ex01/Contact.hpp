#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
    std::string _fname;
    std::string _lname;
    std::string _nickname;
    std::string _phone_num;
    std::string _secret;

public:
    // Constructor:
    Contact(void);

    // Destructor:
    ~Contact(void);

    // Getters:
    std::string get_fname(void) const;
    std::string get_lname(void) const;
    std::string get_nickname(void) const;
    std::string get_phone_num(void) const;
    std::string get_secret(void) const;

    // Setters:
    void set_fname(std::string str);
    void set_lname(std::string str);
    void set_nickname(std::string str);
    void set_phone_num(std::string str);
    void set_secret(std::string str);
};

#endif