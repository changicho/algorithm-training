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

// use counting consecutive 1
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maxOperations(string s) {
    int size = s.size();

    int answer = 0;
    int count = 0;
    int ones = 0;
    for (char &c : s) {
      if (c == '1') {
        count++;
      } else {
        if (count > 0) {
          ones += count;
          answer += ones;
        }
        count = 0;
      }
    }

    return answer;
  }
};