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

// use two pointer
// time : O(N + M)
// space : O(1)
class Solution {
 public:
  bool canChange(string start, string target) {
    int size = start.size();

    int sI = 0, tI = 0;
    while (tI < size && target[tI] == '_') {
      tI++;
    }
    for (; sI < size; sI++) {
      if (start[sI] == '_') continue;

      if (start[sI] != target[tI]) return false;
      if (start[sI] == 'L' && sI < tI) return false;
      if (start[sI] == 'R' && sI > tI) return false;

      tI++;
      while (tI < size && target[tI] == '_') {
        tI++;
      }
    }

    if (tI < size || sI < size) return false;
    return true;
  }
};