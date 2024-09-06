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

// use mod
// time : O(N)
// space : O(1)
class Solution {
 public:
  int chalkReplacer(vector<int>& chalk, int k) {
    int size = chalk.size();

    long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);

    k %= sum;

    for (int i = 0; i < size; i++) {
      k -= chalk[i];
      if (k < 0) return i;
    }
    return 0;
  }
};