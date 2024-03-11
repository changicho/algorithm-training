#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash set
// time : O(N + M)
// space : O(N)
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> us(nums1.begin(), nums1.end());

    vector<int> answer;
    for (int& num : nums2) {
      if (us.count(num) > 0) {
        answer.push_back(num);
        us.erase(num);
      }
    }

    return answer;
  }
};