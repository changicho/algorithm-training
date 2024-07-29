#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use bit compare
// time : O(1)
// space : O(1)
class Solution {
 public:
  int minChanges(int n, int k) {
    int answer = 0;
    for (int i = 0; i < 32; i++) {
      int bit = 1 << i;

      if ((n & bit) == (k & bit)) continue;

      if ((n & bit) > 0 && (k & bit) == 0)
        answer++;
      else
        return -1;
    }
    return answer;
  }
};