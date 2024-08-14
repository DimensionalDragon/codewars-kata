const findMissing = (list) => list.reduce((result, v, i) => (i < list.length - 1 && list[i] + (list[list.length - 1] - list[0]) / list.length != list[i + 1]) ? list[i] + (list[list.length - 1] - list[0]) / list.length : result, -1);

console.log(findMissing([1, 3, 4]), 2);