const solve = m => (2 * m + 1 - Math.sqrt(4 * m + 1)) / (2 * m); // The sum problem is reduced into solving the quadratic mx^2 - (2m + 1)x + m = 0, solve using quadratic formula

console.log(solve(2.0));