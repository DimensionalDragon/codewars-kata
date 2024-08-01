const perimeter = n => (new Array(n + 3).fill(0).reduce((fibo, _, i) => (i == 0 || i == 1) ? [1, 1] : [fibo[1], fibo[0] + fibo[1]])[1] - 1) * 4;

console.log(perimeter(0), 4);
console.log(perimeter(5), 80);
console.log(perimeter(7), 216);
console.log(perimeter(20), 114624);
console.log(perimeter(30), 14098308);
