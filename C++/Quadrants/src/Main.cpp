#include <iostream>

using namespace std;

int quadrant(int x, int y)
{
  return (x > 0) ? (y > 0 ? 1 : 4) : (y > 0 ? 2 : 3);
}

int main()
{
	  cout << quadrant(1, 2) << ", " << 1 << endl;
    cout << quadrant(3, 5) << ", " << 1 << endl;
    cout << quadrant(-10, 100) << ", " << 2 << endl;
    cout << quadrant(-1, -9) << ", " << 3 << endl;
    cout << quadrant(19, -56) << ", " << 4 << endl;
}