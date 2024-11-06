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

// use greedy
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minChanges(string s) {
    int size = s.size();
    int answer = 0;
    for (int i = 0; i < size; i += 2) {
      if (s[i] != s[i + 1]) answer++;
    }
    return answer;
  }
};