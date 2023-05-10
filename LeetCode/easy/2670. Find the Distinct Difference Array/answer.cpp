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
  vector<int> distinctDifferenceArray(vector<int>& nums) {
    int size = nums.size();

    unordered_map<int, int> suffix, prefix;
    for (int i = 0; i < size; i++) {
      suffix[nums[i]]++;
    }

    vector<int> answer(size);

    for (int i = 0; i < size; i++) {
      int num = nums[i];

      prefix[num]++;
      suffix[num]--;

      if (suffix[num] == 0) suffix.erase(num);

      answer[i] = (prefix.size() - suffix.size());
    }

    return answer;
  }
};