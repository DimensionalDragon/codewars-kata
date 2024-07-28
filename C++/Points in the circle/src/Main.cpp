#include <iostream>
#include <cmath>

using namespace std;

int pointsNumber(int radius) // Using approximation sum
{
  double partial_sum = 0.0;
  for (int i = 0; i < 1000000; i++)
  {
    int first_term = floor(radius * radius / (4 * i + 1));
    int second_term = floor(radius * radius / (4 * i + 3));
    partial_sum += (first_term - second_term);
  }
  return round(1 + 4 * partial_sum);
}

int main()
{
	cout << pointsNumber(1) << ", " << 5 << endl;
	cout << pointsNumber(2) << ", " << 13 << endl;
	cout << pointsNumber(3) << ", " << 29 << endl;
	cout << pointsNumber(5) << ", " << 81 << endl;
	cout << pointsNumber(1000) << ", " << 3141549 << endl;
}