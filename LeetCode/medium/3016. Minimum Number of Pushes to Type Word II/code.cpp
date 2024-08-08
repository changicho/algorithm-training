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

// use sort
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minimumPushes(string word) {
    int counts[26] = {
        0,
    };

    for (char &c : word) {
      counts[c - 'a']++;
    }
    sort(counts, counts + 26, greater<int>());

    int answer = 0;
    for (int i = 0; i < 26; i++) {
      int press = 1 + i / 8;

      answer += counts[i] * press;
    }

    return answer;
  }
};