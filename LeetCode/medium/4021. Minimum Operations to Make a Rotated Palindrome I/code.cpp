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

// brute force
// time : O(N^2)
// space : O(1)
class Solution {
 public:
  int minOperations(string s) {
    int size = s.size();
    int answer = INT_MAX;

    for (int rotate = 0; rotate < size; rotate++) {
      int curDiff = 0;
      for (int i = 0; i < size / 2; i++) {
        char left = s[(rotate + i) % size];
        char right = s[(size - 1 + rotate - i + size) % size];

        if (left != right) {
          int diff = max(left, right) - min(left, right);

          diff = min(diff, 26 - diff);
          curDiff += diff;
        }
      }

      answer = min(answer, curDiff + rotate);
    }

    return answer;
  }
};