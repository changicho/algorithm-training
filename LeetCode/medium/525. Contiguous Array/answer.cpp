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
  int findMaxLength(vector<int>& nums) {
    int size = nums.size();
    int answer = 0;

    // key : diff of 1,0
    // value : first index
    unordered_map<int, int> appears;
    appears[0] = -1;

    int diff = 0;
    for (int i = 0; i < size; i++) {
      int& num = nums[i];
      if (num == 0) {
        diff--;
      } else {
        diff++;
      }

      if (appears.count(diff)) {
        answer = max(answer, i - appears[diff]);
      } else {
        appears[diff] = i;
      }
    }

    return answer;
  }
};