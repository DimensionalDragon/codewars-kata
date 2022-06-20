const permutations = (string, memo = {}) => (string.length === 1) ? [string] : permutations(string.substr(1), memo).map((subPermutation) => new Array(subPermutation.length + 1).fill(0).reduce((result, _, i) => (memo[subPermutation.substr(0, i) + string[0] + subPermutation.substr(i)] === (memo[subPermutation.substr(0, i) + string[0] + subPermutation.substr(i)] = true)) ? result : [...result, subPermutation.substr(0, i) + string[0] + subPermutation.substr(i)], [])).reduce((result, subPermutation) => Array.isArray(subPermutation) ? [...result, ...subPermutation] : [...result, subPermutation], []);

console.log(permutations('a'), ['a']);
console.log(permutations('ab').sort(), ['ab', 'ba'].sort());
console.log(permutations('aabb').sort(), ['aabb', 'abab', 'abba', 'baab', 'baba', 'bbaa'].sort());
console.log(permutations('aaaab').sort(),[ 'aaaab', 'aaaba', 'aabaa', 'abaaa', 'baaaa' ].sort());