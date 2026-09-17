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

// hash map
// time : O(N)
// space : O(N)
class Solution {
 public:
  int countSpecialIntegers(vector<int>& nums) {
    int size = nums.size();
    unordered_map<int, vector<int>> indexs;

    for (int i = 0; i < size; i++) {
      indexs[nums[i]].push_back(i);
    }

    int answer = 0;
    for (auto& [num, is] : indexs) {
      if (is.size() != 3) continue;

      if (is[2] - is[1] == is[1] - is[0]) answer++;
    }
    return answer;
  }
};