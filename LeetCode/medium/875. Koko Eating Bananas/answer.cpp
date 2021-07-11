#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search

class Solution {
 private:
  int calculateHour(vector<int>& piles, int k) {
    int curH = 0;
    for (int pile : piles) {
      curH += ceil((double)pile / k);
    }
    return curH;
  }

 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    int answer = 0;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (calculateHour(piles, mid) <= h) {
        answer = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return answer;
  }
};