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

// use greedy
// time : O(N^2)
// space : O(N)
class Solution {
  string convert(int &num) {
    int size = 7;
    string res = to_string(num);
    return string(size - res.size(), '0') + res;
  }

  string getKey(string &num) {
    string key = string(10, 0);
    for (char &c : num) {
      key[c - '0']++;
    }
    return key;
  }

  bool isEqual(string &first, string &second) {
    if (first == second) return true;
    int size = first.size();

    int diff = 0;
    string diffA = "", diffB = "";
    for (int i = 0; i < size; i++) {
      if (first[i] != second[i]) {
        diff++;
        diffA += first[i];
        diffB += second[i];
      }
    }
    if (diff <= 3) return true;
    if (diff > 4) return false;

    for (int i = 1; i < 4; i++) {
      if (diffA[0] == diffB[i] && diffB[0] == diffA[i]) return true;
    }

    return false;
  }

 public:
  int countPairs(vector<int> &nums) {
    int size = nums.size();
    int answer = 0;

    unordered_map<string, unordered_map<string, int>> um;
    for (int &num : nums) {
      string converted = convert(num);
      string key = getKey(converted);

      um[key][converted]++;
    }

    for (auto &[key, m] : um) {
      vector<pair<string, int>> arr;
      for (auto &[s, c] : m) {
        arr.push_back({s, c});

        answer += c * (c - 1) / 2;
      }

      int size = arr.size();
      for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
          if (isEqual(arr[i].first, arr[j].first)) {
            answer += arr[i].second * arr[j].second;
          }
        }
      }
    }

    return answer;
  }
};