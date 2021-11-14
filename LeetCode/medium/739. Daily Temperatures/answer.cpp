#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use stack

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int size = temperatures.size();
    vector<int> answer(size, 0);

    stack<int> st;
    st.push(0);

    for (int i = 1; i < size; i++) {
      while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
        int idx = st.top();
        st.pop();

        answer[idx] = i - idx;
      }

      st.push(i);
    }

    return answer;
  }
};

// use reverse one pass, space optimize

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int size = temperatures.size();
    int hottest = 0;
    vector<int> answer(size, 0);

    for (int i = size - 1; i >= 0; i--) {
      int currentTemp = temperatures[i];

      if (currentTemp >= hottest) {
        hottest = currentTemp;
        continue;
      }

      int days = 1;
      while (temperatures[i + days] <= currentTemp) {
        days += answer[i + days];
      }
      answer[i] = days;
    }

    return answer;
  }
};