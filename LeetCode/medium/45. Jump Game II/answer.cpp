#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// dp

class Solution {
 public:
  int jump(vector<int>& nums) {
    int size = nums.size();
    vector<int> leastJumps(size, 10000);
    leastJumps[0] = 0;

    for (int from = 0; from < size; from++) {
      int reach = nums[from];

      int limit = min(size, from + reach + 1);
      for (int to = from + 1; to < limit; to++) {
        leastJumps[to] = min(leastJumps[to], leastJumps[from] + 1);
      }
    }

    return leastJumps.back();
  }
};

// greedy

class Solution {
 public:
  int jump(vector<int>& nums) {
    int size = nums.size();
    int answer = 0;

    int position = 0;
    int next = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      next = max(next, i + nums[i]);

      if (position == i) {
        answer++;
        position = next;
      }
    }
    return answer;
  }
};
