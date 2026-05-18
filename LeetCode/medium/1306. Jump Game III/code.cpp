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
  bool canReach(vector<int>& arr, int start) {
    int size = arr.size();

    vector<bool> visited(size);

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      if (arr[cur] == 0) return true;

      int prev = cur - arr[cur];
      int next = cur + arr[cur];

      if (prev >= 0 && !visited[prev]) {
        q.push(prev);
        visited[prev] = true;
      }
      if (next < size && !visited[next]) {
        q.push(next);
        visited[next] = true;
      }
    }

    return false;
  }
};