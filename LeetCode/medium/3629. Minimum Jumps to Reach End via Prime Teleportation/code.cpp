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

// use BFS by step
// time : O(M * log_2(M) + N * log_2(M))
// space : O(N + M)
vector<int> factors[1000001];

bool init = [] {
  for (int i = 2; i <= 1000000; i++) {
    if (factors[i].size() > 0) continue;

    for (int j = i; j <= 1000000; j += i) {
      factors[j].push_back(i);
    }
  }
  return true;
}();

class Solution {
 public:
  int minJumps(vector<int>& nums) {
    int size = nums.size();
    unordered_map<int, vector<int>> primeIndexes;
    for (int i = 0; i < size; i++) {
      int cur = nums[i];

      // prime
      if (factors[cur].size() == 1) {
        primeIndexes[cur].push_back(i);
      }
    }

    vector<bool> visited(size, false);

    queue<int> q;
    visited[size - 1] = true;
    int step = 0;
    q.push(size - 1);

    while (!q.empty()) {
      int qSize = q.size();

      while (qSize--) {
        int i = q.front();
        q.pop();
        int cur = nums[i];

        if (i == 0) return step;

        if (i + 1 < size && !visited[i + 1]) {
          visited[i + 1] = true;
          q.push(i + 1);
        }
        if (i - 1 >= 0 && !visited[i - 1]) {
          visited[i - 1] = true;
          q.push(i - 1);
        }

        for (int& p : factors[cur]) {
          if (primeIndexes.count(p)) {
            for (int& n : primeIndexes[p]) {
              if (!visited[n]) {
                visited[n] = true;
                q.push(n);
              }
            }
            primeIndexes[p].clear();
          }
        }
      }

      step++;
    }

    return size - 1;
  }
};