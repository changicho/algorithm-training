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

// sliding window & sort
// time : O(N * log_2(N) + M * log_2(N))
// space : O(N + M)
class Solution {
 public:
  vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                           vector<int>& queries) {
    int size = queries.size();
    int logSize = logs.size();

    sort(logs.begin(), logs.end(),
         [](auto& a, auto& b) { return a[1] < b[1]; });

    vector<vector<int>> q;
    for (int i = 0; i < size; i++) {
      q.push_back({queries[i], i});
    }
    sort(q.begin(), q.end());

    vector<int> answer(size);

    int leftI = 0, rightI = 0;

    vector<int> count(n + 1);
    int uniqueSize = 0;

    for (vector<int>& query : q) {
      while (rightI < logSize && logs[rightI][1] <= query[0]) {
        count[logs[rightI][0]]++;
        if (count[logs[rightI][0]] == 1) {
          uniqueSize++;
        }
        rightI++;
      }

      while (leftI < logSize && logs[leftI][1] < query[0] - x) {
        count[logs[leftI][0]]--;
        if (count[logs[leftI][0]] == 0) {
          uniqueSize--;
        }
        leftI++;
      }

      answer[query[1]] = n - uniqueSize;
    }
    return answer;
  }
};
