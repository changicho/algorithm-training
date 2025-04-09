#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use count & one pass
// time : O(N)
// space : O(M)
class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    int size = nums.size();
    int counts[101] = {
        0,
    };

    int overCount = 0;
    for (int& num : nums) {
      counts[num]++;
      if (counts[num] == 2) overCount++;
    }

    int answer = 0;
    for (int i = 0; i < size; i += 3) {
      if (overCount == 0) break;

      answer++;
      for (int j = 0; j < 3; j++) {
        if (i + j >= size) break;
        int num = nums[i + j];
        counts[num]--;
        if (counts[num] == 1) overCount--;
      }
    }
    return answer;
  }
};