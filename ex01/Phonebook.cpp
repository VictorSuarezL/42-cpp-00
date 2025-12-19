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
    str = col10(str);
}

void Phonebook::print(Contact contact)
{
    std::cout << "Requesting information..." << std::endl;
    if (!contact.get_fname().size())
    {
        std::cout << "Failed to get info from contact" << std::endl;
        return;
    }
    std::cout << "First Name: " << contact.get_fname() << std::endl;
    std::cout << "Last Name: " << contact.get_lname() << std::endl;
    std::cout << "Nickname: " << contact.get_nickname() << std::endl;
    std::cout << "Phone Number: " << contact.get_phone_num() << std::endl;
    std::cout << "Darkest Secret: " << contact.get_secret() << std::endl;
}

void Phonebook::_print_ui(Contact contact[8])
{
    int i;
    std::string str;

    std::cout << " ___________________________________________ " << std::endl;
    std::cout << "|" << std::setw(10) << std::right << "Index"
              << "|" << std::setw(10) << std::right << "First Name"
              << "|" << std::setw(10) << std::right << "Last Name"
              << "|" << std::setw(10) << std::right << "Nickname"
              << "|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    i = -1;
    while (++i < 8 && contact[i].get_fname().size())
    {
        if (contact[i].get_fname().size())
        {
            str = std::to_string(i + 1);
            _calculate_padding(str);
            std::cout << "|" << str;
            str = contact[i].get_fname();
            _calculate_padding(str);
            std::cout << "|" << str;
            str = contact[i].get_lname();
            _calculate_padding(str);
            std::cout << "|" << str;
            str = contact[i].get_nickname();
            _calculate_padding(str);
            std::cout << "|" << str << "|" << std::endl;
        }
    }
    std::cout << " ------------------------------------------- " << std::endl;
}

void Phonebook::add(void)
{
    std::string str;

    if (this->_index > 7)
        std::cout << "Warning: overwriting info about " << this->_contacts[this->_index % 8].get_fname() << std::endl;

    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter first name: ";
        if (std::getline(std::cin, str) && str != "")
        {
            this->_contacts[this->_index % 8].set_fname(str);
        }
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter last name: ";
        if (std::getline(std::cin, str) && str != "")
        {
            this->_contacts[this->_index % 8].set_lname(str);
        }
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter nickname: ";
        if (std::getline(std::cin, str) && str != "")
        {
            this->_contacts[this->_index % 8].set_nickname(str);
        }
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter phone number: ";
        if (std::getline(std::cin, str) && str != "")
        {
            bool is_num = true;
            for (size_t j = 0; j < str.length(); j++)
            {
                if (!std::isdigit(str[j]))
                {
                    is_num = false;
                    printf("Character '%c' is not a digit.\n", str[j]);
                    break;
                }
            }
            if (!is_num)
            {
                std::cout << "Error: Phone number must contain only digits." << std::endl;
                str = "";
            }
            else
                this->_contacts[this->_index % 8].set_phone_num(str);
        }
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter darkest secret: ";
        if (std::getline(std::cin, str) && str != "")
        {
            this->_contacts[this->_index % 8].set_secret(str);
            std::cout << this->_contacts[this->_index % 8].get_fname() << " successfully added to phonebook [" << this->_index % 8 + 1 << "/8]" << std::endl;
        }
    }
    this->_index++;
}

void Phonebook::search()
{
    std::string str;
    int i = 0;

    _print_ui(this->_contacts);

    while (!std::cin.eof())
    {
        std::cout << "Select and index: ";
        if (std::getline(std::cin, str) && str != "")
        {
            bool is_num = true;
            for (size_t j = 0; j < str.length(); j++)
            {
                if (!std::isdigit(str[j]))
                {
                    is_num = false;
                    printf("Character '%c' is not a digit.\n", str[j]);
                    break;
                }
            }

            if (is_num)
            {
                try
                {
                    i = std::stoi(str) - 1;
                    if (i >= 0 && i <= 7 && this->_contacts[i].get_fname().size())
                    {
                        Phonebook::print(this->_contacts[i]);
                    }
                    else
                    {
                        std::cout << "Invalid index!" << std::endl;
                    }
                }
                catch (const std::exception &e)
                {
                    std::cout << "Error: Input is not a valid number." << std::endl;
                }
            }
            else
            {
                std::cout << "Error: Input must be a number." << std::endl;
            }
        }
    }
}

Contact Phonebook::get_contact(int index)
{
    return (this->_contacts[index % 8]);
}
