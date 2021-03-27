#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int length = digits.size();
    digits[length - 1] += 1;
    bool hasNewOne = false;
    for (int i = length - 1; i >= 0; i--) {
      if (digits[i] >= 10) {
        digits[i] -= 10;

        if (i - 1 >= 0) {
          digits[i - 1] += 1;
        } else {
          hasNewOne = true;
        }
      } else {
        break;
      }
    }

    if (hasNewOne) {
      digits.insert(digits.begin(), 1);
    }

    return digits;
  }
};