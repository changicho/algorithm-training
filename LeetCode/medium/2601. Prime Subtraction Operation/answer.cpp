#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use prime number & binary search
// time : O(N * log_2(P) + P * log_2(log_2(P)))
// space : O(P)
class Solution {
 private:
  bool isNotPrime[1001];
  vector<int> primes;

  void init() {
    isNotPrime[1] = true;

    for (int i = 2; i <= 1000; i++) {
      if (isNotPrime[i]) continue;

      for (int j = 2; i * j <= 1000; j++) {
        isNotPrime[i * j] = true;
      }
    }

    for (int i = 2; i <= 1000; i++) {
      if (!isNotPrime[i]) primes.push_back(i);
    }
  }

  // maximum prime lower than target
  int pickPrime(int target) {
    int left = 0, right = primes.size();

    int ret = -1;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (primes[mid] < target) {
        // pick right
        ret = primes[mid];
        left = mid + 1;
      } else {
        // pick left
        right = mid;
      }
    }
    return ret;
  }

 public:
  bool primeSubOperation(vector<int>& nums) {
    init();

    int size = nums.size();

    for (int i = 0; i < size; i++) {
      int before = (i - 1) < 0 ? 0 : nums[i - 1];

      int target = pickPrime(nums[i] - before);

      if (target == -1) continue;
      nums[i] -= target;
    }

    for (int i = 0; i < size - 1; i++) {
      if (nums[i] >= nums[i + 1]) return false;
    }
    return true;
  }
};