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

// brute force
// time : O(N^2)
// space : O(1)
class Solution {
 public:
  int countRatioSubarrays(vector<int>& nums, int a, int b) {
    int size = nums.size();

    int answer = 0;
    for (int i = 0; i < size; i++) {
      int odd = 0, even = 0;

      for (int j = i; j < size; j++) {
        if (nums[j] % 2 == 0) {
          even++;
        } else {
          odd++;
        }

        if (even * b <= a * odd) {
          answer++;
        }
      }
    }
    return answer;
  }
};