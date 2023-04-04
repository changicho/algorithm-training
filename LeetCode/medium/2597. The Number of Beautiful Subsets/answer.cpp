#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use brute force & backtracking
// time : O(2^N)
// space : O(N)
class Solution {
 private:
  int answer = 0;
  vector<int> nums;
  int k;

  int visited[1001];

  void recursive(int index) {
    if (index == nums.size()) {
      answer++;
      return;
    }

    // not pick cur
    recursive(index + 1);

    int num = nums[index];
    if ((num - k < 0 || visited[num - k] == 0) &&
        (num + k > 1000 || visited[num + k] == 0)) {
      visited[num]++;
      recursive(index + 1);
      visited[num]--;
    }
  }

 public:
  int beautifulSubsets(vector<int>& nums, int k) {
    this->nums = nums;
    this->k = k;

    recursive(0);

    return answer - 1;
  }
};