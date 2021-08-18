#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search

class Solution {
 public:
  bool isBadVersion(int version);

  int firstBadVersion(int n) {
    int left = 1, right = n, mid;
    while (left <= right) {
      mid = left + (right - left) / 2;

      if (isBadVersion(mid)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
};