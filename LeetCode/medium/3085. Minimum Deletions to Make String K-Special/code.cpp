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

// use one pass (count)
// time : O(N)
// space : O(1)
class Solution {
 private:
  int calc(int left, int right, int *count) {
    int ret = 0;
    for (int i = 0; i < 26; i++) {
      if (count[i] < left) {
        ret += count[i];
      } else if (count[i] > right) {
        ret += count[i] - right;
      }
    }
    return ret;
  }

 public:
  int minimumDeletions(string word, int k) {
    int count[26] = {
        0,
    };

    for (char &c : word) {
      count[c - 'a']++;
    }

    int answer = word.size();
    for (int i = 0; i < 26; i++) {
      if (count[i] == 0) continue;

      int cur = calc(count[i], count[i] + k, count);

      answer = min(answer, cur);
    }
    return answer;
  }
};