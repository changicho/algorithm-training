#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use BST set
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  long long getSums(long long to) {
    if (to <= 0) return 0;
    return (to * (to + 1)) / 2;
  }

  long long getSums(long long from, long long to) {
    return getSums(to) - getSums(from - 1);
  }

 public:
  long long minimalKSum(vector<int>& nums, int k) {
    int count = k;
    // O(N * log_2(N))
    set<int> numSets(nums.begin(), nums.end());

    long long answer = 0;
    int before = 0;
    auto it = numSets.begin();
    // O(N)
    while (it != numSets.end() && count > 0) {
      int cur = *it;
      // can add range
      if (before + 1 < cur) {
        int diff = (cur - 1) - (before + 1) + 1;

        long long from = before + 1;
        long long to = diff <= count ? cur - 1 : from + count - 1;

        count -= (to - from + 1);

        answer += getSums(from, to);
      }

      before = cur;
      it++;
    }

    // left number case
    if (count > 0) {
      long long from = before + 1;
      long long to = from + count - 1;

      answer += getSums(from, to);
    }
    return answer;
  }
};

// use BST set, remove smallest
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  long long minimalKSum(vector<int>& nums, int k) {
    long long answer = (long long)k * (k + 1) / 2;
    // O(N * log_2(N))
    set<int> numSets(nums.begin(), nums.end());

    long long nextK = k;
    // O(N)
    for (int num : numSets) {
      if (num <= nextK) {
        nextK++;
        answer += nextK - num;
      }
    }

    return answer;
  }
};

// use heap, remove smallest
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  long long minimalKSum(vector<int>& nums, int k) {
    long long answer = (long long)k * (k + 1) / 2;
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

    int last = 0;
    long long nextK = k;
    while (!pq.empty() && pq.top() <= nextK) {
      int num = pq.top();
      pq.pop();

      if (num != last) {
        nextK++;
        answer += nextK - num;
      }
      last = num;
    }

    return answer;
  }
};

// use brute force & hash set (TLE)
// time : O(N + K)
// space : O(1)
class Solution {
 public:
  long long minimalKSum(vector<int>& nums, int k) {
    int count = k;
    unordered_set<int> numSets(nums.begin(), nums.end());

    long long answer = 0;
    for (long long i = 1; count > 0; i++) {
      if (numSets.count(i) > 0) continue;
      count--;
      answer += i;
    }

    return answer;
  }
};