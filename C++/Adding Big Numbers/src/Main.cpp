#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string add(string a, string b)
{
	/* Cut the longer number to make both strings have the same length */
	string cutoff = a.length() < b.length() ? b.substr(0, b.length() - a.length()) : a.substr(0, a.length() - b.length());
	a.length() < b.length() ? b = b.substr(b.length() - a.length()) : a = a.substr(a.length() - b.length());
  
  	/* Trivial cases (one of the strings is 0 or both is a 1 digit number) */
  	if(a.length() == 0 || a == "0") return cutoff.append(b);
	if(b.length() == 0 || b == "0") return cutoff.append(a);
  	if(a.length() == 1 && b.length() == 1) return add(cutoff.append("0"), to_string((a[0] - '0') + (b[0] - '0')));
  
  	/* General cases */
	string result = "";
	int carry = 0;
	for(int i = a.length() - 1; i >= 0; i--) // Add every digit with it's partner and carry, add carry to cutoff if overflow
	{
		int addResult = (a[i] - '0') + (b[i] - '0') + carry; // Add
		result += addResult % 10 + '0'; // Store it in result
		carry = (addResult / 10) % 10; // Update the carry
		if(i == 0 && carry > 0) cutoff = add(to_string(carry), cutoff); // If carry overflowed, add it to cutoff
	}
	reverse(result.begin(), result.end()); // The result of adding the digits are backwards, reverse needed
	return cutoff.append(result); // Append the cutoff to the front of result and return it
}

int main()
{
	string a = "31", b = "69";
	string result = add(a, b);
	cout << "[Main] result = " << result << endl;
    return 0;
}