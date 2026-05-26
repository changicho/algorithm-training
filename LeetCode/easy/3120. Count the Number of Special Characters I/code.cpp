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

// one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int numberOfSpecialChars(string word) {
    int count[256] = {
        0,
    };

    for (char& c : word) {
      count[c]++;
    }

    int answer = 0;
    for (int i = 0; i < 26; i++) {
      if (count[i + 'a'] > 0 && count[i + 'A'] > 0) answer++;
    }
    return answer;
  }
};