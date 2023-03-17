#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use factorize & count same factor
// time : O(N * sqrt(M))
// space : O(sqrt(M))
class Solution {
 private:
  vector<int> factorize(int num) {
    vector<int> res;
    for (int divider = 2; num > 1 && divider < 1000;
         divider += 1 + (divider % 2)) {
      if (num % divider == 0) {
        res.push_back(divider);

        while (num % divider == 0) {
          num /= divider;
        }
      }
    }

    if (num > 1) res.push_back(num);
    return res;
  }

 public:
  int findValidSplit(vector<int>& nums) {
    int size = nums.size();

    unordered_map<int, int> left, right;

    for (int num : nums) {
      for (int factor : factorize(num)) {
        right[factor]++;
      }
    }

    for (int i = 0, common = 0; i < size - 1; i++) {
      int num = nums[i];

      for (int factor : factorize(num)) {
        if (left[factor] == 0) common++;
        left[factor]++;
        if (left[factor] == right[factor]) common--;
      }

      if (common == 0) return i;
    }

    return -1;
  }
};

// use eratonothenes sieve & factorize & count same factor
// time : O(N * sqrt(M))
// space : O(sqrt(M))
class Solution {
 private:
  bool isNotPrime[1001];

  vector<int> primes;

  vector<int> factorize(int num) {
    vector<int> res;
    for (int& prime : primes) {
      if (num % prime == 0) {
        res.push_back(prime);

        while (num % prime == 0) {
          num /= prime;
        }
      }
    }

    if (num > 1) res.push_back(num);
    return res;
  }

 public:
  int findValidSplit(vector<int>& nums) {
    int size = nums.size();

    for (int num = 2; num <= 1e3; num++) {
      if (isNotPrime[num]) continue;

      for (int multiple = 2 * num; multiple <= 1e3; multiple += num) {
        isNotPrime[multiple] = true;
      }
    }

    for (int num = 2; num <= 1e3; num++) {
      if (!isNotPrime[num]) primes.push_back(num);
    }

    unordered_map<int, int> left, right;

    for (int num : nums) {
      for (int factor : factorize(num)) {
        right[factor]++;
      }
    }

    for (int i = 0, common = 0; i < size - 1; i++) {
      int num = nums[i];

      for (int factor : factorize(num)) {
        if (left[factor] == 0) common++;
        left[factor]++;
        if (left[factor] == right[factor]) common--;
      }

      if (common == 0) return i;
    }

    return -1;
  }
};