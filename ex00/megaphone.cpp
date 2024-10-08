#include <iostream>

int main(int ac, char **av)
{
    int i;
    int j;

    i = 0;
    j = 1;

    if(ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (av[j])
        {
            while (av[j][i])
            {
                std::cout << (char)std::toupper(av[j][i]);
                i++;
            }
            i = 0;
            j++;
        }
        std::cout << std::endl;
    }
    return 0;
}
