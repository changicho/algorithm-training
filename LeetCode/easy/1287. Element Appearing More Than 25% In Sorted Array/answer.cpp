#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two pointer
// time : O(N)
// space : O(1)
class Solution {
 public:
  int findSpecialInteger(vector<int>& arr) {
    int size = arr.size();

    for (int right = 0, left = 0; right < size; right++) {
      while (left < right && arr[left] != arr[right]) {
        left++;
      }

      int count = right - left + 1;
      if (count > size / 4) return arr[right];
    }
    return -1;
  }
};

// use binary search
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  int findSpecialInteger(vector<int>& arr) {
    int size = arr.size();
    vector<int> candidates = {arr[size / 4], arr[size / 2], arr[3 * size / 4]};

    for (int& candidate : candidates) {
      int count = upper_bound(arr.begin(), arr.end(), candidate) -
                  lower_bound(arr.begin(), arr.end(), candidate);

      if (count > size / 4) {
        return candidate;
      }
    }

    return -1;
  }
};