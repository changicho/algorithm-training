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

// use hash map
// time : O(N)
// space : O(N)
class Solution {
 public:
  int countTrapezoids(vector<vector<int>>& points) {
    const int MOD = 1e9 + 7;
    unordered_map<int, long long> um;

    for (vector<int>& p : points) {
      int x = p[0], y = p[1];

      um[y]++;
    }

    long long answer = 0;
    long long caseSum = 0;
    for (auto& [_, count] : um) {
      long long cur = (count) * (count - 1) / 2;

      answer += cur * caseSum;
      caseSum += cur;
    }

    return answer % MOD;
  }
};

// use hash map & two pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  int countTrapezoids(vector<vector<int>>& points) {
    const int MOD = 1e9 + 7;
    unordered_map<int, long long> um;

    for (vector<int>& p : points) {
      int x = p[0], y = p[1];

      um[y]++;
    }

    long long caseSum = 0;
    for (auto& [_, count] : um) {
      long long cur = (count) * (count - 1) / 2;

      caseSum += cur;
    }

    long long answer = 0;
    for (auto& [_, count] : um) {
      long long cur = (count) * (count - 1) / 2;
      answer += cur * (caseSum - cur);
    }

    return (answer / 2) % MOD;
  }
};