#include <iostream>
#include <array>

using namespace std;

/* Third parameter for memoization of recursive function */
unsigned long long combination(unsigned int n, unsigned int k, array<array<unsigned long long, 500>, 500>& combinations)
{
  if (n == k || k == 0) // Represents first and last number of pascal's triangle row, which is always 1
    return 1;
  if (combinations[n][k] != 0) // Grab from memo if already computed
    return combinations[n][k];
  combinations[n][k] = combination(n-1, k-1, combinations) + combination(n-1, k, combinations); // Recursive formula, store the result in memo
  return combinations[n][k];
}

unsigned long long total_inc_dec(unsigned int n)
{
  /* Init memo array */
  array<array<unsigned long long, 500>, 500> combinations;
  for (int i = 0; i < 500; i++)
    combinations[i].fill(0);
  
  /* Formula for number of nonbouncy numbers below 10^n */
  return combination(n + 9, n, combinations) + (n + 1) * combination(n + 10, n + 1, combinations) / 10 - 10 * n - 1;
}

int main()
{
  cout << total_inc_dec(1) << ", " << 10 << endl;
  cout << total_inc_dec(2) << ", " << 100 << endl;
  cout << total_inc_dec(3) << ", " << 475 << endl;
  cout << total_inc_dec(4) << ", " << 1675 << endl;
}