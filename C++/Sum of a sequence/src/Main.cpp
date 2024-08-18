#include <iostream>

using namespace std;

int sequenceSum(int start, int end, int step)
{
  int result = 0;
  for(int i = start; i <= end; i += step)
  {
    result += i;
  }
  return result;
}

int main()
{
  cout << sequenceSum(2, 6, 2) << "," << 12 << endl;
  cout << sequenceSum(1, 5, 1) << "," << 15 << endl;
  cout << sequenceSum(1, 5, 3) << "," << 5 << endl;
  cout << sequenceSum(0, 15, 3) << "," << 45 << endl;
  cout << sequenceSum(16, 15, 3) << "," << 0 << endl;
  cout << sequenceSum(2, 24, 22) << "," << 26 << endl;
  cout << sequenceSum(2, 2, 2) << "," << 2 << endl;
  cout << sequenceSum(2, 2, 1) << "," << 2 << endl;
  cout << sequenceSum(1, 15, 3) << "," << 35 << endl;
  cout << sequenceSum(15, 1, 3) << "," << 0 << endl;
}