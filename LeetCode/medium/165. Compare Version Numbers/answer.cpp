#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use split, two pass
// time : O(N + M)
// space : O(N + M)
class Solution {
 private:
  vector<int> convert(string version) {
    vector<int> ret;

    string temp = "";
    for (char &c : version) {
      if (c == '.') {
        ret.push_back(stoi(temp));
        temp = "";
        continue;
      }
      temp += c;
    }

    if (temp != "") {
      ret.push_back(stoi(temp));
    }

    return ret;
  }

 public:
  int compareVersion(string version1, string version2) {
    vector<int> arr1 = convert(version1), arr2 = convert(version2);

    while (arr1.size() < arr2.size()) {
      arr1.push_back(0);
    }
    while (arr2.size() < arr1.size()) {
      arr2.push_back(0);
    }

    int size = min(arr1.size(), arr2.size());

    for (int i = 0; i < size; i++) {
      if (arr1[i] < arr2[i]) {
        return -1;
      } else if (arr1[i] > arr2[i]) {
        return 1;
      }
    }
    return 0;
  }
};

// use two pointer
// time : O(N + M)
// space : O(1)
class Solution {
 public:
  int compareVersion(string s1, string s2) {
    int length1 = s1.length(), length2 = s2.length();

    int idx1 = 0, idx2 = 0;
    while (idx1 < length1 || idx2 < length2) {
      int number1 = 0, number2 = 0;

      // get next number of s1
      while (idx1 < length1 && s1[idx1] != '.') {
        number1 = number1 * 10 + (s1[idx1] - '0');
        idx1++;
      }
      // get next number of s2
      while (idx2 < length2 && s2[idx2] != '.') {
        number2 = number2 * 10 + (s2[idx2] - '0');
        idx2++;
      }

      if (number1 > number2) {
        return 1;
      } else if (number1 < number2) {
        return -1;
      }

      number1 = 0, number2 = 0;

      idx1++, idx2++;
    }

    return 0;
  }
};