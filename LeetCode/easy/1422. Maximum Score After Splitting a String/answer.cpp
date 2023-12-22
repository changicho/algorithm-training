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
  int maxScore(string s) {
    int size = s.size();
    vector<int> zeros(size), ones(size);
    for (int i = 0; i < size; i++) {
      if (i > 0) zeros[i] = zeros[i - 1];
      zeros[i] += s[i] == '0';
    }
    for (int i = size - 1; i >= 0; i--) {
      if (i < size - 1) ones[i] = ones[i + 1];
      ones[i] += s[i] == '1';
    }

    int answer = 0;
    for (int i = 0; i < size - 1; i++) {
      int left = zeros[i], right = ones[i + 1];
      answer = max(answer, left + right);
    }
    return answer;
  }
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maxScore(string s) {
    int size = s.size();

    int zero = 0, one = 0;
    for (int i = 0; i < size; i++) {
      one += s[i] == '1';
    }

    int answer = 0;
    for (int i = 0; i < size - 1; i++) {
      if (s[i] == '0') {
        zero++;
      } else {
        one--;
      }

      answer = max(answer, zero + one);
    }
    return answer;
  }
};