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

// use count
// time : O(N)
// space : O(M)
class Solution {
 public:
  int largestUniqueNumber(vector<int> &nums) {
    int counts[1001] = {
        0,
    };
    int answer = -1;
    for (int &num : nums) {
      counts[num]++;
    }

    for (int &num : nums) {
      if (counts[num] == 1) {
        answer = max(answer, num);
      }
    }
    return answer;
  }
};