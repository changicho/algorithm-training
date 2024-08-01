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

// use prefix two pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minimumDeletions(string s) {
    int size = s.size();

    // a : left, b : right
    int aCount = 0, bCount = 0;
    for (int i = 0; i < size; i++) {
      if (s[i] == 'b') bCount++;
    }

    int answer = bCount;
    for (int i = size - 1; i >= 0; i--) {
      if (s[i] == 'a') {
        aCount++;
      } else {
        bCount--;
      }

      answer = min(answer, bCount + aCount);
    }
    return answer;
  }
};