#include <iostream>
#include <cmath>

using namespace std;

double solve(double m) // The sum problem is reduced into solving the quadratic mx^2 - (2m + 1)x + m = 0
{
	double mid = (2 * m + 1) / (2 * m); // Get the midpoint of the roots
	double distance = sqrt(mid * mid - 1); // Get the distance from midpoint to root
	return (mid + distance < 1) ? mid + distance : mid - distance; // Choose the root that is smaller than 1 since only that root would converge
}

int main()
{
	cout.precision(16);
	cout << solve(8.0) << endl;
    return 0;
}