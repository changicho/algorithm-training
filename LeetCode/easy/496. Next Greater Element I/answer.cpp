#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use stack & hash map

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