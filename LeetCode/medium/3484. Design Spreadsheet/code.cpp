#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash map
// time : O(N * L)
// space : O(N * L)
class Spreadsheet {
 private:
  unordered_map<string, int> um;

  vector<string> split(string &s) {
    int size = s.size();
    vector<string> ret;
    string temp = "";
    for (int i = 1; i <= size; i++) {
      if (i == size || s[i] == '+') {
        ret.push_back(temp);
        temp = "";
      } else {
        temp += s[i];
      }
    }

    return ret;
  }

  bool isNumber(string &s) {
    for (char &c : s) {
      if (!isdigit(c)) return false;
    }
    return true;
  }

  int pick(string &s) {
    if (isNumber(s)) {
      return stoi(s);
    }
    return um[s];
  }

 public:
  Spreadsheet(int rows) {}

  void setCell(string cell, int value) { um[cell] = value; }

  void resetCell(string cell) { um[cell] = 0; }

  int getValue(string formula) {
    vector<string> arr = split(formula);

    int first = pick(arr[0]);
    if (arr.size() == 1) {
      return first;
    }
    int second = pick(arr[1]);

    return first + second;
  }
};
