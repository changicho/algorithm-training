#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use counting sort
// time : O(N + M)
// space : O(M)
class Solution {
 public:
  int minIncrementForUnique(vector<int>& nums) {
    int counts[100002] = {
        0,
    };
    for (int& num : nums) {
      counts[num]++;
    }

    int answer = 0;
    for (int num = 0; num <= 1e5; num++) {
      if (counts[num] > 1) {
        int move = counts[num] - 1;
        answer += move;
        counts[num + 1] += move;
        counts[num] = 1;
      }
    }
    if (counts[100001] > 0) {
      int num = counts[100001];

      answer += (num) * (num - 1) / 2;
    }

    return answer;
  }
};