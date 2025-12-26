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
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minProductSum(vector<int>& nums1, vector<int>& nums2) {
    int count1[101] = {
        0,
    };
    int count2[101] = {
        0,
    };

    for (int& num : nums1) {
      count1[num]++;
    }
    for (int& num : nums2) {
      count2[num]++;
    }

    int size = nums1.size();
    int num1 = 0, num2 = 100;

    int sum = 0;
    for (int i = 0; i < size; i++) {
      while (count1[num1] == 0) {
        num1++;
      }
      count1[num1]--;

      while (count2[num2] == 0) {
        num2--;
      }
      count2[num2]--;

      sum += num1 * num2;
    }
    return sum;
  }
};