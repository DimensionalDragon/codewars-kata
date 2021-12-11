const findClosestPowerOfTwo = (n) => { // Helper function to determine closest power of 2 less than n
	let i = 0;
	while(Math.pow(2, i) <= n)
	{
		if(n == Math.pow(2, i)) return n;
		i++;
	}
	return Math.pow(2, i - 1);
};

const countOnes = (left, right) => {
	/* Base cases */
	if(left == 0 && right == 0) return 0; // 0 to 0
	if(left == 0 && right == 1) return 1; // 0 to 1
	if(left == 0 && right + 1 == findClosestPowerOfTwo(right + 1)) return 2 * countOnes(0, (right + 1)/2 - 1) + (right + 1)/2; // 0 to (power of 2) - 1

	/* case where the upper limit is not 1 less than a power of 2, clue: the next "power of 2 area" has one more 1 in every element */	
	else if(left == 0)
	{
		const closestPowerOfTwo = findClosestPowerOfTwo(right);
		return countOnes(0, closestPowerOfTwo - 1) + countOnes(0, right - closestPowerOfTwo) + (right - closestPowerOfTwo + 1);
	}
	return countOnes(0, right) - countOnes(0, left - 1); // General case (lower limit is not 0)
}

console.log(countOnes(0, 2));