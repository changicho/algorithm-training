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

// heap
// time : O((N + H) * log_2(N))
// space : O(N)
class Solution {
 private:
  struct Status {
    long long val;
    long long origin;
    int step;

    bool operator<(const Status& b) const { return val > b.val; }
  };

 public:
  long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    long long answer = 0;

    int size = workerTimes.size();

    priority_queue<Status> pq;
    for (int& worker : workerTimes) {
      pq.push({worker, worker, 1});
    }

    while (mountainHeight > 0) {
      mountainHeight--;

      Status cur = pq.top();
      pq.pop();

      answer = cur.val;

      pq.push(
          {cur.val + cur.origin * (cur.step + 1), cur.origin, cur.step + 1});
    }

    return answer;
  }
};

// binary search
// time : O(N * log_2(M * H^2))
// space : O(1)
class Solution {
 private:
  long long calc(long long time, vector<int>& workerTimes) {
    double eps = 1e-7;
    long long ret = 0;
    for (int& worker : workerTimes) {
      long long work = time / worker;
      ret += (-1.0 + sqrt(1 + work * 8)) / 2 + eps;
    }
    return ret;
  }

 public:
  long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    int size = workerTimes.size();

    int maximum = *max_element(workerTimes.begin(), workerTimes.end());

    long long left = 1, right = (long long)maximum * mountainHeight *
                                (mountainHeight + 1) / 2;
    long long answer = 0;

    while (left <= right) {
      long long mid = left + (right - left) / 2;

      long long cur = calc(mid, workerTimes);

      if (cur >= mountainHeight) {
        right = mid - 1;
        answer = mid;
      } else {
        left = mid + 1;
      }
    }

    return answer;
  }
};