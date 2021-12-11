#include <iostream>
#include <vector>
#include <cmath>

int memo[100][100];

void clearArray(int array[100][100]) // Codewars somehow retains the array content for next test so i had to do this
{
	for(int i = 0; i <= 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			array[i][j] = 0;
		}
	}
}

int sum(const std::vector<int> arr, int start, int end) // Sum array elements in certain range
{
	int total = 0;
	for(int i = start; i <= end; i++)
	{
		total += arr[i];
	}
	return total;
}

int maxSequenceDP(const std::vector<int>& arr, int start, int end) // Dynamic Programming helper function
{
    /* Base cases */
    if(arr.size() == 0 || start > end) return 0;
    if(memo[start][end]) return memo[start][end];

    /* DP formula is max(sum of all elements, max sequence sum of the array without the first element, max sequence sum of the array without the last element) */
    memo[start][end] = std::max(std::max(sum(arr, start, end), maxSequenceDP(arr, start + 1, end)), maxSequenceDP(arr, start, end - 1));
    return memo[start][end];
}

int maxSequence(const std::vector<int>& arr) // Call the DP helper function
{
	clearArray(memo);
	return maxSequenceDP(arr, 0, arr.size() - 1);
}

int main()
{
	std::cout << maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << std::endl;
    return 0;
}