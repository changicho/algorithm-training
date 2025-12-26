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

// use count sort
// time : O(N + M + K)
// space : O(K)
class Solution {
 public:
  int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    int size = capacity.size();

    int count[51] = {
        0,
    };
    for (int& c : capacity) {
      count[c]++;
    }

    int sum = accumulate(apple.begin(), apple.end(), 0);

    int prefix = 0;
    int useCount = 0;
    for (int val = 50; val >= 0; val--) {
      int diff = sum - prefix;

      if (diff > count[val] * val) {
        useCount += count[val];
        prefix += count[val] * val;
        count[val] = 0;
        continue;
      }

      int valCount = ceil((double)diff / val);
      useCount += valCount;
      return useCount;
    }

    return size;
  }
};