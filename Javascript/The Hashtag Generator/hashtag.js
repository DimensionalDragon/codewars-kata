const generateHashtag = str => !str.replace(/ /g, '').length || str.replace(/ /g, '').length > 139 ? false : `#${str.split(' ').filter(el => el !== '').reduce((res, word) => res + (word ? word[0].toUpperCase() + word.substr(1).toLowerCase() : ''), '')}`;

console.log(generateHashtag('   hello   world '));
console.log(generateHashtag('     '));
console.log(generateHashtag("code" + " ".repeat(140) + "wars"));