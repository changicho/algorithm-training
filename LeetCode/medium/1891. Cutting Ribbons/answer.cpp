#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search

class Solution {
 private:
  bool canMake(vector<int> &ribbons, int length, int k) {
    int count = 0;

    for (int &r : ribbons) {
      count += r / length;
    }

    return count >= k;
  }

 public:
  int maxLength(vector<int> &ribbons, int k) {
    int maximum = 0;
    for (int &r : ribbons) {
      maximum = max(r, maximum);
    }

    int answer = 0;

    int left = 1, right = maximum + 1;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (canMake(ribbons, mid, k)) {
        // pick right
        answer = mid;
        left = mid + 1;
      } else {
        // pick left
        right = mid;
      }
    }

    return answer;
  }
};