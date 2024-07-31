const totalIncDec = x => {
  const combinations = new Array(500).fill(0).map(() => new Array(500));
  for (let i = 0; i < 500; i++) {
    for (let j = 0; j < 500; j++) {
      combinations[i][j] = j > i ? 0 : i == j || j == 0 ? 1 : combinations[i - 1][j] + combinations[i - 1][j - 1];
    }
  }
  return combinations[x + 9][x] + (x + 1) * combinations[x + 10][x + 1] / 10 - 10 * x - 1;
};

console.log(totalIncDec(1), 10);
console.log(totalIncDec(2), 100);
console.log(totalIncDec(3), 475);
console.log(totalIncDec(4), 1675);
