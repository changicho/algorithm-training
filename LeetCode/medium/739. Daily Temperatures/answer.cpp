#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use stack
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int size = temperatures.size();
    stack<int> stk;

    vector<int> answer(size);
    for (int i = 0; i < size; i++) {
      while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
        answer[stk.top()] = i - stk.top();
        stk.pop();
      }

      stk.push(i);
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