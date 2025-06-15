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

// use greedy
// time : O(log_10(N))
// space : O(log_10(N))
class Solution {
 public:
  int minMaxDifference(int num) {
    string s = to_string(num);

    int size = s.size();

    string maximum = s, minimum = s;
    char maxTarget = '9', minTarget = s[0];

    int pos = maximum.find_first_not_of('9');
    if (pos != -1) {
      maxTarget = maximum[pos];
    }
    // for (char &c : maximum) {
    //   if (c == '9') continue;
    //   maxTarget = c;
    //   break;
    // }

    for (int i = 0; i < size; i++) {
      if (maximum[i] == maxTarget) maximum[i] = '9';
      if (minimum[i] == minTarget) minimum[i] = '0';
    }

    return stoi(maximum) - stoi(minimum);
  }
};