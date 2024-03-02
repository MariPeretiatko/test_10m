#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <numeric>
#include <unistd.h>
// using namespace std;
// using std::cout;

// g++ test.cpp -o test -lstdc++

bool readDataFromFile(const std::string &filename, std::vector<long long> &numbers)
{
    long long number;

    std::ifstream file(filename);
    if (!file.is_open())
    {
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

long long minElement(std::vector<long long> &numbers)
{
    return (*std::min_element(numbers.begin(), numbers.end()));
}

long long maxElement(std::vector<long long> &numbers)
{
    return (*std::max_element(numbers.begin(), numbers.end()));
}

double sumAllElements(std::vector<long long> &numbers, int size)
{
    double sumOfElems;
    for (int i = 0; i < size; i++)
        sumOfElems += numbers[i];
    return (sumOfElems);
}

double sumAllElements1(std::vector<long long> &numbers)
{
    double sumOfElems;
    std::for_each(numbers.begin(), numbers.end(), [&](long long n)
                  { sumOfElems += n; });
    return (sumOfElems);
}

float medianFind(std::vector<long long> &numbers, int size)
{
    float median;
    int median_idx = size / 2;

    if (size % 2 == 0)
        median = (numbers[median_idx] + numbers[median_idx - 1]) * 0.5;
    else
        median = numbers[median_idx];
    return (median);
}

double averageFind(std::vector<long long> &numbers, int size)
{
    return (sumAllElements(numbers, size) / size);
}

int findLongestSequence(std::vector<long long> &numbers, int size, bool increase, int *last_index)
{
    int count_sequence = 1;
    int final_sequence = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if ((increase && numbers[i] < numbers[i + 1]) || (!increase && numbers[i] > numbers[i + 1]))
            count_sequence++;
        else
        {
            if (count_sequence > final_sequence)
            {
                final_sequence = count_sequence;
                *last_index = i;
            }
            count_sequence = 1;
        }
    }
    return (final_sequence);
}

std::vector<long long> &initNewSequence(std::vector<long long> &sequence, std::vector<long long> &numbers, int size, int index)
{
    for (int i = 0; i < size; i++)
        sequence.push_back(numbers[index--]);
    std::reverse(sequence.begin(), sequence.end());
    return (sequence);
}

std::vector<long long> sequenceIncrease(std::vector<long long> &numbers, int size)
{
    std::vector<long long> sequence_increase;
    int last_index = 0;
    int count_sequence = findLongestSequence(numbers, size, true, &last_index);
    sequence_increase = initNewSequence(sequence_increase, numbers, count_sequence, last_index);
    return (sequence_increase);
}

std::vector<long long> sequenceDecrease(std::vector<long long> &numbers, int size)
{
    std::vector<long long> sequens_decrease;
    int last_index = 0;
    int count_sequence = findLongestSequence(numbers, size, false, &last_index);
    sequens_decrease = initNewSequence(sequens_decrease, numbers, count_sequence, last_index);
    return (sequens_decrease);
}
void printElements(std::vector<long long> &numbers)
{
    for (int i = 0; i < numbers.size(); i++)
        std::cout << "[" << i << "] - " << numbers[i] << std::endl;
    std::cout << "\n";
}

void menu(std::vector<long long> &numbers)
{
    int max = maxElement(numbers);
    int min = minElement(numbers);
    long long size = numbers.size();
    long long median = medianFind(numbers, size);
    double sum_of_elems = sumAllElements(numbers, size);
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

int main(int ac, char *av[])
{
    std::string filename;
    if (ac == 1)
    {
        filename = "10m.txt";
        std::cout << filename << std::endl;
    }
    else if (ac == 2)
    {
        filename = av[1];
        std::cout << filename << std::endl;
    }
    else
    {
        std::cout << "\n\e[1;31mError with parameters\n\e[0m";
        std::cout << "The program takes one parameter and this is the name\n";
        std::cout << "of the file from which you want to read numbers for further work.\n";
        std::cout << "You can also run the program without parameters, then the program\n";
        std::cout << "with the default file will be executed.\n\n";
        return (0);
    }
    clock_t start = clock();
    std::vector<long long> numbers;
    readDataFromFile(filename, numbers);
    int size = numbers.size();
    if (size == 0)
        return (0);
    // menu(numbers);
    int max = maxElement(numbers);
    std::cout << "MAX = " << max << std::endl;
    int min = minElement(numbers);
    std::cout << "MIN = " << min << std::endl;
    float median = medianFind(numbers, size);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << "Median = " << median << std::endl;
    double average = averageFind(numbers, size);
    std::cout << "Average = " << average << std::endl;
    std::vector<long long> sequence_increase = sequenceIncrease(numbers, size);
    printElements(sequence_increase);
    std::vector<long long> sequence_decrease = sequenceDecrease(numbers, size);
    printElements(sequence_decrease);

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Program execution time:" << duration << " сек" << std::endl;
    return 0;
}
