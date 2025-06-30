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

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<int> maxSubsequence(vector<int> &nums, int k) {
    int size = nums.size();

    vector<pair<int, int>> arr;
    for (int i = 0; i < size; i++) {
      arr.push_back({nums[i], i});
    }

    sort(arr.begin(), arr.end(), greater<pair<int, int>>());

    sort(arr.begin(), arr.begin() + k,
         [](auto &a, auto &b) { return a.second < b.second; });

    vector<int> answer;

    for (int i = 0; i < k; i++) {
      answer.push_back(arr[i].first);
    }

    return answer;
  }
};