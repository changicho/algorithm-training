#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// bit convert & one pass
// time : O(N)
// space : O(1)
class Solution {
 private:
  bool check(char a, char b) {
    string sa = "", sb = "";

    for (int i = 0; i < 8; i++) {
      sa += a % 2 + '0';
      sb += b % 2 + '0';

      a /= 2;
      b /= 2;
    }

    reverse(sb.begin(), sb.end());

    return sa == sb;
  }

 public:
  bool isPalindromic(string s) {
    int size = s.size();

    for (int i = 0; i <= size / 2; i++) {
      char l = s[i], r = s[size - 1 - i];

      if (check(l, r) == false) return false;
    }

    return true;
  }
};

// bit check & one pass
// time : O(N)
// space : O(1)
class Solution {
 private:
  bool check(char a, char b) {
    for (int bit = 7; bit >= 0; bit--) {
      int left = (a >> bit) & 1;
      int right = (b >> (7 - bit)) & 1;

      if (left != right) return false;
    }
    return true;
  }

 public:
  bool isPalindromic(string s) {
    int size = s.size();

    for (int i = 0; i <= size / 2; i++) {
      char l = s[i], r = s[size - 1 - i];

      if (check(l, r) == false) return false;
    }

    return true;
  }
};