#include <iostream>
#include <cmath>
#include <vector>
#define FLRSQRT(x) floor(sqrt(x))

using namespace std;

int sumOfSquares(int n)
{
	// If n is a perfect square, result is 1
    if(FLRSQRT(n) * FLRSQRT(n) == n) return 1;
	// If n is a sum of 2 square numbers, result is 2
    vector<int> squares;
	for(int i = 1; i <= FLRSQRT(n); i++)
	{
		squares.push_back(i * i); // Generate all perfect squares less than n
	}
    for(int i = 0; i < squares.size(); i++)
	{
        if(FLRSQRT(n - squares[i]) * FLRSQRT(n - squares[i]) == n - squares[i]) return 2;
    }
	// if n is in the form of 4^k(8m + 7), k and m integers, result is 4
    while(n % 4 == 0)
	{
        n /= 4;
    }
    if(n % 8 == 7) return 4;
    // If no cases above is satisfied, result is 3
    return 3;
}

int main()
{
	cout << (sumOfSquares(15), 4) << endl;
	cout << (sumOfSquares(16), 1) << endl;
	cout << (sumOfSquares(17), 2) << endl;
	cout << (sumOfSquares(18), 2) << endl;
	cout << (sumOfSquares(19), 3) << endl;
	cout << (sumOfSquares(26), 2) << endl;
	cout << (sumOfSquares(3456), 3) << endl;
	cout << (sumOfSquares(1008), 4) << endl;
}