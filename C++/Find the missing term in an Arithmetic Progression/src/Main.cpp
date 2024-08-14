#include <iostream>
#include <vector>

using namespace std;

long findMissing(std::vector<long> list)
{
  int n = list.size();
  int d = (list.back() - list[0]) / n;
  for (int i = 0; i < n - 1; i++)
  {
    if (list[i] + d != list[i + 1])
      return list[i] + d;
  }
}

int main()
{
  cout << findMissing({1, 3, 4}) << ", " << 2 << endl;
}