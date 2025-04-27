#include <algorithm>
#include <climits>
#include <cmath>
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

// use brute force
// time : O(N * log_10(N))
// space : O(log_10(N))
class Solution {
 private:
  int calc(int num) {
    int sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    return sum;
  }

 public:
  int countLargestGroup(int n) {
    unordered_map<int, int> counts;

    int maximum = 0;
    for (int i = 1; i <= n; i++) {
      int sum = calc(i);
      counts[sum]++;
      maximum = max(maximum, counts[sum]);
    }

    int answer = 0;
    for (auto [key, val] : counts) {
      if (val == maximum) answer++;
    }
    return answer;
  }
};