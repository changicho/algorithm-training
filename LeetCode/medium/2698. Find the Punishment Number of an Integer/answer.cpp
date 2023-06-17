#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N * 2^(log_10(N^2)))
// time : O(log_10(N^2))
class Solution {
 private:
  void recursive(string &num, int temp, int sum, int index, bool &isValid) {
    int size = num.size();

    if (index == size) {
      int origin = sqrt(stoi(num));

      sum += temp;
      if (sum == origin) {
        isValid = true;
      }
      return;
    }

    int beforeTemp = temp;
    temp = temp * 10 + num[index] - '0';
    recursive(num, temp, sum, index + 1, isValid);

    temp = beforeTemp;
    sum += temp;
    temp = num[index] - '0';
    recursive(num, temp, sum, index + 1, isValid);
  }

  bool check(int num) {
    int converted = num * num;

    string str = to_string(converted);

    bool isValid = false;
    recursive(str, 0, 0, 0, isValid);

    return isValid;
  }

 public:
  int punishmentNumber(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
      if (check(i)) {
        answer += i * i;
      }
    }
    return answer;
  }
};