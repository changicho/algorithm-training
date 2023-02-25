#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use simulation
// time : O(N)
// space : O(N)
class Solution {
 private:
  long long convert(int a, int b) {
    string str = to_string(a) + to_string(b);

    return stoll(str);
  }

 public:
  long long findTheArrayConcVal(vector<int>& nums) {
    long long answer = 0;

    int left = 0, right = nums.size() - 1;

    while (left < right) {
      answer += convert(nums[left], nums[right]);
      left++;
      right--;
    }

    if (left == right) {
      answer += nums[left];
    }
    return answer;
  }
};