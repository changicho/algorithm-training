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

// binary search & diff array
// time : O(N * log_2(K) + M)
// space : O(N)
class Solution {
 private:
  bool check(vector<int>& monsters, vector<long long> diffs, long long start) {
    int size = monsters.size();
    long long cur = start;
    long long diff = 0;
    for (int i = 0; i < size; i++) {
      diff += diffs[i];

      if (monsters[i] > cur + diff) return false;
      cur -= monsters[i];
      cur = max(cur, 0LL);
    }
    return true;
  }

 public:
  long long minInitialStrength(vector<int>& monsters,
                               vector<vector<int>>& boosts) {
    int size = monsters.size();

    long long left = 0, right = 50000000000001;

    vector<long long> diffs(size + 2, 0);
    for (vector<int>& b : boosts) {
      diffs[b[0]] += b[2];
      diffs[b[1] + 1] -= b[2];
    }

    long long answer = -1;
    while (left < right) {
      long long mid = left + (right - left) / 2;

      if (check(monsters, diffs, mid)) {
        // pick left

        answer = mid;
        right = mid;
      } else {
        // pick right
        left = mid + 1;
      }
    }

    return answer;
  }
};

// diff array & reverse
// time : O(N + M)
// space : O(N)
class Solution {
 public:
  long long minInitialStrength(vector<int>& monsters,
                               vector<vector<int>>& boosts) {
    int size = monsters.size();

    vector<long long> diffs(size + 2, 0);
    for (vector<int>& b : boosts) {
      diffs[b[1]] += b[2];
      if (b[0] - 1 >= 0) {
        diffs[b[0] - 1] -= b[2];
      }
    }

    long long answer = 0;
    long long diff = 0;
    for (int i = size - 1; i >= 0; i--) {
      diff += diffs[i];

      if (answer > 0) {
        answer += monsters[i];
      } else {
        answer = max(0LL, (long long)monsters[i] - diff);
      }
    }

    return answer;
  }
};
