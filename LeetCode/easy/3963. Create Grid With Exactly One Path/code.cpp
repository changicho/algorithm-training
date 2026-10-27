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

// greedy
// time : O(MN)
// space : O(MN)
class Solution {
 public:
  vector<string> createGrid(int m, int n) {
    vector<string> answer(m, string(n, '#'));

    for (int x = 0; x < n; x++) {
      answer[0][x] = '.';
    }
    for (int y = 1; y < m; y++) {
      answer[y][n - 1] = '.';
    }
    return answer;
  }
};