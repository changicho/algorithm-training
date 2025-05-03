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

// use binary search & greedy
// time : O(N * log_2(N) + M * log_2(M))
// space : O(N + M)
class Solution {
 private:
  bool check(int mid, vector<int>& tasks, vector<int>& workers, int pills,
             int strength) {
    int used = 0;

    multiset<int> workerSet(workers.end() - mid, workers.end());

    for (int i = mid - 1; i >= 0; i--) {
      auto strongest = prev(workerSet.end());
      if (*strongest >= tasks[i]) {
        workerSet.erase(strongest);
        continue;
      }

      auto target = workerSet.lower_bound(tasks[i] - strength);
      used++;
      if (target == workerSet.end() || used > pills) {
        return false;
      }

      workerSet.erase(target);
    }
    return true;
  }

 public:
  int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                    int strength) {
    int taskSize = tasks.size();
    int workerSize = workers.size();
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());

    int answer = 0;
    int left = 1, right = min(workerSize, taskSize);
    while (left <= right) {
      int mid = (left + right) / 2;

      if (check(mid, tasks, workers, pills, strength)) {
        answer = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return answer;
  }
};