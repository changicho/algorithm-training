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

// use bit count
// time : O(N)
// space : O(1)
class Solution {
 public:
  int largestCombination(vector<int>& candidates) {
    int bits[32] = {
        0,
    };

    for (int& num : candidates) {
      for (int i = 0; i < 32; i++) {
        if (num & (1 << i)) {
          bits[i]++;
        }
      }
    }

    int answer = 0;
    for (int i = 0; i < 32; i++) {
      answer = max(answer, bits[i]);
    }
    return answer;
  }
};