#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use compare part
// time : O(1)
// space : O(1)
class Solution {
 private:
  string convert(string s) {
    string part1 = "", part2 = "";

    part1 += s[0];
    part1 += s[2];
    part2 += s[1];
    part2 += s[3];

    sort(part1.begin(), part1.end());
    sort(part2.begin(), part2.end());

    return part1 + part2;
  }

 public:
  bool canBeEqual(string s1, string s2) { return convert(s1) == convert(s2); }
};

// greedy compare
// time : O(1)
// space : O(1)
class Solution {
 public:
  bool canBeEqual(string s1, string s2) {
    if (s1[0] != s2[0]) {
      swap(s1[0], s1[2]);
    }
    if (s1[1] != s2[1]) {
      swap(s1[1], s1[3]);
    }

    return s1 == s2;
  }
};