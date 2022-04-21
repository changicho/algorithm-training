#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use two pointer & combination
// time : O(N * log_2(N) + W^2)
// space : O(W)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int threeSumMulti(vector<int>& arr, int target) {
    unordered_map<int, long> count;
    vector<int> keys;

    for (int& a : arr) {
      count[a]++;
    }
    for (auto it : count) {
      keys.push_back(it.first);
    }
    sort(keys.begin(), keys.end());

    int size = keys.size();
    long long answer = 0;

    for (int i = 0; i < size; i++) {
      long curCount = count[keys[i]];
      // one case
      int left = i + 1, right = size - 1;
      while (left < right) {
        int cur = keys[i] + keys[left] + keys[right];

        if (cur == target) {
          answer += curCount * count[keys[left]] * count[keys[right]];
        }

        if (cur > target) {
          right--;
        } else {
          left++;
        }
      }

      // two case
      if (count[keys[i]] >= 2 && count.count(target - keys[i] * 2) > 0 &&
          target - keys[i] * 2 != keys[i]) {
        answer += (curCount * (curCount - 1) / 2) * count[target - keys[i] * 2];
      }

      // three case
      if (count[keys[i]] >= 3 && keys[i] * 3 == target) {
        answer += curCount * (curCount - 1) * (curCount - 2) / 6;
      }
    }

    answer %= MOD;
    return answer;
  }
};

// use two pointer & combination
// time : O(N + W^2)
// space : O(W)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int threeSumMulti(vector<int>& arr, int target) {
    unordered_map<int, long> count;
    for (int& num : arr) {
      count[num]++;
    }

    long answer = 0;
    for (auto& [first, c1] : count) {
      for (auto& [second, c2] : count) {
        int third = target - first - second;

        if (!count.count(third)) continue;
        // three case
        if (first == second && second == third) {
          answer += count[first] * (count[first] - 1) * (count[first] - 2) / 6;
        }
        // two case
        if (first == second && second != third) {
          answer += count[first] * (count[first] - 1) / 2 * count[third];
        }
        // one case
        if (first < second && second < third) {
          answer += count[first] * count[second] * count[third];
        }
      }
    }
    return answer % MOD;
  }
};