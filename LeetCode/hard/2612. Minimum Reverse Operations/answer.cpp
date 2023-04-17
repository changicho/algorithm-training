#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use set BFS with range move
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  pair<int, int> getRange(int n, int pivot, int k) {
    int l1 = max(0, pivot - k + 1);
    int r1 = l1 + k - 1;

    int r2 = min(n - 1, pivot + k - 1);
    int l2 = r2 - k + 1;

    int left = r1 - (pivot - l1);
    int right = l2 + (r2 - pivot);
    return {left, right};
  }

 public:
  vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
    vector<int> answer(n, INT_MAX);

    for (int& ban : banned) {
      answer[ban] = -1;
    }

    // k == 2 : +1
    // k == 3 : +0 +2
    // k == 4 : +1, +3
    // k == 5 : +0 +2 +4

    // range left ~ right, move cur
    // left <= cur <= right
    // next = right - (cur - left);

    set<int> indexes[2];
    for (int i = 0; i < n; i++) {
      if (answer[i] == -1) continue;
      indexes[i % 2].insert(i);
    }

    int step = 0;
    queue<int> q;
    q.push(p);

    answer[p] = 0;

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        int cur = q.front();
        q.pop();

        pair<int, int> range = getRange(n, cur, k);

        int leftFar = range.first, rightFar = range.second;
        int isOdd = (cur % 2 + ((k + 1) % 2)) % 2;

        auto leftIt = indexes[isOdd].lower_bound(leftFar);
        auto rightIt = indexes[isOdd].upper_bound(rightFar);

        for (auto it = leftIt; it != rightIt; it++) {
          int next = *it;

          if (answer[next] != INT_MAX) continue;
          answer[next] = step + 1;
          q.push(next);
        }

        indexes[isOdd].erase(leftIt, rightIt);
      }

      step++;
    }

    for (int i = 0; i < n; i++) {
      if (answer[i] == INT_MAX) {
        answer[i] = -1;
      }
    }
    return answer;
  }
};