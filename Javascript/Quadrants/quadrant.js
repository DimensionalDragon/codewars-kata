const quadrant = (x, y) => (x > 0 ? (y > 0 ? 1 : 4) : y > 0 ? 2 : 3);

console.log(quadrant(1, 2), 1);
console.log(quadrant(3, 5), 1);
console.log(quadrant(-10, 100), 2);
console.log(quadrant(-1, -9), 3);
console.log(quadrant(19, -56), 4);
