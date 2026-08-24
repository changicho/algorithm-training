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

// BFS
// time : O(N)
// space : O(N)
class Solution {
 public:
  long long weightedSum(vector<int>& parent, vector<int>& nums) {
    int size = parent.size();
    vector<vector<int>> graph(size + 1);

    long long sum = nums[0];
    for (int i = 1; i < size; i++) {
      sum += nums[i];

      int p = parent[i];

      graph[p].push_back(i);
    }

    long long answer = 0;
    queue<int> q;
    q.push(0);
    long long d = 1;
    while (!q.empty()) {
      int qSize = q.size();

      while (qSize--) {
        int cur = q.front();
        q.pop();

        answer += nums[cur] - nums[cur] * d;
        for (int& c : graph[cur]) {
          q.push(c);
        }
      }

      d++;
    }

    answer += sum * (d - 1);
    return answer;
  }
};