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
// time : O(N * sqrt(M))
// space : O(1)
class Solution {
 private:
  int hasFour(int& num) {
    int count = 0;
    int sum = 0;

    for (int i = 1; i <= sqrt(num); i++) {
      if (num % i == 0) {
        count += 2;
        sum += i;
        sum += num / i;

        if (num / i == i) {
          count--;
          sum -= num / i;
        }
      }
    }

    return count == 4 ? sum : 0;
  }

 public:
  int sumFourDivisors(vector<int>& nums) {
    int sum = 0;

    for (int& num : nums) {
      sum += hasFour(num);
    }
    return sum;
  }
};