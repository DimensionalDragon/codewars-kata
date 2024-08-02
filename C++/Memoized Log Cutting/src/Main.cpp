#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Your new function as given to you by me, your boss.
int cut_log(const vector<int>& p, int n){
  // Some array to store calculated values
  int dp[100] = {0};
  for(int j = 1 ; j <= n ; j++){
    for(int i = 1 ; i <= j ; i++){ // Two nested loops = Θ(n^2)
      dp[j] = max(dp[j], p[i] + dp[j - i]);
    }
  }
  return dp[n]; // Good luck intern!
}

int main()
{
  std::vector<int> p({ 0,   1,   5,   8,   9,  10,  17,  17,  20,  24, // 0X's
                      30,  32,  35,  39,  43,  43,  45,  49,  50,  54, // 1X's
                      57,  60,  65,  68,  70,  74,  80,  81,  84,  85, // 2X's
                      87,  91,  95,  99, 101, 104, 107, 112, 115, 116, // 3X's
                      119, 121, 125, 129, 131, 134, 135, 140, 143, 145, // 4X's
                      151}); // 50th element

  cout << cut_log(p, 1) << ", " << 1 << endl;
  cout << cut_log(p, 5) << ", " << 13 << endl;
  cout << cut_log(p, 8) << ", " << 22 << endl;
  cout << cut_log(p, 10) << ", " << 30 << endl;
  cout << cut_log(p, 22) << ", " << 65 << endl;
}