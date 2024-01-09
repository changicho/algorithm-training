#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  int missingInteger(vector<int>& nums) {
    int size = nums.size();

    int visited[51] = {
        0,
    };
    for (int& num : nums) {
      visited[num] = true;
    }

    int prefix = nums[0];
    for (int j = 1; j < size; j++) {
      if (nums[j] - nums[j - 1] == 1) {
        prefix += nums[j];
      } else {
        break;
      }
    }

    int answer = prefix;
    while (answer <= 50 && visited[answer]) {
      answer++;
    }
    return answer;
  }
};