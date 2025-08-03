#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  vector<int> smallestSubarrays(vector<int>& nums) {
    int size = nums.size();
    vector<int> target(size);
    for (int i = size - 1, bit = 0; i >= 0; i--) {
      bit |= nums[i];

      target[i] = bit;
    }

    int bits[32] = {
        0,
    };

    function<int(void)> convert = [&]() {
      int bit = 0;
      for (int i = 0; i < 32; i++) {
        if (bits[i] > 0) {
          bit |= (1 << i);
        }
      }
      return bit;
    };

    vector<int> answer(size);
    for (int left = size - 1, right = size - 1; left >= 0; left--) {
      for (int i = 0; i < 32; i++) {
        if (nums[left] & (1 << i)) {
          bits[i]++;
        }
      }

      while (left < right && convert() == target[left]) {
        for (int i = 0; i < 32; i++) {
          if (nums[right] & (1 << i)) {
            bits[i]--;
          }
        }
        right--;
      }
      if (right < size - 1 && convert() != target[left]) {
        right++;
        for (int i = 0; i < 32; i++) {
          if (nums[right] & (1 << i)) {
            bits[i]++;
          }
        }
      }

      answer[left] = right - left + 1;
    }
    return answer;
  }
};

// use sliding window
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> smallestSubarrays(vector<int>& nums) {
    int size = nums.size();

    vector<int> lastPositions(31, -1);
    vector<int> answer(size);
    for (int i = size - 1; i >= 0; --i) {
      int last = i;

      for (int bit = 0; bit < 31; ++bit) {
        if (!(nums[i] & (1 << bit))) {
          if (lastPositions[bit] != -1) {
            last = max(last, lastPositions[bit]);
          }
        } else {
          lastPositions[bit] = i;
        }
      }
      answer[i] = last - i + 1;
    }
    return answer;
  }
};