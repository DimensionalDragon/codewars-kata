#include <iostream>
#include <cmath>

using namespace std;

int findClosestPowerOfTwo(int n) // Helper function to determine closest power of 2 less than n
{
	int i = 0;
	while(pow(2, i) <= n)
	{
		if(n == pow(2, i)) return n;
		i++;
	}
	return pow(2, i - 1);
}

long long countOnes(int left, int right)
{
	/* Base cases */
	if(left == 0 && right == 0) return 0; // 0 to 0
	if(left == 0 && right == 1) return 1; // 0 to 1
	if(left == 0 && right + 1 == findClosestPowerOfTwo(right + 1)) return 2 * countOnes(0, (right + 1)/2 - 1) + (right + 1)/2; // 0 to (power of 2) - 1

	/* case where the upper limit is not 1 less than a power of 2, clue: the next "power of 2 area" has one more 1 in every element */	
	else if(left == 0)
	{
		int closestPowerOfTwo = findClosestPowerOfTwo(right);
		return countOnes(0, closestPowerOfTwo - 1) + countOnes(0, right - closestPowerOfTwo) + (right - closestPowerOfTwo + 1);
	}
	return countOnes(0, right) - countOnes(0, left - 1); // General case (lower limit is not 0)
}

int main()
{
	std::cout << countOnes(0, 2) << std::endl;
    return 0;
}