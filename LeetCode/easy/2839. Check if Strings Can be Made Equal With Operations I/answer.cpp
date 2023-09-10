#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use compare part
// time : O(N)
// space : O(N)
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