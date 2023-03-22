#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int size = flowerbed.size();

    int planted = 0;
    for (int i = 0; i < size; i++) {
      if (flowerbed[i] == 1) continue;

      bool isPossible = true;
      if (i - 1 >= 0 && flowerbed[i - 1] == 1) isPossible = false;
      if (i + 1 < size && flowerbed[i + 1] == 1) isPossible = false;

      if (isPossible) {
        flowerbed[i] = 1;
        planted++;
      }
    }

    return planted >= n;
  }
};