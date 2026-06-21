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
  int largestAltitude(vector<int>& gain) {
    int answer = 0;
    int cur = 0;
    for (int& g : gain) {
      cur += g;

      answer = max(answer, cur);
    }
    return answer;
  }
};