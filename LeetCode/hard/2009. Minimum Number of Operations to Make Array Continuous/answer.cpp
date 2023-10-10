#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use sort & sliding window
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());

    int target = size - 1;
    int answer = size;

    queue<int> q;
    unordered_map<int, int> counts;
    int duplicated = 0;
    for (int& num : nums) {
      while (!q.empty() && num - q.front() > target) {
        int key = q.front();
        if (counts[key] > 1) duplicated--;
        counts[key]--;
        if (counts[key] == 0) counts.erase(key);
        q.pop();
      }

      q.push(num);
      if (counts[num] > 0) duplicated++;
      counts[num]++;

      int curCost = size - q.size() + duplicated;

      answer = min(curCost, answer);
    }
    return answer;
  }
};