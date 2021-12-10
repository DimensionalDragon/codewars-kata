const pigIt = str => str.split(' ').map(word => (word[0] >= 'a' && word[0] <= 'z') || (word[0] >= 'A' && word[0] <= 'Z') ? word.substr(1) + word[0] + 'ay' : word).join(' ');

console.log(pigIt('O pig latin is cool y ! ? .'));