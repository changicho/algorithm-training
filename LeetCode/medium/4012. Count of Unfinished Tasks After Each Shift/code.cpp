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

// prefix sum & binary search
// time : O(M * log_2(N))
// space : O(N + M)
class Solution {
 public:
  vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
    int size = tasks.size();
    vector<int> answer;

    vector<long long> prefixSum;
    prefixSum.push_back(0);
    for (int i = 0; i < size; i++) {
      prefixSum.push_back(prefixSum.back() + tasks[i]);
    }

    int left = 0;
    int sI = 0;  // index
    for (int& shift : shifts) {
      int target = upper_bound(prefixSum.begin() + sI, prefixSum.end(),
                               prefixSum[sI] + shift + left) -
                   prefixSum.begin();
      target--;
      left = (prefixSum[sI] + shift + left) - prefixSum[target];

      answer.push_back(size - target);
      sI = target;

      if (sI >= size) {
        sI = 0;
        left = 0;
      }
    }
    return answer;
  }
};