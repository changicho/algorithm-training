#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int guess(int num);

// use binary search
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  int guessNumber(int n) {
    if (guess(n) == 0) return n;

    long left = 0, right = n;
    while (left < right) {
      int mid = left + (right - left) / 2;

      int result = guess(mid);
      if (result == 1) {
        // pick right
        left = mid + 1;
      } else {
        // pick left
        right = mid;
      }
    }

    return left;
  }
};