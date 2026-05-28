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
    int isNotFine = 0;
    int upper = 0;
    int lower = 0;

    for (char& c : word) {
      if (islower(c)) {
        lower |= 1 << (c - 'a');
        if (upper & 1 << (c - 'a')) {
          isNotFine |= 1 << (c - 'a');
        }
      } else {
        upper |= 1 << (c - 'A');
        if (lower & 1 << (c - 'A') == 0) {
          isNotFine |= 1 << (c - 'A');
        }
      }
    }

    int answer = 0;
    for (int i = 0; i < 26; i++) {
      if ((upper & 1 << i) && (lower & 1 << i) && !(isNotFine & 1 << i))
        answer++;
    }
    return answer;
  }
};