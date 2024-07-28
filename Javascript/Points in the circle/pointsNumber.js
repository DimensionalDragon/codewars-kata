function pointsNumber(radius) {
    // Using approximation sum
    let partial_sum = 0;
    for (let i = 0; i < 1000000; i++) {
        let first_term = Math.floor((radius * radius) / (4 * i + 1));
        let second_term = Math.floor((radius * radius) / (4 * i + 3));
        partial_sum += first_term - second_term;
    }
    return Math.round(1 + 4 * partial_sum);
}

console.log(pointsNumber(1), 5);
console.log(pointsNumber(2), 13);
console.log(pointsNumber(3), 29);
console.log(pointsNumber(5), 81);
console.log(pointsNumber(1000), 3141549);
