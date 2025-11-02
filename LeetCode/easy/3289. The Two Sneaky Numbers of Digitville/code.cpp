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

// use count
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> getSneakyNumbers(vector<int>& nums) {
    vector<int> answer;

    int count[101] = {
        0,
    };
    for (int& num : nums) {
      count[num]++;
    }

    for (int i = 0; i <= 100; i++) {
      if (count[i] == 2) answer.push_back(i);
    }
    return answer;
  }
};

// use bit operation
// time : O(N)
// space : O(1)
class Solution {
 public:
  vector<int> getSneakyNumbers(vector<int>& nums) {
    int size = nums.size() - 2;
    int y = 0;
    for (int x : nums) {
      y ^= x;
    }
    for (int i = 0; i < size; i++) {
      y ^= i;
    }
    int lowBit = y & (-y);
    int x1 = 0, x2 = 0;
    for (int x : nums) {
      if (x & lowBit) {
        x1 ^= x;
      } else {
        x2 ^= x;
      }
    }
    for (int i = 0; i < size; i++) {
      if (i & lowBit) {
        x1 ^= i;
      } else {
        x2 ^= i;
      }
    }
    return {x1, x2};
  }
};

// use math
// time : O(N)
// space : O(1)
class Solution {
 public:
  vector<int> getSneakyNumbers(vector<int>& nums) {
    int size = nums.size() - 2;

    int sum = 0, squaredSum = 0;
    for (int x : nums) {
      sum += x;
      squaredSum += x * x;
    }

    // remain x1 + x2
    int diff = sum - size * (size - 1) / 2;
    // remain x1^2 + x2^2
    int sqDiff = squaredSum - size * (size - 1) * (2 * size - 1) / 6;

    // x1 + x2 = diff
    // x1^2 + x2^2 = sqDiff
    int x1 = (diff - sqrt(2 * sqDiff - diff * diff)) / 2;
    int x2 = (diff + sqrt(2 * sqDiff - diff * diff)) / 2;
    return {x1, x2};
  }
};