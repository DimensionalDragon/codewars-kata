function accum(string) { return string.toLowerCase().split('').map((char, idx) => char.toUpperCase() + char.repeat(idx)).join('-')};

console.log(accum('abc'), 'A-Bb-Ccc');
console.log(accum('rrqft'), 'R-Rr-Qqq-Ffff-Ttttt');
console.log(accum("ZpglnRxqenU"), "Z-Pp-Ggg-Llll-Nnnnn-Rrrrrr-Xxxxxxx-Qqqqqqqq-Eeeeeeeee-Nnnnnnnnnn-Uuuuuuuuuuu");