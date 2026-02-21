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

// one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int countBinarySubstrings(string s) {
    int size = s.size();

    int before = 0;
    int cur = 1;
    int answer = 0;

    for (int i = 1; i < size; i++) {
      if (s[i] == s[i - 1]) {
        cur++;
      } else {
        before = cur;
        cur = 1;
      }

      if (before >= cur) answer++;
    }

    return answer;
  }
};

// use consecutive count
// time : O(N)
// space : O(N)
class Solution {
 public:
  int countBinarySubstrings(string s) {
    int size = s.size();

    int l2r[100001] = {
        0,
    };
    int r2l[100001] = {
        0,
    };

    for (int i = 1; i < size; i++) {
      if (s[i] == s[i - 1]) {
        l2r[i] = l2r[i - 1] + 1;
      } else {
        l2r[i] = 0;
      }
    }

    for (int i = size - 2; i >= 0; i--) {
      if (s[i] == s[i + 1]) {
        r2l[i] = r2l[i + 1] + 1;
      } else {
        r2l[i] = 0;
      }
    }

    int answer = 0;

    for (int i = 0; i < size - 1; i++) {
      if (s[i] != s[i + 1]) {
        int count = min(l2r[i], r2l[i + 1]);
        answer += count + 1;
      }
    }

    return answer;
  }
};