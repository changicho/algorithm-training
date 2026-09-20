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

// one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  int countSpecialIntegers(vector<int>& nums) {
    int size = nums.size();

    unordered_map<int, vector<int>> um;

    for (int i = 0; i < size; i++) {
      int num = nums[i];

      um[num].push_back(i);
    }

    int answer = 0;
    for (auto& [num, indices] : um) {
      if (indices.size() < 3) continue;
      int isize = indices.size();
      int diff = indices[1] - indices[0];
      bool isValid = true;

      for (int i = 2; i < isize; i++) {
        if (diff != indices[i] - indices[i - 1]) {
          isValid = false;
          break;
        }
      }

      answer += isValid;
    }
    return answer;
  }
};