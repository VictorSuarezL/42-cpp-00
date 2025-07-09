#include <Phonebook.hpp>

Phonebook::Phonebook(void)
{
    this->_index = 0;
    std::cout << "Welcome to worst Phonebook! Created an empty phonebook for up to 8 contacts" << std::endl;
}

Phonebook::~Phonebook(void)
{
    std::cout << "See you soon!" << std::endl;
}

void Phonebook::_calculate_padding(std::string &str)
{
    if (str.size() > 10)
        str = str.substr(0, 9) + ".";
    else
    {
        while (str.size() < 10)
            str = " " + str;
    }
}

void Phonebook::_print_ui(Contact contact[8])
{
    int i;
    std::string str;

    std::cout << " ___________________________________________ " << std::endl;
    std::cout << "|        Id|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    i = -1;
    while (++i < 8 && contact[i].get_fname().size())
    {
        if (contact[i].get_fname().size())
        {
            str = std::to_string(i + 1);
            _calculate_padding(str);
            std::cout << "|" << str << "|";
            str = contact[i].get_fname();
            _calculate_padding(str);
            std::cout << str << "|";
            str = contact[i].get_lname();
            _calculate_padding(str);
            std::cout << str << "|";
            str = contact[i].get_nickname();
            _calculate_padding(str);
            std::cout << str << "|" << std::endl;
        }
    }
    std::cout << " ------------------------------------------- " << std::endl;
}

// void Phonebook::add(void)
// {
//     std::string str;

//     str = "";
//     while (!std::cin.eof() && str == "")
//     {
//         std::cout << "Enter first name: ";
//         if (std::getline(std::cin, str) && str != "")
//         {
//             this->_contacts[this->_index % 8].set_fname(str);
//         }
//     }
//     str = "";
//     while (!std::cin.eof() && str == "")
//     {
//         std::cout << "Enter " << this->_contacts[this->_index % 8].get_fname() << "'s last name: ";
//         if (std::getline(std::cin, str) && str != "")
//         {
//             this->_contacts[this->_index % 8].set_lname(str);
//         }
//     }
//     str = "";
//     while (!std::cin.eof() && str == "")
//     {
//         std::cout << "Enter " << this->_contacts[this->_index % 8].get_fname() << "'s nickname: ";
//         if (std::getline(std::cin, str) && str != "")
//         {
//             this->_contacts[this->_index % 8].set_nickname(str);
//         }
//     }
//     str = "";
//     while (!std::cin.eof() && str == "")
//     {
//         std::cout << "Enter " << this->_contacts[this->_index % 8].get_fname() << "'s phone number: ";
//         if (std::getline(std::cin, str) && str != "")
//         {
//             this->_contacts[this->_index % 8].set_phone_num(str);
//         }
//     }
//     str = "";
//     while (!std::cin.eof() && str == "")
//     {
//         std::cout << "Enter " << this->_contacts[this->_index % 8].get_fname() << "secret: ";
//         if (std::getline(std::cin, str) && str != "")
//         {
//             this->_contacts[this->_index % 8].set_secret(str);
//             std::cout << this->_contacts[this->_index % 8].get_fname() << " successfully added to phonebook [" << this->_index % 8 + 1 << "/8]" << std::endl;
//         }
//     }
//     this->_index++;
// }



// void Phonebook::print(Contact contact)
// {
//     std::cout << "Requesting contact information" << std::endl;
//     std::cout << contact.get_fname().size() << std::endl;
// }

// int search_ui(Contact contacts[8])
// {
//     // char c;
//     int i;
//     std::string str;

//     std::cout << " ___________________________________________ " << std::endl;
//     std::cout << "|        Id|First Name| Last Name|  Nickname|" << std::endl;
//     std::cout << "|----------|----------|----------|----------|" << std::endl;
//     i = '0';
//     while (i <= '8')
//     {
//         str = i;
//         if (contacts[i].get_fname().size())
//         {
//             std::cout << "|" << str << "|";
//             str = contacts[i].get_fname();
//             std::cout << "|" << str << "|";
//         }
//     }
//     std::cout << " ------------------------------------------- " << std::endl;
//     return i;
// }


