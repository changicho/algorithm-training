#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
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
  int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    int size = reward1.size();

    vector<pair<int, int>> nums;
    for (int i = 0; i < size; i++) {
      nums.push_back({reward1[i], reward2[i]});
    }

    sort(nums.begin(), nums.end(), [](auto& a, auto& b) {
      return (a.first - a.second) > (b.first - b.second);
    });

    int answer = 0;
    for (int i = 0; i < k; i++) {
      answer += nums[i].first;
    }
    for (int i = k; i < size; i++) {
      answer += nums[i].second;
    }
    return answer;
  }
};