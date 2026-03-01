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

// one pass
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  int binaryGap(int n) {
    int answer = 0;
    int count = 0;
    int before = 32;

    while (n > 0) {
      if (n % 2 == 1) {
        answer = max(answer, count - before);
        before = count;
      }

      n /= 2;
      count++;
    }
    return answer;
  }
};