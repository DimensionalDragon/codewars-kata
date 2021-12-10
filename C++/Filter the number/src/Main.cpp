#include <iostream>
#include <string>

using namespace std;

long long filter_string(const std::string &value)
{
    string result;
	for(char c : value)
		if(c >= '0' && c <= '9') result += c;
	return stoll(result);
}

int main()
{
	cout << filter_string("aa1bb2cc3dd") << endl;
    return 0;
}