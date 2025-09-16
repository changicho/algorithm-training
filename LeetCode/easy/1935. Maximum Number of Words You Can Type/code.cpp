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
// time : O(N + M)
// space : O(1)
class Solution {
 public:
  int canBeTypedWords(string text, string brokenLetters) {
    bool broken[26] = {
        false,
    };

    for (char &c : brokenLetters) {
      broken[c - 'a'] = true;
    }

    bool flag = false;
    int answer = 0;
    for (char &c : text) {
      if (c == ' ') {
        answer++;
        answer -= flag;
        flag = false;
        continue;
      }
      if (broken[c - 'a']) flag = true;
    }
    answer -= flag;
    answer++;

    return answer;
  }
};