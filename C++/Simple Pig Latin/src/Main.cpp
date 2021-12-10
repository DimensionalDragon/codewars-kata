#include <iostream>
#include <vector>
#include <string>

using namespace std;

string pig_it(string str)
{
	vector<string> words;
	string result = "";

	/* Parse string so that every word (and punctuations) becomes one element in vector */
	int start = 0;
	for(int i = 0; i <= str.length(); i++)
	{
		if(str[i] == ' ' || str[i] == '\0')
		{
			words.push_back(str.substr(start, i - start));
			start = i + 1;
		}
	}

	/* For every word, if it starts with alphabet, transform it, if not, ignore it */
	for(string& word : words)
	{
		if((word[0] >= 'a' && word[0] <= 'z') || (word[0] >= 'A' && word[0] <= 'Z')) word = word.substr(1) + word[0] + "ay";
		result += word + " "; // Append both transformed and not transformed words to result
	}

	return result.substr(0, result.length() - 1); // Delete the extra space character on the back of result and return it
}

int main()
{
	cout << pig_it("Pig latin a is life ! . hey") << endl;
    return 0;
}