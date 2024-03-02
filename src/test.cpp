#include "../statistics.h"

int main(int ac, char *av[])
{
    clock_t start = clock();

    const std::string filename = initFilename(ac, av);

    std::vector<long long> numbers;
    readDataFromFile(filename, numbers);
    int size = numbers.size();
    if (size == 0)
	{
		std::cout << "\n\e[1;31mProblems with file contents\n\n\e[0m";
        return (0);
	}

    // menu(numbers);
    printInfo(numbers, size);

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Program execution time:" << duration << " sec" << std::endl;
    return 0;
}