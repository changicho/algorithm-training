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

// use greedy & factorial
// time : O(N)
// space : O(1)
class Solution {
 public:
  int countPermutations(vector<int>& complexity) {
    const int MOD = 1e9 + 7;

    int size = complexity.size();

    int first = complexity[0];

    long long answer = 1;
    for (int i = 1; i < size; i++) {
      int num = complexity[i];

      if (num <= first) return 0;

      answer *= i;
      answer %= MOD;
    }

    return answer;
  }
};