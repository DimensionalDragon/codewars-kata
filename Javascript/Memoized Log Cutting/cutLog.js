const cutLog = (p, n) => new Array(100).fill(0).reduce((result, _, j) => (j == 0) ? result : [...result, p.slice(1, j+1).reduce((max, _, i) => Math.max(max, p[i + 1] + result[j - (i + 1)]), 0)], [0])[n];

let p = [0,   1,   5,   8,   9,  10,  17,  17,  20,  24, // 0X's
        30,  32,  35,  39,  43,  43,  45,  49,  50,  54, // 1X's
        57,  60,  65,  68,  70,  74,  80,  81,  84,  85, // 2X's
        87,  91,  95,  99, 101, 104, 107, 112, 115, 116, // 3X's
        119] // 40th element

console.log(cutLog(p, 1), 1);
console.log(cutLog(p, 5), 13);
console.log(cutLog(p, 8), 22);
console.log(cutLog(p, 10), 30);
console.log(cutLog(p, 22), 65);
