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
  int bitwiseComplement(int n) {
    int answer = 0;
    if (n == 0) return 1;
    for (int i = 1; i < n; i <<= 1) {
      if ((n & i) == 0) {
        answer += i;
      }
    }
    return answer;
  }
};