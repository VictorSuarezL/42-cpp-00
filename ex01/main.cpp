#include <Phonebook.hpp>

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
