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

// one pass
// time : O(N)
// space : O(M)
class Solution {
 public:
  int countSpecialIntegers(vector<int>& nums) {
    int visitedCount[101] = {
        0,
    };

    int before = nums[0];

    nums.push_back(INT_MAX);

    int answer = 0;
    for (int& num : nums) {
      if (before == num) continue;

      visitedCount[before]++;
      if (visitedCount[before] == 1) {
        answer++;
      } else if (visitedCount[before] == 2) {
        answer--;
      }

      before = num;
    }

    return answer;
  }
};

// one pass (boolean)
// time : O(N)
// space : O(M)
class Solution {
 public:
  int countSpecialIntegers(vector<int>& nums) {
    bool visited[101] = {
        false,
    };
    bool duplicated[101] = {
        false,
    };

    int before = nums[0];

    nums.push_back(INT_MAX);

    int answer = 0;
    for (int& num : nums) {
      if (before == num) continue;

      if (visited[before]) {
        if (!duplicated[before]) {
          answer--;
        }
        duplicated[before] = true;
      } else {
        answer++;
        visited[before] = true;
      }

      before = num;
    }

    return answer;
  }
};