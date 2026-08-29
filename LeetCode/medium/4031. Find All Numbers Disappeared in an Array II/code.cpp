#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// sort & one pass
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                             int upper) {
    vector<vector<int>> answer;

    sort(nums.begin(), nums.end());

    int size = nums.size();

    int before = lower;

    for (int i = 0; i < size; i++) {
      int& num = nums[i];
      if (num > upper) break;
      if (before > num) {
        continue;
      }

      if (before != num) {
        answer.push_back({before, num - 1});
      }
      before = num + 1;
    }

    if (before <= upper) {
      answer.push_back({before, upper});
    }
    return answer;
  }
};

// count
// time : O(N + M)
// space : O(M)
class Solution {
 public:
  vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                             int upper) {
    vector<vector<int>> answer;

    bool visited[100001] = {
        false,
    };
    for (int& num : nums) {
      visited[num] = true;
    }

    int before = lower;
    for (int i = lower; i <= upper; i++) {
      if (!visited[i]) {
        continue;
      }

      if (before < i) {
        answer.push_back({before, i - 1});
      }
      before = i + 1;
    }

    if (before <= upper) {
      answer.push_back({before, upper});
    }

    return answer;
  }
};