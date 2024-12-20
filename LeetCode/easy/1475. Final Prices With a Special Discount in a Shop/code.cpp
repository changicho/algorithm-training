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

// use monotonic stack
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> finalPrices(vector<int>& prices) {
    int size = prices.size();

    vector<int> answer(size);

    stack<int> incStack;
    for (int i = size - 1; i >= 0; i--) {
      int cur = prices[i];
      while (!incStack.empty() && cur < incStack.top()) {
        incStack.pop();
      }

      if (!incStack.empty()) {
        answer[i] = cur - incStack.top();
      } else {
        answer[i] = cur;
      }
      incStack.push(cur);
    }
    return answer;
  }
};