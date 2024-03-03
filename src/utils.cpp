#include "../statistics.h"

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
	if (count_sequence - 1 > *last_index)
	{
		*last_index = size - 1;
		final_sequence = count_sequence;
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

double sumAllElements(std::vector<long long> &numbers, int size)
{
	double sumOfElems = 0.0;
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
