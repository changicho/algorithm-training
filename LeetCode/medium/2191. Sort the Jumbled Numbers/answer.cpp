#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use convert & sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
  struct Number {
    int origin, converted;

    bool operator<(const Number &b) const { return converted < b.converted; }
  };

 public:
  vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
    vector<Number> datum;

    for (int &num : nums) {
      string converted = "";
      for (char c : to_string(num)) {
        converted += mapping[c - '0'] + '0';
      }

      datum.push_back({num, stoi(converted)});
    }

    // stable_sort(datum.begin(), datum.end());
    sort(datum.begin(), datum.end());

    vector<int> answer;
    for (Number &d : datum) {
      answer.push_back(d.origin);
    }

    return answer;
  }
};

// use convert & sort (with index)
// time : O(N * log_2(N))
// space : O(N)
class Solution {
  struct Number {
    int origin, converted, index;

    bool operator<(const Number &b) const {
      if (converted == b.converted) {
        return index < b.index;
      }
      return converted < b.converted;
    }
  };

 public:
  vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
    vector<Number> datum;

    for (int &num : nums) {
      string converted = "";
      for (char c : to_string(num)) {
        converted += mapping[c - '0'] + '0';
      }

      datum.push_back({num, stoi(converted), (int)datum.size()});
    }

    sort(datum.begin(), datum.end());

    vector<int> answer;
    for (Number &d : datum) {
      answer.push_back(d.origin);
    }

    return answer;
  }
};