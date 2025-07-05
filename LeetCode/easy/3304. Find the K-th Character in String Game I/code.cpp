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

// use iteration
// time : O(log_2(K))
// space : O(1)
class Solution {
 public:
  char kthCharacter(int k) {
    int diff = 0;

    while (k > 1) {
      int half = 1 << int(log2(k));
      if (half == k) {
        half /= 2;
      }

      k -= half;
      diff++;
    }
    return 'a' + diff;
  }
};

// use simulation
// time : O(K * log_2(K))
// space : O(K)
class Solution {
 public:
  char kthCharacter(int k) {
    string cur = "a";

    while (cur.size() < k) {
      string next = cur;
      for (char &c : next) {
        c++;
        if (c > 'z') c = 'a';
      }
      cur = cur + next;
    }

    return cur[k - 1];
  }
};

// use string
// time : O(K)
// space : O(K)
class Solution {
 public:
  char kthCharacter(int k) {
    string cur =
        "abbcbccdbccdcddebccdcddecddedeefbccdcddecddedeefcddedeefdeefeffgbccdcd"
        "decddedeefcddedeefdeefeffgcddedeefdeefeffgdeefeffgeffgfgghbccdcddecdde"
        "deefcddedeefdeefeffgcddedeefdeefeffgdeefeffgeffgfgghcddedeefdeefeffgde"
        "efeffgeffgfgghdeefeffgeffgfggheffgfgghfgghghhibccdcddecddedeefcddedeef"
        "deefeffgcddedeefdeefeffgdeefeffgeffgfgghcddedeefdeefeffgdeefeffgeffgfg"
        "ghdeefeffgeffgfggheffgfgghfgghghhicddedeefdeefeffgdeefeffgeffgfgghdeef"
        "effgeffgfggheffgfgghfgghghhideefeffgeffgfggheffgfgghfgghghhieffgfgghfg"
        "ghghhifgghghhighhihiij";

    return cur[k - 1];
  }
};