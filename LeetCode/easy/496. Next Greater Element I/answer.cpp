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
    unordered_map<int, int> nextPair;
    stack<int> st;

    for (int i = 0; i < size; i++) {
      while (!st.empty() && nums2[st.top()] < nums2[i]) {
        int target = st.top();
        st.pop();
        nextPair[nums2[target]] = nums2[i];
      }

      st.push(i);
    }

    vector<int> answers;
    for (int& num : nums1) {
      answers.emplace_back(nextPair.count(num) ? nextPair[num] : -1);
    }
    return answers;
  }
};