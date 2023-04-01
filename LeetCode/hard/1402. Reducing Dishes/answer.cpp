#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort & suffix sum
// time : O(N * log_2(N))
// space : O(1)
class Solution {
 public:
  int maxSatisfaction(vector<int>& satisfaction) {
    int size = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());

    int suffixSum = 0;
    int start = -1;
    for (int i = size - 1; i >= 0; i--) {
      suffixSum += satisfaction[i];

      if (suffixSum < 0) {
        break;
      }
      start = i;
    }

    if (start == -1) return 0;

    int answer = 0;
    for (int i = start; i < size; i++) {
      answer += satisfaction[i] * (i - start + 1);
    }
    return answer;
  }
};

// use sort & brute force
// time : O(N^2)
// space : O(1)
class Solution {
 public:
  int maxSatisfaction(vector<int>& satisfaction) {
    int size = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());

    int answer = 0;
    for (int start = 0; start < size; start++) {
      int temp = 0;
      for (int i = start; i < size; i++) {
        temp += satisfaction[i] * (i - start + 1);
      }
      answer = max(answer, temp);
    }

    return answer;
  }
};