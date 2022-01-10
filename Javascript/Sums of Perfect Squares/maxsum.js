const sumOfSquares = n => {
    // If n is a perfect square, result is 1
    if(Number.isInteger(Math.sqrt(n))) return 1;
    // If n is a sum of 2 square numbers, result is 2
    const squares = new Array(Math.floor(Math.sqrt(n))).fill(0).map((num, index) => (index + 1) * (index + 1)); // Generate all perfect squares less than n
    for(let i = 0; i < squares.length; i++) {
        if(Number.isInteger(Math.sqrt(n - squares[i]))) return 2;
    }
    // if n is in the form of 4^k(8m + 7), k and m integers, result is 4
    while(n % 4 == 0) {
        n /= 4;
    }
    if(n % 8 === 7) return 4;
    // If no cases above is satisfied, result is 3
    return 3;
}

console.log(sumOfSquares(15), 4);
console.log(sumOfSquares(16), 1);
console.log(sumOfSquares(17), 2);
console.log(sumOfSquares(18), 2);
console.log(sumOfSquares(19), 3);
console.log(sumOfSquares(26), 2);
console.log(sumOfSquares(3456), 3);
console.log(sumOfSquares(1008), 4);