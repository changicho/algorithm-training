#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sliding window
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> getAverages(vector<int>& nums, int k) {
    int size = nums.size();

    if (size < 2 * k + 1) {
      return vector<int>(size, -1);
    }

    vector<int> answer;
    for (int i = 0; i < k; i++) {
      answer.push_back(-1);
    }

    long long sum = 0;
    for (int i = 0; i < 2 * k + 1; i++) {
      sum += nums[i];
    }
    answer.push_back(sum / (2 * k + 1));

    int left = 0, right = 2 * k + 1;
    while (right < size) {
      sum += nums[right];
      right++;
      sum -= nums[left];
      left++;

      answer.push_back(sum / (2 * k + 1));
    }
    for (int i = 0; i < k; i++) {
      answer.push_back(-1);
    }
    return answer;
  }
};

// use sliding window
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> getAverages(vector<int>& nums, int k) {
    int size = nums.size();
    int windowSize = 2 * k + 1;

    if (k == 0) {
      return nums;
    }

    vector<int> answer(size, -1);
    if (windowSize > size) {
      return answer;
    }

    long long sum = 0;
    for (int i = 0; i < windowSize; ++i) {
      sum += nums[i];
    }
    answer[k] = sum / windowSize;

    for (int right = windowSize; right < size; ++right) {
      int left = right - windowSize;
      sum -= nums[left];
      sum += nums[right];

      answer[right - k] = sum / windowSize;
    }

    return answer;
  }
};