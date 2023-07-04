#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash map, set
// time : O(N)
// space : O(N)
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    unordered_map<int, int> m;
    unordered_set<int> s;

    for (int num : nums) {
      if (m[num] == 0) {
        m[num] += 1;
        s.insert(num);
      } else {
        s.erase(num);
      }
    }

    return *s.begin();
  }
};

// use bit operation
// time : O(N)
// space : O(1)
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int one = 0, two = 0, three = 0;

    for (int num : nums) {
      two ^= one & num;
      one ^= num;

      three = ~(one & two);

      two &= three;
      one &= three;
    }

    return one;
  }
};

// use bit operation (other)
// time : O(N)
// space : O(1)
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int one = 0, two = 0, three = 0;

    for (int num : nums) {
      two |= one & num;
      one ^= num;

      three = one & two;

      one ^= three;
      two ^= three;
    }

    return one;
  }
};

// use bit mask
// time : O(N)
// space : O(1)
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int answer = 0;

    for (int i = 0; i < 32; i++) {
      int sum = 0;
      int mask = 1 << i;

      for (int num : nums) {
        if (num & mask) {
          sum++;
        }
      }

      if (sum % 3 == 1) {
        answer |= mask;
      }
    }

    return answer;
  }
};

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int size = nums.size();

    for (int i = 0; i < size; i++) {
      bool leftDiff = false, rightDiff = false;
      if (i - 1 < 0) {
        leftDiff = true;
      } else {
        leftDiff = nums[i - 1] != nums[i];
      }
      if (i + 1 >= size) {
        rightDiff = true;
      } else {
        rightDiff = nums[i] != nums[i + 1];
      }

      if (leftDiff && rightDiff) {
        return nums[i];
      }
    }
    return 0;
  }
};