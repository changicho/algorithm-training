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

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maxDistance(string s, int k) {
    int size = s.size();
    int y = 0, x = 0, answer = 0;

    for (int i = 0; i < size; i++) {
      switch (s[i]) {
        case 'N':
          y++;
          break;
        case 'S':
          y--;
          break;
        case 'E':
          x++;
          break;
        case 'W':
          x--;
          break;
      }

      answer = max(answer, min(abs(x) + abs(y) + k * 2, i + 1));
    }
    return answer;
  }
};