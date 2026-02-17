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

// brute force
// time : O(N^2 + M)
// space : O(M)
class Solution {
 public:
  int longestBalanced(vector<int>& nums) {
    int size = nums.size();

    int answer = 0;
    bool visited[100001] = {
        0,
    };

    for (int left = 0; left < size; left++) {
      memset(visited, false, sizeof(visited));
      int oddCount = 0;
      int evenCount = 0;

      for (int right = left; right < size; right++) {
        int cur = nums[right];
        if (cur % 2 == 1) {
          if (visited[cur] == false) oddCount++;
          visited[cur] = true;
        } else {
          if (visited[cur] == false) evenCount++;
          visited[cur] = true;
        }

        if (oddCount == evenCount) {
          answer = max(answer, right - left + 1);
        }
      }
    }
    return answer;
  }
};

// brute force & hash set
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int longestBalanced(vector<int>& nums) {
    int size = nums.size();

    int answer = 0;
    unordered_set<int> us;

    for (int left = 0; left < size; left++) {
      us.clear();
      int oddCount = 0, evenCount = 0;

      for (int right = left; right < size; right++) {
        int cur = nums[right];

        if (us.count(cur) == 0) {
          if (cur % 2 == 1) {
            evenCount++;
          } else {
            oddCount++;
          }
          us.insert(cur);
        }

        if (oddCount == evenCount) {
          answer = max(answer, right - left + 1);
        }
      }
    }
    return answer;
  }
};