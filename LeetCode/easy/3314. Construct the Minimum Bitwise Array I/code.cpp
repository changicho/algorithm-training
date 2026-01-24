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

// use bit math
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> minBitwiseArray(vector<int>& nums) {
    int size = nums.size();

    vector<int> answer(size);
    for (int i = 0; i < size; i++) {
      int x = nums[i];
      int res = -1;
      int d = 1;
      while ((x & d) != 0) {
        res = x - d;
        d <<= 1;
      }

      answer[i] = res;
    }
    return answer;
  }
};

// use brute force
// time : O(N * M)
// space : O(N)
class Solution {
 public:
  vector<int> minBitwiseArray(vector<int>& nums) {
    int size = nums.size();

    vector<int> answer(size, -1);
    for (int i = 0; i < size; i++) {
      for (int num = 0; num <= 1000; num++) {
        if ((num | (num + 1)) == nums[i]) {
          answer[i] = num;
          break;
        }
      }
    }
    return answer;
  }
};