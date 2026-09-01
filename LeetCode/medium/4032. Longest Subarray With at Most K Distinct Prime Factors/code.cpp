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

// prime factor & sliding window
// time : O(M * log_2(log_2(M)) + N * F)
// space : O(N * F + M)
class Solution {
 private:
  bool isNotPrime[100001];
  vector<int> primes;

  vector<int> convert(int num) {
    vector<int> ret;

    for (int& i : primes) {
      if (num < i) break;

      if ((num % i) == 0) {
        ret.push_back(i);
        num /= i;
      }
    }

    return ret;
  }

 public:
  int longestSubarray(vector<int>& nums, int k) {
    isNotPrime[1] = true;
    for (int i = 2; i <= 100000; i++) {
      if (isNotPrime[i]) continue;
      primes.push_back(i);

      for (int j = i + i; j <= 100000; j += i) {
        isNotPrime[j] = true;
      }
    }

    int size = nums.size();

    vector<vector<int>> ps;

    for (int& num : nums) {
      if (!isNotPrime[num]) {
        ps.push_back({num});
        continue;
      }

      vector<int> cur = convert(num);

      ps.push_back(cur);
    }

    int answer = 0;
    unordered_map<int, int> um;
    for (int left = 0, right = 0; right < size; right++) {
      for (int& p : ps[right]) {
        um[p]++;
      }

      while (um.size() > k && left <= right) {
        for (int& p : ps[left]) {
          um[p]--;
          if (um[p] == 0) um.erase(p);
        }
        left++;
      }

      answer = max(answer, right - left + 1);
    }
    return answer;
  }
};