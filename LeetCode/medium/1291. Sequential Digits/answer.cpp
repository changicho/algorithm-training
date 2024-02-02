#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force with digit length
// time : O(1)
// space : O(1)
class Solution {
 public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> answer;

    int lowLen = log10(low) + 1, highLen = log10(high) + 1;

    for (int length = lowLen; length <= highLen; length++) {
      for (int start = 1; start <= 9 - length + 1; start++) {
        string cur = string(length, start + '0');
        for (int i = 1; i < length; i++) {
          cur[i] = cur[i - 1] + 1;
        }

        int num = stoi(cur);
        if (low <= num && num <= high) {
          answer.push_back(num);
        }
      }
    }
    return answer;
  }
};