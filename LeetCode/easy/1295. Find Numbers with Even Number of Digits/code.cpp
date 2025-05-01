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
// time : O(N)
// space : O(1)
class Solution {
 private:
  bool check(int num) {
    for (int d = 100000, c = 0; d >= 1; d /= 10, c++) {
      if (num >= d) {
        return c % 2 == 0;
      }
    }
    return false;
  }

 public:
  int findNumbers(vector<int>& nums) {
    int answer = 0;

    for (int& num : nums) {
      if (check(num)) {
        answer++;
      }
    }
    return answer;
  }
};