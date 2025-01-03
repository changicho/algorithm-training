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

// use index shift
// time : O(N + M)
// space : O(N)
class Solution {
 public:
  string stringShift(string s, vector<vector<int>>& shift) {
    int size = s.size();

    int start = 0;
    for (vector<int>& oper : shift) {
      int dir = oper[0], amount = oper[1];

      amount %= size;

      if (dir == 0) {
        start = (start + size + amount) % size;
      } else {
        start = (start + size - amount) % size;
      }
    }

    s += s.substr(0, start);
    s.erase(0, start);
    return s;
  }
};