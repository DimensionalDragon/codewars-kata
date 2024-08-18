const sequenceSum = (begin, end, step) => begin > end ? 0 : Array.from({length: Math.floor((end - begin)/step) + 1}, (_, i) => i * step + begin).reduce((sum, v) => sum + v);

console.log(sequenceSum(2, 6, 2), 12);
console.log(sequenceSum(1, 5, 1), 15);
console.log(sequenceSum(1, 5, 3), 5);