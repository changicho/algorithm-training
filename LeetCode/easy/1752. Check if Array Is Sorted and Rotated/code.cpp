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

// use brute force
// time : O(N^2)
// space : O(1)
class Solution {
 private:
  bool isSorted(vector<int>& nums, int index) {
    int size = nums.size();
    for (int i = 0; i < size - 1; i++) {
      int nI = (i + 1) % size;

      if (nums[(index + i) % size] > nums[(index + nI) % size]) return false;
    }
    return true;
  }

 public:
  bool check(vector<int>& nums) {
    int size = nums.size();
    int minI = 0;

    for (int i = 0; i < size; i++) {
      if (isSorted(nums, i)) return true;
    }
    return false;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool check(vector<int>& nums) {
    int size = nums.size();
    int inverted = 0;

    for (int i = 0; i < size; i++) {
      int nI = (i + 1) % size;

      if (nums[nI] < nums[i]) inverted++;
    }

    return inverted <= 1;
  }
};