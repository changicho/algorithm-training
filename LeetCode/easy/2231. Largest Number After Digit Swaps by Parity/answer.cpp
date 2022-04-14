#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int largestInteger(int num) {
    string numStr = to_string(num);

    int length = numStr.length();

    vector<bool> isOdd(length);
    vector<char> odds, evens;
    for (int i = 0; i < length; i++) {
      if ((numStr[i] - '0') % 2 == 1) {
        isOdd[i] = true;
        odds.push_back(numStr[i]);
      } else {
        isOdd[i] = false;
        evens.push_back(numStr[i]);
      }
    }

    sort(odds.begin(), odds.end());
    sort(evens.begin(), evens.end());

    int largest = 0;
    for (int i = 0; i < length; i++) {
      if (isOdd[i]) {
        largest = largest * 10 + odds.back() - '0';
        odds.pop_back();
      } else {
        largest = largest * 10 + evens.back() - '0';
        evens.pop_back();
      }
    }

    return largest;
  }
};

// use counting sort
// time : O(N)
// space : O(N)
class Solution {
 private:
  vector<int> countingSort(vector<int> &v) {
    vector<int> ret;
    for (int i = 0; i < 10; i++) {
      for (int c = 0; c < v[i]; c++) {
        ret.push_back(i);
      }
    }
    return ret;
  }

 public:
  int largestInteger(int num) {
    string numStr = to_string(num);
    int length = numStr.length();

    vector<bool> isOdd(length);
    vector<int> oddsCount(10, 0), evensCount(10, 0);
    for (int i = 0; i < length; i++) {
      if ((numStr[i] - '0') % 2 == 1) {
        isOdd[i] = true;
        oddsCount[numStr[i] - '0']++;
      } else {
        isOdd[i] = false;
        evensCount[numStr[i] - '0']++;
      }
    }

    vector<int> odds = countingSort(oddsCount),
                evens = countingSort(evensCount);

    int largest = 0;
    for (int i = 0; i < length; i++) {
      if (isOdd[i]) {
        largest = largest * 10 + odds.back();
        odds.pop_back();
      } else {
        largest = largest * 10 + evens.back();
        evens.pop_back();
      }
    }

    return largest;
  }
};