#include <iostream>
#include <vector>
#define Matrix vector<vector<int>>

using namespace std;

Matrix minorMatrix(Matrix m, int row, int column) // remove a row and a column from a matrix
{
	Matrix minor = m;
	minor.erase(minor.begin() + row);
	for(int i = 0; i < minor.size(); i++)
	{
		minor[i].erase(minor[i].begin() + column);
	}
	return minor;
}

long long determinant(Matrix m)
{
	if(m.size() == 1) // base case 1x1
	{
		return m[0][0];
	}
    if(m.size() == 2) // base case 2x2
	{
		return m[0][0] * m[1][1] - m[0][1] * m[1][0];
	}
	int power[2] = {1, -1}; // even and odd powers of -1 so that we don't need the pow function
	int result = 0;
	for(int i = 0; i < m[0].size(); i++)
	{
		result += power[i % 2] * m[0][i] * determinant(minorMatrix(m, 0, i));
	}
	return result;
}

int main()
{
	Matrix m0 = {{1}};
	Matrix m1 = {
		{1, 3},
		{2, 5}
	};
	Matrix m2 = {
		{2,  5,  3},
		{1, -2, -1},
		{1,  3,  4}
	};

	cout << determinant(m0) << " " << 1 << endl;
	cout << determinant(m1) << " " << -1 << endl;
	cout << determinant(m2) << " " << -20 << endl;
    return 0;
}