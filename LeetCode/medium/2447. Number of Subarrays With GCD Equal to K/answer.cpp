#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use brute force
// time : O(N^2)
// space : O(1)
class Solution {
 public:
  int subarrayGCD(vector<int>& nums, int k) {
    int size = nums.size();
    int answer = 0;

    for (int left = 0; left < size; left++) {
      int divisor = nums[left];
      for (int right = left; right < size; right++) {
        divisor = gcd(nums[right], divisor);

        if (divisor < k) break;
        if (divisor == k) {
          answer++;
        }
      }
    }

    return answer;
  }
};

// count gcds
// time : O(N * log_2(M))
// space : log_2(M)
class Solution {
 public:
  int subarrayGCD(vector<int>& nums, int k) {
    int size = nums.size();
    int answer = 0;

    unordered_map<int, int> gcds;
    for (int i = 0; i < size; i++) {
      unordered_map<int, int> new_gcds;

      if (nums[i] % k == 0) {
        gcds[nums[i]]++;
        for (auto [prev_gcd, cnt] : gcds) {
          new_gcds[gcd(prev_gcd, nums[i])] += cnt;
        }
      }

      answer += new_gcds[k];
      swap(gcds, new_gcds);
    }
    return answer;
  }
};