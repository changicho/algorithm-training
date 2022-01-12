#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// use stack

class Solution {
 public:
  vector<int> nextLargerNodes(ListNode* head) {
    ListNode* cur = head;
    vector<int> nums;
    while (cur) {
      nums.push_back(cur->val);
      cur = cur->next;
    }

    int size = nums.size();
    vector<int> answer(size, 0);

    stack<int> st;
    st.push(0);

    for (int i = 1; i < size; i++) {
      while (!st.empty() && nums[st.top()] < nums[i]) {
        int target = st.top();
        answer[target] = nums[i];
        st.pop();
      }
      st.push(i);
    }

    return answer;
  }
};