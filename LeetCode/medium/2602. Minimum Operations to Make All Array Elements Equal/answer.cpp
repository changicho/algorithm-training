#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search
// time : O((N + M) * log_2(N))
// space : O(N)
class Solution {
 private:
  long long calc(vector<long long> &prefixes, vector<int> &nums, int query) {
    int size = nums.size();

    int center = lower_bound(nums.begin(), nums.end(), query) - nums.begin();

    long long ret = 0;
    // left part
    ret += abs(prefixes[center] - (long long)query * (center));
    // right part
    ret += abs(prefixes[size] - prefixes[center] -
               (long long)query * (size - center));

    return ret;
  }

 public:
  vector<long long> minOperations(vector<int> &nums, vector<int> &queries) {
    vector<long long> answer;

    sort(nums.begin(), nums.end());

    int size = nums.size();
    vector<long long> prefixes(size + 1, 0);
    for (int i = 0; i < size; i++) {
      prefixes[i + 1] = prefixes[i] + nums[i];
    }

    for (int &query : queries) {
      answer.push_back(calc(prefixes, nums, query));
    }
    return answer;
  }
};