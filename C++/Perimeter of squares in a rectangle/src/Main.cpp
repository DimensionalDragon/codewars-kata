#include <iostream>

using namespace std;

typedef unsigned long long ull;

static ull perimeter(int n)
{
  /* Calculate ((n+1)+2)th fibonacci number */
  ull a[2] = {1, 1};
  for (int i = 3; i <= (n + 1) + 2; i++)
  {
    ull next = a[0] + a[1];
    a[0] = a[1];
    a[1] = next;
  }
  
  /* Sum of first k fibonacci number = (k+2)th fibonacci number - 1 */
  return 4 * (a[1] - 1);
}

int main()
{
  cout << perimeter(5) << ", " << 80 << endl;
  cout << perimeter(7) << ", " << 216 << endl;
  cout << perimeter(20) << ", " << 114624 << endl;
  cout << perimeter(30) << ", " << 14098308 << endl;
}