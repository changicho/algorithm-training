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

// two pointer
// time : O(N)
// space : O(1)
class Solution {
 public:
  string rearrangeString(string s, char x, char y) {
    int size = s.size();

    for (int i = 0, j = 0; i < size; i++) {
      if (s[i] == y) {
        swap(s[i], s[j]);
        j++;
      }
    }

    return s;
  }
};