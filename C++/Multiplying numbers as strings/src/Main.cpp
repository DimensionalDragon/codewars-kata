#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string operator+(string a, string b)
{
  /* Cut the longer number to make both strings have the same length */
	string cutoff = a.length() < b.length() ? b.substr(0, b.length() - a.length()) : a.substr(0, a.length() - b.length());
	a.length() < b.length() ? b = b.substr(b.length() - a.length()) : a = a.substr(a.length() - b.length());
  
  /* Trivial cases (one of the strings is 0 or both is a 1 digit number) */
  if(a.length() == 0 || a == "0") return cutoff.append(b);
	if(b.length() == 0 || b == "0") return cutoff.append(a);
  if(a.length() == 1 && b.length() == 1) return cutoff.append("0") + to_string((a[0] - '0') + (b[0] - '0'));
  
  /* General cases */
	string result = "";
	int carry = 0;
	for(int i = a.length() - 1; i >= 0; i--) // Add every digit with it's partner and carry, add carry to cutoff if overflow
	{
		int addResult = (a[i] - '0') + (b[i] - '0') + carry; // Add
		result += addResult % 10 + '0'; // Store it in result
		carry = (addResult / 10) % 10; // Update the carry
		if(i == 0 && carry > 0) cutoff = to_string(carry) + cutoff; // If carry overflowed, add it to cutoff
	}
	reverse(result.begin(), result.end()); // The result of adding the digits are backwards, reverse needed
	result = cutoff.append(result); // Append the cutoff to the front of result
	return result;
}

string operator*(string a, string b)
{
  vector<string> results;
  
  /* Append 0s to the front of the shorter number */
	a.length() < b.length() ? a = string(b.length() - a.length(), '0').append(a) : b = string(a.length() - b.length(), '0').append(b);

  /* Multiplication procedure */
	for(int i = a.length() - 1; i >= 0; i--)
	{
		string rowResult = ""; // Temporary result
		int carry = 0;
		for(int j = b.length() - 1; j >= 0; j--) // Multiply 1 digit from b to every digit of a
		{
			int multiplyResult = (a[i] - '0') * (b[j] - '0') + carry; // Multiply and add previous carry
			rowResult += multiplyResult % 10 + '0'; // Store it in rowResult
			carry = (multiplyResult / 10) % 10; // Update the carry
			if(j == 0 && carry > 0) rowResult += carry + '0'; // If carry overflowed, append it to the front
		}
		reverse(rowResult.begin(), rowResult.end()); // The result of multiplying the digits are backwards, reverse needed
		results.push_back(rowResult); //store the rowResult in results vector
	}
  
  /* Repeatedly add first and second element of results, then remove the first element, until only one remains */
	for(int i = 1; results.size() > 1; i++)
	{
		results[1] = results[0] + results[1].append(string(i, '0'));
		results.erase(results.begin());
	}
  
  /* Leading 0 removal */
	while(results[0][0] == '0' && results[0].length() > 1) // Leading 0 removal
		results[0].erase(results[0].begin());
  
	return results[0];
}

int main()
{
	string a = "30", b = "69";
	string result = a * b;
	cout << "[Main] result = " << result << endl;
    return 0;
}