#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long parse_int(std::string number)
{
	// Map/dict for numbers
	unordered_map<string, int> numberMap{
		{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
		{"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19},
		{"ten", 10}, {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50}, {"sixty", 60}, {"seventy", 70}, {"eighty", 80}, {"ninety", 90},
		{"hundred", 100}, {"thousand", 1000}, {"million", 1000000}
	};

	// Split the number into words
	vector<int> results;
	int startIndex = 0, stackOffset = 0;
	for(int i = 0; i < number.size(); i++)
	{
		if(number[i] == ' ' || number[i] == '-' || i == number.size() - 1) // Split when space, dash, or end of string reached
		{
			int endIndex = (i == number.size() - 1) ? (i - startIndex + 1) : (i - startIndex);
			string word = number.substr(startIndex, endIndex);
			startIndex = i + 1;
			if(word == "and")
				continue;
			/* Using a stack-like (with offset) data structure to calculate number everytime a hundred, thousand, or million found */
			if(word == "hundred" || word == "thousand" || word == "million")
			{
				int multiplier = numberMap[word];
				/* 	If multiplier is less than previous calculation, that multiplier is not meant for the whole number. Add the offset to "ignore" the last calculation and continue to the next */
				if(multiplier <= results[stackOffset])
					stackOffset++;
				/* Collapse : add everything in the stack (starting from offset), multiply by the multiplier, and push the result back to stack */
				int collapsed = 0;
				while(results.size() > stackOffset)
				{
					collapsed += results.back();
					results.pop_back();
				}
				results.push_back(multiplier * collapsed);
				continue;
			}
			results.push_back(numberMap[word]);
		}
	}

	/* Add everything in the result stack to get the final result */
	long result = 0;
	for(int res : results)
	{
		result += res;
	}
	return result;
}

int main()
{
	cout << parse_int("one") << ' ' <<  1 << endl;
	cout << parse_int("twenty") << ' ' <<  20 << endl;
	cout << parse_int("two hundred and forty-six") << ' ' <<  246 << endl;
	cout << parse_int("seven hundred eighty-three thousand nine hundred and nineteen") << ' ' <<  783919 << endl;
	cout << parse_int("one million") << ' ' <<  1000000 << endl;
	return 0;
}