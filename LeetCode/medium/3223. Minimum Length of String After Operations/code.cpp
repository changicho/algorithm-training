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

// use count
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minimumLength(string s) {
    int counts[26] = {
        0,
    };
    for (char &c : s) {
      counts[c - 'a']++;
    }
    int answer = 0;
    for (int i = 0; i < 26; i++) {
      if (counts[i] == 0) continue;

      if (counts[i] % 2 == 0)
        answer += 2;
      else
        answer++;
    }
    return answer;
  }
};