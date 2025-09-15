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
  int minOperations(string s) {
    int answer = 0;

    for (char &c : s) {
      int dist = (26 - (c - 'a')) % 26;

      answer = max(answer, dist);
    }

    return answer;
  }
};