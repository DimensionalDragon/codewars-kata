const minorMatrix = (m, row, column) => { // remove a row and a column from a matrix
	return m.filter((_, i) => i != row).map(row => row.filter((_, i) => i != column));
}

const determinant = (m) => {
	if(m.length === 1) return m[0][0]; // base case 1x1
    if(m.length === 2) return m[0][0] * m[1][1] - m[0][1] * m[1][0]; // base case 2x2
	const power = [1, -1]; // even and odd powers of -1 so that we don't need the pow function
	const result = m[0].reduce((total, element, i) => total + power[i % 2] * element * determinant(minorMatrix(m, 0, i)), 0);
	return result;
}

m1 = [
	[1, 3],
	[2, 5]
];

m2 = [
	[2,  5,  3],
	[1, -2, -1],
	[1,  3,  4]
];

console.log(determinant([[1]]), 1)
console.log(determinant(m1), -1)
console.log(determinant(m2), -20)