const highAndLow = s => `${Math.max(...s.split(' '))} ${Math.min(...s.split(' '))}`;

console.log(highAndLow('1 9 3 4 -5'))
console.log(highAndLow("8 3 -5 42 -1 0 0 -9 4 7 4 -4"), "42 -9");