#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search

class Solution {
 private:
  bool canShip(vector<int>& weights, int days, int capacity) {
    int curW = 0, spent = 1;
    for (int& w : weights) {
      if (w > capacity) return false;

      if (curW + w > capacity) {
        spent += 1;
        curW = 0;
      }

      curW += w;
    }

    if (spent <= days) return true;
    return false;
  }

 public:
  int shipWithinDays(vector<int>& weights, int days) {
    int sum = 0, maxW = 0;
    for (int& w : weights) {
      sum += w;
      maxW = max(w, maxW);
    }

    int left = maxW, right = sum;

    int answer = sum;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (canShip(weights, days, mid)) {
        // pick left
        answer = mid;
        right = mid;
      } else {
        // pick right
        left = mid + 1;
      }
    }

    return answer;  // return right;
  }
};