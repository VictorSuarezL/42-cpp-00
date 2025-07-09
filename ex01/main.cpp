#include <Phonebook.hpp>

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

// void Phonebook::add(void)
// {
//     std::string first_names[] = {"John", "Jane", "Alice", "Bob", "Charlie", "David", "Eve", "Frank"};
//     std::string last_names[] = {"Doe", "Smithadfadfafadfadfadf", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller"};
//     std::string nicknames[] = {"JD", "JS", "AJ", "BW", "CB", "DJ", "EG", "FM"};
//     std::string phone_numbers[] = {"123-456-7890", "234-567-8901", "345-678-9012", "456-789-0123", "567-890-1234", "678-901-2345", "789-012-3456", "890-123-4567"};
//     std::string secrets[] = {"Secret1", "Secret2", "Secret3", "Secret4", "Secret5", "Secret6", "Secret7", "Secret8"};

//     if (this->_index > 7)
//         std::cout << "Warning: overwriting info about " << this->_contacts[this->_index % 8].get_fname() << std::endl;

//     int idx = this->_index % 8;
//     this->_contacts[idx].set_fname(first_names[idx]);
//     this->_contacts[idx].set_lname(last_names[idx]);
//     this->_contacts[idx].set_nickname(nicknames[idx]);
//     this->_contacts[idx].set_phone_num(phone_numbers[idx]);
//     this->_contacts[idx].set_secret(secrets[idx]);

//     std::cout << first_names[idx] << " successfully added to phonebook [" << idx + 1 << "/8]" << std::endl;

//     this->_index++;
// }

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

int main(void)
{
    Phonebook phoneb;
    std::string str;

    while (str != "EXIT")
    {
        std::cout << "Enter a command > ";
        std::getline(std::cin, str);
        if (str == "ADD")
        {
            phoneb.add();
        }
        else if (str == "SEARCH")
        {
            std::cout << "Hello!" << std::endl;
            phoneb.search();
        }
        if (std::cin.eof())
        {
            std::cout << std::endl;
            return 0;
        }
    }
    return 0;
}
