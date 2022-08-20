const snail = array => array[0].length === 0 ? [] : new Array(Math.floor(array[0].length / 2) + 1).fill(0).map((_, depth) => Math.floor((array[0].length - depth * 2) / 2) == 0 ? (array[0].length - depth * 2) % 2 == 1 ? [array[depth][depth]] : [] : [...new Array(array[0].length - depth * 2).fill(0).map((_, j) => array[depth][j + depth]), ...new Array(array[0].length - depth * 2 - 1).fill(0).map((_, i) => array[i + depth + 1][array[0].length - 1 - depth]), ...new Array(array[0].length - depth * 2 - 1).fill(0).map((_, j) => array[array[0].length - 1 - depth][array[0].length - 2 - depth - j]), ...new Array(array[0].length - depth * 2 - 2).fill(0).map((_, i) => array[array[0].length - 2 - depth - i][depth])]).filter(arr => arr[0] != null).reduce((result, arr) => [...result, ...arr], []);

console.log(snail([[]]), []);
console.log(snail([[1]]), [1]);
console.log(
    snail([
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9],
    ]),
    [1, 2, 3, 6, 9, 8, 7, 4, 5]
);
console.log(
    snail([
        [1, 2, 3, 4, 5],
        [6, 7, 8, 9, 10],
        [11, 12, 13, 14, 15],
        [16, 17, 18, 19, 20],
        [21, 22, 23, 24, 25],
    ]),
    [
        1, 2, 3, 4, 5, 10, 15, 20, 25, 24, 23, 22, 21, 16, 11, 6, 7, 8, 9, 14,
        19, 18, 17, 12, 13,
    ]
);
console.log(
    snail([
        [1, 2, 3, 4, 5, 6],
        [20, 21, 22, 23, 24, 7],
        [19, 32, 33, 34, 25, 8],
        [18, 31, 36, 35, 26, 9],
        [17, 30, 29, 28, 27, 10],
        [16, 15, 14, 13, 12, 11],
    ]),
    [
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
    ]
);
