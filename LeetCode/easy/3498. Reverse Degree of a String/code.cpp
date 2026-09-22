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
  int reverseDegree(string s) {
    int size = s.size();
    int answer = 0;

    for (int i = 0; i < size; i++) {
      char& c = s[i];
      int cur = c - 'a';
      answer += (26 - cur) * (i + 1);
    }
    return answer;
  }
};