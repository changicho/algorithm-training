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

// use count
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  int tupleSameProduct(vector<int>& nums) {
    int size = nums.size();

    unordered_map<int, int> counts;
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        int cur = nums[i] * nums[j];

        counts[cur]++;
      }
    }

    int answer = 0;
    for (auto& [key, val] : counts) {
      if (val >= 2) {
        int combi = (val - 1) * val / 2;
        answer += combi * 2 * 2 * 2;
      }
    }
    return answer;
  }
};