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

// sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int countGoodRotations(vector<int>& nums) {
    int size = nums.size();

    int leftI = 0, rightI = size / 2;
    long long leftSum = 0, rightSum = 0;

    for (int i = 0; i < size / 2; i++) {
      leftSum += nums[i];
      rightSum += nums[size / 2 + i];
    }

    int answer = 0;

    for (int shift = 0; shift < size; shift++) {
      if (leftSum > rightSum) answer++;

      leftSum -= nums[leftI];
      leftSum += nums[rightI];

      rightSum -= nums[rightI];
      rightSum += nums[leftI];

      leftI = (leftI + 1) % size;
      rightI = (rightI + 1) % size;
    }
    return answer;
  }
};

// two pointer (half compare)
// time : O(N)
// space : O(1)
class Solution {
 public:
  int countGoodRotations(vector<int>& nums) {
    int size = nums.size();

    int leftI = 0, rightI = size / 2;
    long long leftSum = 0, rightSum = 0;

    for (int i = 0; i < size / 2; i++) {
      leftSum += nums[i];
      rightSum += nums[size / 2 + i];
    }

    int answer = 0;

    for (int shift = 0; shift < size / 2; shift++) {
      if (leftSum != rightSum) answer++;

      leftSum -= nums[leftI];
      leftSum += nums[rightI];

      rightSum -= nums[rightI];
      rightSum += nums[leftI];

      leftI = (leftI + 1) % size;
      rightI = (rightI + 1) % size;
    }
    return answer;
  }
};