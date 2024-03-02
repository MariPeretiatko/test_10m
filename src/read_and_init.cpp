#include "../statistics.h"

bool readDataFromFile(const std::string &filename, std::vector<long long> &numbers)
{
    long long number;

    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "\n\e[1;31mError with file\n\e[0m";
        std::cerr << "Failed to open the file.\n";
        return false;
    }
    while (file >> number)
    {
        numbers.push_back(number);
    }

    file.close();
    return true;
}

std::string initFilename(int ac, char *av[])
{
    std::string filename;
    if (ac == 1)
        filename = "10m.txt";
    else if (ac == 2)
        filename = av[1];
    else
    {
        filename = "";
        std::cout << "\n\e[1;31mError with parameters\n\e[0m";
        std::cout << "The program takes one parameter and this is the name\n";
        std::cout << "of the file from which you want to read numbers for further work.\n";
        std::cout << "You can also run the program without parameters, then the program\n";
        std::cout << "with the default file will be executed.\n\n";
    }
    return (filename);
}
