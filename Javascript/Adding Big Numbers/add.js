const add = (a, b) => {
    /* Cut the longer number to make both strings have the same length */
	let cutoff = a.length < b.length ? b.substr(0, b.length - a.length) : a.substr(0, a.length - b.length);
	a.length < b.length ? b = b.substr(b.length - a.length) : a = a.substr(a.length - b.length);
  
    /* Trivial cases (one of the strings is 0 or both is a 1 digit number) */
    if(a.length == 0 || a == '0') return `${cutoff}${b}`;
    if(b.length == 0 || b == '0') return `${cutoff}${a}`;
    if(a.length == 1 && b.length == 1) return add(`${cutoff}0`, `${(parseInt(a[0]) + parseInt(b[0]))}`);
  
    /* General cases */
	let result = '';
	let carry = 0;
	for(let i = a.length - 1; i >= 0; i--) // Add every digit with it's partner and carry, add carry to cutoff if overflow
	{
		const addResult = parseInt(a[i]) + parseInt(b[i]) + carry; // Add
		result += `${addResult % 10}`; // Store it in result
		carry = Math.floor(addResult / 10) % 10; // Update the carry
		if(i == 0 && carry > 0) cutoff = add(`${carry}`, `${cutoff}`); // If carry overflowed, add it to cutoff
	}
    return `${cutoff}${result.split('').reverse().join('')}`; // The result of adding the digits are backwards, reverse the result then append the cutoff to the front of result
}

console.log(add('1', '1'), '2');
console.log(add('123', '456'), '579');
console.log(add('888', '222'), '1110');
console.log(add('1372', '69'), '1441');
console.log(add('12', '456'), '468');
console.log(add('101', '100'), '201');
console.log(add('63829983432984289347293874', '90938498237058927340892374089'), '91002328220491911630239667963')