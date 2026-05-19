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

// prefix sum
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<long long> distance(vector<int>& nums) {
    int size = nums.size();
    unordered_map<int, vector<int>> idxs;

    for (int i = 0; i < size; i++) {
      int cur = nums[i];

      idxs[cur].push_back(i);
    }

    vector<long long> answer(size);

    for (auto& [key, val] : idxs) {
      if (val.size() == 1) continue;

      long long sum = accumulate(val.begin(), val.end(), 0LL);

      long long prefix = 0;

      int ssize = val.size();

      for (long long i = 0; i < ssize; i++) {
        long long leftPart = val[i] * (i + 1) - prefix;

        long long rightPart = (sum - prefix) - val[i] * (ssize - i + 1);

        answer[val[i]] = leftPart + rightPart;
        prefix += val[i];
      }
    }

    return answer;
  }
};

// binary search
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  long long calc(int i, vector<int>& arr, vector<long long>& prefix) {
    long long ret = 0;

    if (arr.size() == 1) return 0;

    long long target = lower_bound(arr.begin(), arr.end(), i) - arr.begin();

    long long leftPart = i * (target)-prefix[target];
    long long rightPart =
        prefix.back() - prefix[target] - i * (arr.size() - target);

    ret += leftPart;
    ret += rightPart;

    return ret;
  }

 public:
  vector<long long> distance(vector<int>& nums) {
    int size = nums.size();
    unordered_map<int, vector<int>> idxs;
    unordered_map<int, vector<long long>> prefixs;

    for (int i = 0; i < size; i++) {
      int cur = nums[i];

      idxs[cur].push_back(i);
      if (prefixs[cur].size() == 0) prefixs[cur].push_back(0);

      prefixs[cur].push_back(prefixs[cur].back() + i);
    }

    vector<long long> answer;
    for (int i = 0; i < size; i++) {
      long long cur = calc(i, idxs[nums[i]], prefixs[nums[i]]);

      answer.push_back(cur);
    }

    return answer;
  }
};