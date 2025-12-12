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

// use brute force
// time : O(N^2)
// space : O(1)
class Solution {
 public:
  int countTriples(int n) {
    int answer = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        int target = i * i + j * j;
        int sq = sqrt(int(target));
        double sqD = sqrt(double(target));

        if (sq <= n && sq == sqD) answer++;
      }
    }

    return answer;
  }
};