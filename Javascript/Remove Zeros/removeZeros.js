function isZeroTillTheEnd(array, index) { // Check if from a certain index to the end is all zero
	for(let i = index; i < array.length; i++)
		if(array[i] !== 0 && array[i] !== '0') return false;
	return true;
}

function removeZeros(array) {
	for(let i = 0; i < array.length; i++) {
		if((array[i] === 0 || array[i] === '0') && !isZeroTillTheEnd(array, i)) {
			array.length = array.length + 1; // Add an index to array without pushing
			array[array.length - 1] = array[i]; // Set the value of the new index as a "temp" without creating new temp variable
			for(let j = i; j < array.length - 1; j++) // Shifting
				array[j] = array[j + 1];
			array.length = array.length - 1; // Remove last index of array without popping
      		if(!isZeroTillTheEnd(array, i)) i--; // Anticipating consecutive zeros by subtracting the index
		}
	}
	return array;
}

let input = [7, 2, 3, 0, 4, 6, 0, 0, 13, 0, 78, 0, 0, 19, 14],
solution = [7, 2, 3, 4, 6, 13, 78, 19, 14, 0, 0, 0, 0, 0, 0];
console.log(removeZeros(input), solution);