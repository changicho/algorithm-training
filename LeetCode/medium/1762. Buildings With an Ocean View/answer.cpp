#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use stack

class Solution {
 public:
  vector<int> findBuildings(vector<int>& heights) {
    int size = heights.size();
    vector<int> answer;

    for (int i = 0; i < size; i++) {
      int h = heights[i];
      while (!answer.empty() && heights[answer.back()] <= h) {
        answer.pop_back();
      }
      answer.push_back(i);
    }

    return answer;
  }
};

// use monotonic stack

class Solution {
 public:
  vector<int> findBuildings(vector<int>& heights) {
    int size = heights.size();
    vector<int> answer;
    stack<int> st;

    for (int i = size - 1; i >= 0; i--) {
      // remove lower than current height
      while (!st.empty() && heights[st.top()] < heights[i]) {
        st.pop();
      }

      // if stack empty, there is no building to the right
      if (st.empty()) answer.push_back(i);

      // push current index
      st.push(i);
    }

    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// use monotonic stack with space optimize

class Solution {
 public:
  vector<int> findBuildings(vector<int>& heights) {
    int size = heights.size();
    vector<int> answer;
    int maxHeight = -1;

    for (int i = size - 1; i >= 0; i--) {
      if (maxHeight >= heights[i]) continue;

      answer.push_back(i);
      // update
      maxHeight = heights[i];
    }

    reverse(answer.begin(), answer.end());
    return answer;
  }
};