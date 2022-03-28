#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use hash set
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool divideArray(vector<int>& nums) {
    // total O(500) = O(1)
    unordered_set<int> us;

    // O(N)
    for (int& num : nums) {
      if (us.count(num) > 0) {
        us.erase(num);
      } else {
        us.insert(num);
      }
    }

    return us.size() == 0;
  }
};

// use count array
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool divideArray(vector<int>& nums) {
    // O(500) = O(1)
    int counts[501] = {
        0,
    };

    // O(N)
    for (int& n : nums) {
      counts[n]++;
    }

    // O(500) = O(1)
    for (int c = 1; c <= 500; c++) {
      if (counts[c] % 2 == 1) return false;
    }

    return true;
  }
};