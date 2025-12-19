#include <Phonebook.hpp>

static bool is_ascii_printable(const std::string &s)
{
    if (s.empty())
        return false;

    for (size_t i = 0; i < s.size(); ++i)
    {
        unsigned char c = static_cast<unsigned char>(s[i]);
        if (c < 32 || c > 126)
            return false;
    }
    return true;
}

static std::string prompt_ascii_field(const std::string &label, const std::string &field_name)
{
    std::string input;

    while (!std::cin.eof())
    {
        std::cout << label;
        std::getline(std::cin, input);

        if (input.empty())
        {
            std::cout << "Error: " << field_name << " cannot be empty." << std::endl;
            continue;
        }
        if (!is_ascii_printable(input))
        {
            std::cout << "Error: " << field_name
                      << " must contain only printable ASCII characters (no accents/Ñ/UTF-8)."
                      << std::endl;
            continue;
        }
        return input;
    }
    return "";
}

static std::string prompt_non_empty_field(const std::string &label, const std::string &field_name)
{
    std::string input;

    while (!std::cin.eof())
    {
        std::cout << label;
        std::getline(std::cin, input);

        if (input.empty())
        {
            std::cout << "Error: " << field_name << " cannot be empty." << std::endl;
            continue;
        }
        return input;
    }
    return "";
}

static std::string format_col_10(const std::string &s)
{
    if (s.size() > 10)
        return s.substr(0, 9) + ".";
    return s;
}
// =================================================================

Phonebook::Phonebook(void)
{
    this->_index = 0;
    std::cout << "Welcome to worst Phonebook! Created an empty phonebook for up to 8 contacts" << std::endl;
}

Phonebook::~Phonebook(void)
{
    std::cout << "See you soon!" << std::endl;
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

    std::cout << " ___________________________________________ " << std::endl;
    std::cout << "|" << std::setw(10) << std::right << "Index"
              << "|" << std::setw(10) << std::right << "First Name"
              << "|" << std::setw(10) << std::right << "Last Name"
              << "|" << std::setw(10) << std::right << "Nickname"
              << "|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    i = 0;
    while (i < 8 && contact[i].get_fname().size())
    {
        std::cout << "|" << std::setw(10) << std::right << format_col_10(std::to_string(i + 1));
        std::cout << "|" << std::setw(10) << std::right << format_col_10(contact[i].get_fname());
        std::cout << "|" << std::setw(10) << std::right << format_col_10(contact[i].get_lname());
        std::cout << "|" << std::setw(10) << std::right << format_col_10(contact[i].get_nickname());
        std::cout << "|" << std::endl;
        ++i;
    }

    std::cout << " ------------------------------------------- " << std::endl;
}

void Phonebook::add(void)
{
    std::string str;

    if (this->_index > 7)
        std::cout << "Warning: overwriting info about " << this->_contacts[this->_index % 8].get_fname() << std::endl;

    // Strict ASCII printable for name fields:
    str = prompt_ascii_field("Enter first name: ", "First name");
    if (std::cin.eof()) return;
    this->_contacts[this->_index % 8].set_fname(str);

    str = prompt_ascii_field("Enter last name: ", "Last name");
    if (std::cin.eof()) return;
    this->_contacts[this->_index % 8].set_lname(str);

    str = prompt_ascii_field("Enter nickname: ", "Nickname");
    if (std::cin.eof()) return;
    this->_contacts[this->_index % 8].set_nickname(str);

    // Phone number: non-empty + digits only (ASCII)
    while (!std::cin.eof())
    {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, str);

        if (str.empty())
        {
            std::cout << "Error: Phone number cannot be empty." << std::endl;
            continue;
        }

        bool is_num = true;
        for (size_t j = 0; j < str.length(); j++)
        {
            if (!std::isdigit(static_cast<unsigned char>(str[j])))
            {
                is_num = false;
                std::cout << "Error: Phone number must contain only digits." << std::endl;
                break;
            }
        }

        if (!is_num)
            continue;

        this->_contacts[this->_index % 8].set_phone_num(str);
        break;
    }

    // Darkest secret: non-empty (aquí NO restringo ASCII porque tú pediste solo nombres)
    str = prompt_non_empty_field("Enter darkest secret: ", "Darkest secret");
    if (std::cin.eof()) return;
    this->_contacts[this->_index % 8].set_secret(str);

    std::cout << this->_contacts[this->_index % 8].get_fname()
              << " successfully added to phonebook ["
              << this->_index % 8 + 1 << "/8]" << std::endl;

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
                if (!std::isdigit(static_cast<unsigned char>(str[j])))
                {
                    is_num = false;
                    std::cout << "Error: Input must be a number." << std::endl;
                    break;
                }
            }

            if (is_num)
            {
                try
                {
                    i = std::stoi(str) - 1;
                    if (i >= 0 && i <= 7 && this->_contacts[i].get_fname().size())
                        Phonebook::print(this->_contacts[i]);
                    else
                        std::cout << "Invalid index!" << std::endl;
                }
                catch (const std::exception &e)
                {
                    std::cout << "Error: Input is not a valid number." << std::endl;
                }
            }
        }
    }
}

Contact Phonebook::get_contact(int index)
{
    return (this->_contacts[index % 8]);
}
