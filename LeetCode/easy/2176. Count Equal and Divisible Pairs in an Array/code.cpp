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
 public:
  int countPairs(vector<int>& nums, int k) {
    int size = nums.size();
    int answer = 0;
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        if (nums[i] == nums[j] && (i * j) % k == 0) {
          answer++;
        }
      }
    }
    return answer;
  }
};