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

// count pair
// time : O(N + M)
// space : O(N + M)
class Solution {
 public:
  int maxEqualAdjacentPairs(vector<int>& nums) {
    unordered_map<int, unordered_map<int, int>> nextCount;

    unordered_map<int, vector<int>> nexts;

    int size = nums.size();
    int alreadySame = 0;
    for (int i = 0; i < size - 1; i++) {
      if (nums[i] == nums[i + 1]) {
        alreadySame++;
      } else {
        nextCount[nums[i]][nums[i + 1]]++;
        nexts[nums[i]].push_back(nums[i + 1]);
      }
    }

    int answer = alreadySame;
    for (auto& [num, nexts] : nexts) {
      for (int& next : nexts) {
        answer = max(answer,
                     nextCount[num][next] + nextCount[next][num] + alreadySame);
      }
    }

    return answer;
  }
};

// count pair
// time : O(N)
// space : O(N)
class Solution {
 public:
  int maxEqualAdjacentPairs(vector<int>& nums) {
    int alreadySame = 0;
    int sameMax = 0;

    unordered_map<long long, int> count;

    int size = nums.size();

    for (int i = 0; i < size - 1; i++) {
      int a = min(nums[i], nums[i + 1]), b = max(nums[i], nums[i + 1]);

      if (a == b) {
        alreadySame++;
      } else {
        long long key = ((long long)a << 32) + b;
        count[key]++;
        sameMax = max(sameMax, count[key]);
      }
    }
    return alreadySame + sameMax;
  }
};