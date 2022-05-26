#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use BFS
// time : O(log_2(N))
// space : O(log_2(N))
class Solution {
 public:
  int integerReplacement(int n) {
    int count = 0;

    unordered_set<long> us;
    us.insert(n);

    queue<long> q;
    q.push(n);

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        long cur = q.front();
        q.pop();

        if (cur == 1) return count;

        if (cur % 2 == 0 && us.count(cur / 2) == 0) {
          q.push(cur / 2);
          us.insert(cur / 2);
        }
        if (cur % 2 == 1 && us.count(cur - 1) == 0) {
          q.push(cur - 1);
          us.insert(cur - 1);
        }
        if (cur % 2 == 1 && us.count(cur + 1) == 0) {
          q.push(cur + 1);
          us.insert(cur + 1);
        }
      }
      count++;
    }

    return count;
  }
};