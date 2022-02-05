#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use custom sort

class Solution {
 public:
  string customSortString(string order, string s) {
    vector<int> orders(26, 100);
    for (int i = 0; i < order.length(); i++) {
      char c = order[i];

      orders[c - 'a'] = i;
    }

    sort(s.begin(), s.end(),
         [&](char a, char b) { return orders[a - 'a'] < orders[b - 'a']; });

    return s;
  }
};

// use counting sort

class Solution {
 public:
  string customSortString(string order, string s) {
    vector<int> cnt(128, 0);

    for (char &c : s) {
      cnt[c]++;
    }

    int index = 0;

    for (char &c : order) {
      while (cnt[c] > 0) {
        s[index++] = c;
        cnt[c]--;
      }
    }

    for (char c = 'a'; c <= 'z'; ++c) {
      while (cnt[c] > 0) {
        s[index++] = c;
        cnt[c]--;
      }
    }

    return s;
  }
};