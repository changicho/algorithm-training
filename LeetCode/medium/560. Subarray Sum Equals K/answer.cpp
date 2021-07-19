#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use hash map

class Solution {
 public:
  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    m[0] = 1;

    int answer = 0;
    int sum = 0;

    for (int &num : nums) {
      sum += num;
      if (m.count(sum - k)) {
        answer += m[sum - k];
      }
      m[sum] += 1;
    }

    return answer;
  }
};