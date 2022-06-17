function parseInt(string) {
	// Map/dict for numbers"
	const numberMap = {
		zero: 0, one: 1, two: 2, three: 3, four: 4, five: 5, six: 6, seven: 7, eight: 8, nine: 9,
		eleven: 11, twelve: 12, thirteen: 13, fourteen: 14, fifteen: 15, sixteen: 16, seventeen: 17, eighteen: 18, nineteen: 19,
		ten: 10, twenty: 20, thirty: 30, forty: 40, fifty: 50, sixty: 60, seventy: 70, eighty: 80, ninety: 90,
		hundred: 100, thousand: 1000, million: 1000000
	};

	const words = string.split(/\s|-/); // Split the number into words
	return words.reduce((stack, word) => {
		if(word === 'and') return {results: stack.results, offset: stack.offset};
		/* Using a stack-like (with offset) data structure to calculate number everytime a hundred, thousand, or million found */
		if(word === 'hundred' || word === 'thousand' || word === 'million') {
			/* If multiplier is less than previous calculation, that multiplier is not meant for the whole number. Add the offset to "ignore" the last calculation and continue to the next */
			if(numberMap[word] <= stack.results[stack.offset]) stack.offset++;
			/* Collapse : add everything in the stack (starting from offset), multiply by the multiplier, and push the result back to stack */
			const collapsed = stack.results.slice(stack.offset).reduce((sum, result) => sum + result, 0);
			return {results: [...stack.results.slice(0, stack.offset), numberMap[word] * collapsed], offset: stack.offset};
		}
		return {results: [...stack.results, numberMap[word]], offset: stack.offset};
	}, {results: [], offset: 0}).results.reduce((sum, result) => sum + result, 0); // Add everything in the result stack to get the final result
}

console.log(parseInt('one'), 1);
console.log(parseInt('twenty'), 20);
console.log(parseInt('two hundred forty-six'), 246);
console.log(parseInt('seven hundred eighty-three thousand nine hundred and nineteen'), 783919);