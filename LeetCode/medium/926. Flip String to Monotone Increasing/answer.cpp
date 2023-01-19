#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use prefix sum
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minFlipsMonoIncr(string s) {
    int size = s.size();
    vector<int> prefixSums(size + 1, 0);

    for (int i = 0; i < size; i++) {
      prefixSums[i + 1] = prefixSums[i] + (s[i] == '1');
    }

    int answer = prefixSums[size];
    for (int i = 0; i < size; i++) {
      int left = prefixSums[i];                      // 0 ~ (i-1)
      int right = prefixSums[size] - prefixSums[i];  // i ~ (size-1)
      right = (size - i) - right;

      answer = min(answer, left + right);
    }
    return answer;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minFlipsMonoIncr(string s) {
    int size = s.size();

    int leftOnes = 0, rightOnes = 0;
    for (int i = 0; i < size; i++) {
      rightOnes += (s[i] == '1');
    }

    int answer = size - rightOnes;
    for (int i = 0; i < size; i++) {
      if (s[i] == '1') {
        leftOnes++;
        rightOnes--;
      }

      int rightLength = size - 1 - i;

      answer = min(answer, leftOnes + (rightLength - rightOnes));
    }
    return answer;
  }
};