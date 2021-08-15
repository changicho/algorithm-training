#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use DFS

class Solution {
 private:
  vector<string> answer;
  unordered_map<char, int> um;

  void recursive(int n, string s) {
    if (s.length() == n) {
      answer.emplace_back(s);
      return;
    }

    for (auto &cur : um) {
      if (cur.second >= 2) {
        char target = cur.first;
        um[cur.first] -= 2;

        recursive(n, target + s + target);

        um[cur.first] += 2;
      }
    }
  }

 public:
  vector<string> generatePalindromes(string s) {
    for (char c : s) {
      um[c] += 1;
    }

    int oddCount = 0;
    string center = "";
    for (auto &cur : um) {
      if (cur.second % 2 == 1) {
        oddCount += 1;
        center += cur.first;
      }
    }

    if (oddCount >= 2) return answer;

    recursive(s.length(), center);

    return answer;
  }
};

// use permutation

class Solution {
 public:
  vector<string> generatePalindromes(string s) {
    vector<string> answer;
    unordered_map<char, int> um;

    // step1. count characters
    for (char c : s) {
      um[c] += 1;
    }

    int oddCount = 0;
    string center = "";
    string half = "";

    // step2. count odd & set middle character & half string
    for (auto &cur : um) {
      if (cur.second % 2 == 1) {
        oddCount += 1;

        center += cur.first;
      } else {
        for (int i = 0; i < cur.second / 2; i++) {
          half += cur.first;
        }
      }
    }

    // if unable to make permutation return
    if (oddCount >= 2) return {};

    // make half from middle character
    um[center.front()] -= 1;
    if (um[center.front()] > 0) {
      for (int i = 0; i < um[center.front()] / 2; i++) {
        half += center.front();
      }
    }

    // step3. make permutation of half string
    sort(half.begin(), half.end());

    do {
      // current answer is (half + center + half')
      string cur = half + center + half;
      reverse(cur.begin() + (cur.length() + 1) / 2, cur.end());
      answer.emplace_back(cur);
    } while (next_permutation(half.begin(), half.end()));

    return answer;
  }
};