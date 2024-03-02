#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <numeric>
#include <unistd.h>

//All main operations with numbers

long long minElement(std::vector<long long> &numbers);
long long maxElement(std::vector<long long> &numbers);
float medianFind(std::vector<long long> &numbers, int size);
double averageFind(std::vector<long long> &numbers, int size);
std::vector<long long> sequenceIncrease(std::vector<long long> &numbers, int size);
std::vector<long long> sequenceDecrease(std::vector<long long> &numbers, int size);

//Reading from a file and initializing a vector

bool readDataFromFile(const std::string &filename, std::vector<long long> &numbers);
std::string initFilename(int ac, char *av[]);

//Secondary functions for vector

double sumAllElements(std::vector<long long> &numbers, int size);
double sumAllElements1(std::vector<long long> &numbers);
int findLongestSequence(std::vector<long long> &numbers, int size, bool increase, int *last_index);
std::vector<long long> &initNewSequence(std::vector<long long> &sequence, std::vector<long long> &numbers, int size, int index);

//Display of calculation results
void printElements(std::vector<long long> &numbers);
void menu(std::vector<long long> &numbers);
void printInfo(std::vector<long long> &numbers, int size);

#endif