#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force

class Solution {
 public:
  int maximumSwap(int num) {
    string numStr = to_string(num);
    int length = numStr.length();

    int answer = num;
    for (int from = 0; from < length; from++) {
      for (int to = 0; to < length; to++) {
        swap(numStr[from], numStr[to]);
        answer = max(answer, stoi(numStr));
        swap(numStr[from], numStr[to]);
      }
    }

    return answer;
  }
};

// use one pass

class Solution {
 public:
  int maximumSwap(int num) {
    string s = to_string(num);
    int length = s.length();
    // index of maximum digit in range i ~ (size - 1)
    vector<int> maximumIdx(length, length - 1);

    for (int i = length - 2; i >= 0; i--) {
      maximumIdx[i] = s[i] > s[maximumIdx[i + 1]] ? i : maximumIdx[i + 1];
    }

    int i = 0;
    while (i < length && s[i] >= s[maximumIdx[i]]) {
      i++;
    }
    if (i < length) {
      swap(s[i], s[maximumIdx[i]]);
    }

    int answer = stoi(s);
    return answer;
  }
};