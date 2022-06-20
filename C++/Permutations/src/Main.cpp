#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void print_vector(vector<string> v)
{
	cout << "{";
	for(int i = 0; i < v.size() - 1; i++)
	{
		cout << v[i] << ", ";
	}
	cout << v[v.size() - 1] << "}" << endl;
}

vector<string> permutations(string s, unordered_map<string, bool> memo = unordered_map<string, bool>())
{
	// Base case
	if(s.size() == 1)
		return {s};
	// permutations("ABCD") = permutations("BCD") with A added to every position ("AXXX", "XAXX", "XXAX", "XXXA") 
	vector<string> subPermutations = permutations(s.substr(1), memo); // Get sub-permutation
	// For loop to append first letter to every position and store it to result
	vector<string> result;
	for(string& subPermutation : subPermutations)
	{
		for(int i = 0; i <= subPermutation.size(); i++)
		{
			string nextAppendedPermutation = subPermutation.substr(0, i) + s[0] + subPermutation.substr(i);
			if(memo.find(nextAppendedPermutation) != memo.end()) // Don't insert the same value if it's already in the memo
				continue;
			memo[nextAppendedPermutation] = true;
			result.push_back(nextAppendedPermutation);
		}
	}
	return result;
}

int main()
{
	print_vector(std::vector<std::string> {"a"});
	print_vector(permutations("a"));
	cout << endl;
    print_vector(std::vector<std::string> {"ab", "ba"});
	print_vector(permutations("ab"));
	cout << endl;
    print_vector(std::vector<std::string> {"aabb", "abab", "abba", "baab", "baba", "bbaa"});
	print_vector(permutations("aabb"));
	cout << endl;
    print_vector(std::vector<std::string> {"aaaab", "aaaba", "aabaa", "abaaa", "baaaa"});
	print_vector(permutations("aaaab"));
	cout << endl;
	return 0;
}