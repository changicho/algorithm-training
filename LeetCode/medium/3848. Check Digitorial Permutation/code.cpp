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

// one pass
// time : O(log_10(N))
// space : O(1)
class Solution {
 public:
  bool isDigitorialPermutation(int n) {
    int facto[10] = {
        0,
    };
    facto[0] = 1;
    for (int i = 1; i <= 9; i++) {
      facto[i] = facto[i - 1] * i;
    }

    int count[10] = {
        0,
    };

    int sum = 0;
    while (n > 0) {
      count[n % 10]++;

      sum += facto[n % 10];

      n /= 10;
    }

    while (sum > 0) {
      count[sum % 10]--;
      sum /= 10;
    }

    for (int i = 0; i < 10; i++) {
      if (count[i] != 0) return false;
    }

    return true;
  }
};