#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int size = arr.size();

    int left = 0, right = size;
    int answerIdx = 0;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (arr[mid] > arr[mid - 1]) {
        answerIdx = mid;
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return answerIdx;
  }
};