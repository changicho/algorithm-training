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

// use bit count
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int bits[32] = {
        0,
    };

    for (int& num : nums) {
      for (int i = 0; i < 32; i++) {
        if (num & (1 << i)) {
          bits[i]++;
        }
      }
    }

    vector<int> answer;
    while (!nums.empty()) {
      int cur = 0;
      for (int i = 0; i < 32; i++) {
        if (bits[i] % 2 == 0 && i < maximumBit) {
          cur |= (1 << i);
        }
      }

      answer.push_back(cur);

      for (int i = 0; i < 32; i++) {
        if (nums.back() & (1 << i)) {
          bits[i]--;
        }
      }
      nums.pop_back();
    }

    return answer;
  }
};

// use prefix sum
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    vector<int> prefixes;

    int prefix = 0;
    for (int& num : nums) {
      prefix ^= num;

      prefixes.push_back(prefix);
    }

    vector<int> answer;
    while (!nums.empty()) {
      int prefix = prefixes.back();
      prefixes.pop_back();

      int cur = 0;
      for (int i = 0; i < 32; i++) {
        if ((prefix & (1 << i)) == 0 && i < maximumBit) {
          cur |= (1 << i);
        }
      }

      answer.push_back(cur);

      nums.pop_back();
    }

    return answer;
  }
};

// use xor
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int xors = 0;
    for (int& num : nums) {
      xors ^= num;
    }

    vector<int> answer;
    while (!nums.empty()) {
      int cur = 0;
      for (int i = 0; i < 32; i++) {
        if ((xors & (1 << i)) == 0 && i < maximumBit) {
          cur |= (1 << i);
        }
      }

      answer.push_back(cur);

      xors ^= nums.back();
      nums.pop_back();
    }

    return answer;
  }
};

// use xor with mask
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int xors = 0;
    for (int& num : nums) {
      xors ^= num;
    }
    int mask = (1 << maximumBit) - 1;

    vector<int> answer;
    while (!nums.empty()) {
      int cur = xors ^ mask;

      answer.push_back(cur);

      xors ^= nums.back();
      nums.pop_back();
    }

    return answer;
  }
};