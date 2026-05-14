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

// greedy
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int minimumEffort(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(), [&](vector<int>& a, vector<int>& b) {
      return a[1] - a[0] < b[1] - b[0];
    });

    int answer = 0;
    for (vector<int>& task : tasks) {
      answer = max(answer + task[0], task[1]);
    }
    return answer;
  }
};