#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N)
// space : O(1)
class Solution {
 private:
  int minimumCount(string &num, string suffix) {
    int idx = suffix.size() - 1;

    int count = 0;
    for (int i = num.size() - 1; i >= 0 && idx >= 0; i--) {
      if (num[i] == suffix[idx]) {
        idx--;
      } else {
        count++;
      }
    }

    if (idx >= 0) return num.size();

    return count;
  }

 public:
  int minimumOperations(string num) {
    int size = num.size();

    int answer = size;

    vector<string> suffixes = {"00", "25", "50", "75"};

    for (string &suffix : suffixes) {
      int count = minimumCount(num, suffix);

      answer = min(answer, count);
    }

    int zeroCount = 0;
    for (char &c : num) {
      if (c == '0') zeroCount++;
    }
    answer = min(answer, size - zeroCount);

    return answer;
  }
};