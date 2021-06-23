#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash map, set

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
