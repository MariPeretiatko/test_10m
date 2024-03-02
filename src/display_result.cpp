#include "../statistics.h"

void printElements(std::vector<long long> &numbers)
{
    for (long unsigned int i = 0; i < numbers.size(); i++)
        std::cout << "[" << i << "] - " << numbers[i] << std::endl;
    std::cout << "\n";
}

void printInfo(std::vector<long long> &numbers, int size)
{
    int max = maxElement(numbers);
    std::cout << "\nMAX = " << max << std::endl;
    int min = minElement(numbers);
    std::cout << "\nMIN = " << min << std::endl;
    float median = medianFind(numbers, size);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << "\nMedian = " << median << std::endl;
    double average = averageFind(numbers, size);
    std::cout << "\nAverage = " << average << std::endl;
    std::vector<long long> sequence_increase = sequenceIncrease(numbers, size);
	std::cout << "\nSequence_increase" << std::endl;
    printElements(sequence_increase);
    std::vector<long long> sequence_decrease = sequenceDecrease(numbers, size);
	std::cout << "\nSequence_decrease" << std::endl;
    printElements(sequence_decrease);
}

void menu(std::vector<long long> &numbers)
{
    int max = maxElement(numbers);
    int min = minElement(numbers);
    long long size = numbers.size();
    long long median = medianFind(numbers, size);
    // double sum_of_elems = sumAllElements(numbers, size);
    double average = averageFind(numbers, size);
    std::vector<long long> tmp = sequenceIncrease(numbers, size);
    std::vector<long long> tmp1 = sequenceDecrease(numbers, size);
    int option;
    while (1)
    {
        system("cls");
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Menu\n";
        std::cout << "[1] - Max\n";
        std::cout << "[2] - Min\n";
        std::cout << "[3] - Median\n";
        std::cout << "[4] - Average\n";
        std::cout << "[5] - The largest sequence of numbers that increases\n";
        std::cout << "[6] - The largest decreasing sequence of numbers\n";
        std::cout << "[0] - Exit\n";

        std::cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            std::cout << "\033[2J\033[1;1H";
            std::cout << "MAX = " << max << std::endl;
            sleep(2);
            break;
        case 2:
            system("cls");
            std::cout << "\033[2J\033[1;1H";
            std::cout << "MIN = " << min << std::endl;
            sleep(2);
            break;
        case 3:
            system("cls");
            std::cout << "\033[2J\033[1;1H";
            std::cout << "Median = " << median << std::endl;
            sleep(2);
            break;
        case 4:
            system("cls");
            std::cout << "\033[2J\033[1;1H";
            std::cout << "Average = " << average << std::endl;
            sleep(2);
            break;
        case 5:
            system("cls");
            std::cout << "\033[2J\033[1;1H";
            std::cout << "Sequence Increase\n"
                      << std::endl;
            printElements(tmp);
            sleep(5);
            break;
        case 6:
            system("cls");
            std::cout << "\033[2J\033[1;1H";
            std::cout << "Sequence Decrease\n"
                      << std::endl;
            printElements(tmp1);
            sleep(5);
            break;
        case 0:
            exit(0);
            break;
        default:
            system("cls");
            std::cout << "\033[2J\033[1;1H";
            std::cout << "Try again\n";
            sleep(1);
            break;
        }
    }
}
