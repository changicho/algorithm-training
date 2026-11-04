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

// greedy & sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 private:
  long long convert(int num) {
    int count[10] = {
        0,
    };
    while (num > 0) {
      count[num % 10]++;
      num /= 10;
    }
    long long ret = 0;
    for (int d = 9; d >= 0; d--) {
      while (count[d]) {
        ret = ret * 10 + d;
        count[d]--;
      }
    }
    return ret;
  }

 public:
  long long maximizeSum(vector<int>& nums, int k) {
    int size = nums.size();
    vector<pair<long long, long long>> arr;
    for (int& num : nums) {
      arr.push_back({num, convert(num)});
    }

    sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
      return a.second - a.first > b.second - b.first;
    });

    long long answer = 0;

    for (int i = 0; i < size; i++) {
      if (i < k) {
        answer += arr[i].second;
      } else {
        answer += arr[i].first;
      }
    }
    return answer;
  }
};