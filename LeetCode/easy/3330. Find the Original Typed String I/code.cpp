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
  int possibleStringCount(string word) {
    int answer = 0;
    int count = 0;
    char before = word[0];

    for (char &c : word) {
      if (before != c) {
        answer += (count - 1);

        count = 1;
        before = c;
      } else {
        count++;
      }
    }

    answer += count;

    return answer;
  }
};