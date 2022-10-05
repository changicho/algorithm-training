#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use hash map
// time : O(N)
// space : O(N)
class Solution {
 public:
  int findPairs(vector<int> &nums, int k) {
    unordered_map<int, int> counts;

    for (int &num : nums) {
      counts[num]++;
    }

    int answer = 0;
    for (auto &it : counts) {
      int key = it.first, val = it.second;

      if (k == 0) {
        if (2 <= val) {
          answer++;
        }
        continue;
      }

      if (counts.count(key + k) > 0) {
        answer++;
      }
    }

    return answer;
  }
};