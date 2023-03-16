#include <algorithm>
#include <climits>
#include <cmath>
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

// use simulation
// time : O(T)
// space : O(1)
class Solution {
 public:
  int passThePillow(int n, int time) {
    bool isLeft = true;
    int index = 0;
    while (time--) {
      if (isLeft) {
        index++;
      } else {
        index--;
      }

      if (index == 0 || index == (n - 1)) {
        isLeft = !isLeft;
      }
    }
    return index + 1;
  }
};

// use simulation
// time : O(min(N, T))
// space : O(1)
class Solution {
 public:
  int passThePillow(int n, int time) {
    int cycleTime = (n - 1) * 2;
    time %= cycleTime;

    bool isLeft = true;
    int index = 0;
    while (time--) {
      if (isLeft) {
        index++;
      } else {
        index--;
      }

      if (index == 0 || index == (n - 1)) {
        isLeft = !isLeft;
      }
    }
    return index + 1;
  }
};

// use divide
// time : O(1)
// space : O(1)
class Solution {
 public:
  int passThePillow(int n, int time) {
    int cycleCount = time / (n - 1);
    int toMove = time % (n - 1);

    if (cycleCount % 2 == 0) {
      // left to right case
      return toMove + 1;
    } else {
      // right to left case
      return n - toMove;
    }
  }
};