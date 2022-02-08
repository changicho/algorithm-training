#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use counting

class Solution {
 public:
  char findTheDifference(string s, string t) {
    int length = s.length();

    unordered_map<char, int> countS, countT;
    for (char &c : s) {
      countS[c]++;
    }
    for (char &c : t) {
      countT[c]++;
    }

    for (char c = 'a'; c <= 'z'; c++) {
      if (countS[c] < countT[c]) return c;
    }
    return 'a';
  }
};

// use sort

class Solution {
 public:
  char findTheDifference(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    // use two pointer
    int length = s.length();

    int idxS = 0, idxT = 0;

    while (idxS < length && idxT < length + 1 && s[idxS] == t[idxT]) {
      idxS++;
      idxT++;
    }

    return t[idxT];
  }
};

// use XOR

class Solution {
 public:
  char findTheDifference(string s, string t) {
    int bit = 0;
    for (char &c : s) {
      bit ^= c;
    }
    for (char &c : t) {
      bit ^= c;
    }

    return (char)bit;
  }
};