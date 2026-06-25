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

// count
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maxNumberOfBalloons(string text) {
    int count[26] = {
        0,
    };
    for (char& c : text) {
      count[c - 'a']++;
    }

    string target = "balloon";
    int answer = 0;
    while (true) {
      bool flag = true;
      for (char& c : target) {
        count[c - 'a']--;

        if (count[c - 'a'] < 0) {
          flag = false;
          break;
        }
      }

      if (flag) {
        answer++;
      } else {
        break;
      }
    }
    return answer;
  }
};