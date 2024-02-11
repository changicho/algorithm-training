#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use math
// time : O(1)
// space : O(1)
class Solution {
 public:
  long long flowerGame(int n, int m) {
    long long oddY = 0, oddX = 0, evenY = 0, evenX = 0;

    evenX = n / 2;
    oddX = n % 2 == 0 ? evenX : evenX + 1;
    evenY = m / 2;
    oddY = m % 2 == 0 ? evenY : evenY + 1;

    return oddX * evenY + evenX * oddY;
  }
};