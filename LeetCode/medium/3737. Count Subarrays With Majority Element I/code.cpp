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

// prefix sum & brute force
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int countMajoritySubarrays(vector<int>& nums, int target) {
    int size = nums.size();
    int prefix[1002] = {
        0,
    };

    for (int i = 0; i < size; i++) {
      prefix[i + 1] = prefix[i] + (nums[i] == target);
    }

    int answer = 0;
    for (int i = 0; i < size; i++) {
      for (int j = i; j < size; j++) {
        int count = prefix[j + 1] - prefix[i];
        int length = j - i + 1;

        if (count > length / 2) {
          answer++;
        }
      }
    }
    return answer;
  }
};