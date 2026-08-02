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

// use math
// time : O(1)
// space : O(1)
class Solution {
 public:
  long long maximumValue(int n, int s, int m) {
    long long answer = s;
    long long half = (n - 1) / 2;

    answer += (m - 1) * (half);

    if (n % 2 == 0) {
      answer += m;
    } else if (n % 2 == 1 && n > 1) {
      answer++;
    }

    return answer;
  }
};