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

// simulation
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> resultArray(vector<int>& nums) {
    vector<int> arr1, arr2;

    arr1.push_back(nums[0]);
    arr2.push_back(nums[1]);

    int size = nums.size();
    for (int i = 2; i < size; i++) {
      if (arr1.back() > arr2.back()) {
        arr1.push_back(nums[i]);
      } else {
        arr2.push_back(nums[i]);
      }
    }

    for (int& num : arr2) {
      arr1.push_back(num);
    }
    return arr1;
  }
};