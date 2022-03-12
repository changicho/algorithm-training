#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use brute force
// time : O(N * M)
// space : O(N)
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> answer(nums1.size(), -1);
    for (int idx = 0; idx < nums1.size(); idx++) {
      int num = nums1[idx];
      bool isFind = false;

      for (int i = 0; i < nums2.size(); i++) {
        if (nums2[i] == num) {
          isFind = true;
          continue;
        }
        if (nums2[i] > num && isFind) {
          answer[idx] = nums2[i];
          break;
        }
      }
    }

    return answer;
  }
};

// use monotonic stack & hash map
// time : O(N + M)
// space : O(N + M)
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int size = nums2.size();

    vector<int> nextGreaters(size, 0);
    // key : index, value : next greater element
    unordered_map<int, int> nextGreaterByIndex;
    stack<int> minStack;

    for (int i = 0; i < size; i++) {
      while (!minStack.empty() && nums2[minStack.top()] < nums2[i]) {
        int target = minStack.top();
        minStack.pop();
        nextGreaterByIndex[nums2[target]] = nums2[i];
      }

      minStack.push(i);
    }

    vector<int> answers;
    for (int& num : nums1) {
      answers.emplace_back(
          nextGreaterByIndex.count(num) ? nextGreaterByIndex[num] : -1);
    }
    return answers;
  }
};