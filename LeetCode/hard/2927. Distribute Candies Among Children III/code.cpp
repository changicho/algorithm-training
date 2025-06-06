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

// use combination
// time : O(1)
// space : O(1)
class Solution {
 private:
  long long combination(int n, int m) {
    if (n < m) return 0;
    return (long long)n * (n - 1) / m / (m - 1);
  }

 public:
  long long distributeCandies(int n, int limit) {
    long long answer = 0;
    answer += combination(n + 2, 2);
    answer -= 3 * combination(n - limit + 1, 2);
    answer += 3 * combination(n - 2 * limit, 2);
    answer -= combination(n - 3 * limit - 1, 2);
    return answer;
  }
};