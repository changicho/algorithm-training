#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use hash map
// time : O(N)
// space : O(N)
class Solution {
 public:
  int numIdenticalPairs(vector<int> &nums) {
    int answer = 0;
    unordered_map<int, int> um;

    for (int &num : nums) {
      um[num]++;
    }

    for (auto &[key, val] : um) {
      answer += (val * (val - 1)) / 2;
    }
    return answer;
  }
};