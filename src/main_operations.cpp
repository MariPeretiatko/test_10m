#include "../statistics.h"

long long minElement(std::vector<long long> &numbers)
{
	return (*std::min_element(numbers.begin(), numbers.end()));
}

long long maxElement(std::vector<long long> &numbers)
{
	return (*std::max_element(numbers.begin(), numbers.end()));
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
