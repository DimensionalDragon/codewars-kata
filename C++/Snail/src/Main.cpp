#include <iostream>
#include <vector>

using namespace std;

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map, int depth = 0)
{
	const int size = snail_map[0].size();
	vector<int> result;

	// Base case (empty or 1x1)
	if((size - depth * 2) / 2 == 0)
	{
		if((size - depth * 2) % 2 == 1)
		{
			result.push_back(snail_map[depth][depth]);
		}
		return result;
	}

	// Outer top
	for(int j = depth; j < size - depth; j++)
	{
		result.push_back(snail_map[depth][j]);
	}

	// Outer right
	for(int i = 1 + depth; i < size - depth; i++)
	{
		result.push_back(snail_map[i][size - 1 - depth]);
	}

	// Outer bottom
	for(int j = size - 2 - depth; j >= depth; j--)
	{
		result.push_back(snail_map[size - 1 - depth][j]);
	}

	// Outer left
	for(int i = size - 2 - depth; i >= 1 + depth; i--)
	{
		result.push_back(snail_map[i][depth]);
	}

	// Inner matrix (recursive)
	vector<int> inner = snail(snail_map, depth + 1);
	result.insert(result.end(), inner.begin(), inner.end());
	return result;
}

void print_vector(vector<int> v) {
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main()
{
	std::vector<std::vector<int>> v;
    std::vector<int> expected;
    
    v = {{}};
    expected = {};
	cout << "[1] result = ";
	print_vector(snail(v));
    
    v = {{1}};
    expected = {1};
	cout << "[2] result = ";
	print_vector(snail(v));

    
    v = {{1,2}, {4,3}};
    expected = {1,2,3,4};
	cout << "[3] result = ";
	print_vector(snail(v));
    
    v = {{1,2,3}, {8,9,4}, {7,6,5}};
    expected = {1,2,3,4,5,6,7,8,9};
	cout << "[4] result = ";
	print_vector(snail(v));
}