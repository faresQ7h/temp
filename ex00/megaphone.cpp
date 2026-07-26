#include <iostream>

std::string convertToUpperString(char *arg)
{
    std::string str;

    for (int i = 0; arg[i]; i++)
        str += std::toupper(arg[i]);

    return str;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    int i = 1;
    while (i < argc)
    {
        std::cout << convertToUpperString(argv[i]);
        if (i + 1 == argc)
            std::cout << std::endl;
        i++;
    }

    return 0;
}