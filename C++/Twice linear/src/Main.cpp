#include <iostream>
#include <vector>

using namespace std;

int dblLinear(int n)
{
  int LIMIT = 1000000;
  vector<int> sequence(LIMIT); // Create container for the sequence

  int doublePlusOneIndex = 0, triplePlusOneIndex = 0; // Index that points to the last numbers generated, both start at 0
  int doublePlusOne = 1, triplePlusOne = 1; // Latest numbers generated

  for ( int i = 0; i < LIMIT; i++ ) // Generate the sequence
  {
    /* Determine the minimum,
    if the latest 2n + 1 and 3n + 1 are the same, generate both,
    otherwise generate only the smaller value.
    This will ensure that they are sorted without the need to sort again */
    int minimum = (doublePlusOne <= triplePlusOne) ? doublePlusOne : triplePlusOne;
    if (doublePlusOne == minimum)
    {
      sequence[i] = doublePlusOne; // Save the value at the back of array
      doublePlusOne = sequence[doublePlusOneIndex] * 2 + 1; // Generate the next 2n + 1 number
      doublePlusOneIndex++; // Move the index to the next number to generate more 2n + 1 numbers
    }
    if (triplePlusOne == minimum)
    {
      sequence[i] = triplePlusOne; // Save the value at the back of array
      triplePlusOne = sequence[triplePlusOneIndex] * 3 + 1; // Generate the next 3n + 1 number
      triplePlusOneIndex++; // Move the index to the next number to generate more 3n + 1 numbers
    }
  }

  return sequence[n]; // Once generated, just return the n-th value 
}

int main()
{
	cout << dblLinear(10) << ", " << 22 << endl;
	cout << dblLinear(20) << ", " << 57 << endl;
	cout << dblLinear(30) << ", " << 91 << endl;
	cout << dblLinear(50) << ", " << 175 << endl;
}