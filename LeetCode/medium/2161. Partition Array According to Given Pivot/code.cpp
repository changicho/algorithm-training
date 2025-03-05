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

// use one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> pivotArray(vector<int> &nums, int pivot) {
    int size = nums.size();
    vector<int> smaller, bigger, equals;

    for (int &num : nums) {
      if (num < pivot) {
        smaller.push_back(num);
      } else if (num > pivot) {
        bigger.push_back(num);
      } else {
        equals.push_back(num);
      }
    }

    int i = 0;
    for (int &num : smaller) {
      nums[i] = num;
      i++;
    }
    for (int &num : equals) {
      nums[i] = num;
      i++;
    }
    for (int &num : bigger) {
      nums[i] = num;
      i++;
    }
    return nums;
  }
};