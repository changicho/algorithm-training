#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N^2)
// space : O(1)
class Solution {
 private:
  bool isEqual(int a, int b) {
    if (a == b) return true;

    string aCount = string(10, 0), bCount = string(10, 0);

    int diff = 0;
    while (a > 0 || b > 0) {
      int curA = a % 10, curB = b % 10;
      if (curA != curB) diff++;
      aCount[curA]++;
      bCount[curB]++;
      a /= 10;
      b /= 10;
    }

    if (diff <= 2 && aCount == bCount) return true;

    return false;
  }

 public:
  int countPairs(vector<int>& nums) {
    int size = nums.size();
    int answer = 0;

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < i; j++) {
        if (isEqual(nums[i], nums[j])) {
          answer++;
        }
      }
    }
    return answer;
  }
};