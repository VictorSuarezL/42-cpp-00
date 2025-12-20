#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    int i = 0;
    int j = 1;

    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        while (av[j])
        {
            i = 0;
            while (av[j][i])
            {
                unsigned char c = static_cast<unsigned char>(av[j][i]);

                if (std::isprint(c))
                    std::cout << static_cast<char>(std::toupper(c));

                i++;
            }
            j++;
        }
        std::cout << std::endl;
    }
    return 0;
}
