#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O((N + M) * min(N, M))
// space : O(N + M)
class Solution {
 private:
  bool canDivide(string base, string token) {
    int length = base.size();

    if (length % token.length() != 0) return false;
    int div = length / token.length();

    string temp = "";
    for (int i = 0; i < div; i++) {
      temp += token;
    }

    return temp == base;
  }

 public:
  string gcdOfStrings(string str1, string str2) {
    if (str2.length() > str1.length()) swap(str1, str2);

    string token = "";
    string answer = "";
    for (int i = 0; i < str2.size(); i++) {
      token += str2[i];

      if (canDivide(str1, token) && canDivide(str2, token)) {
        answer = token;
      }
    }
    return answer;
  }
};

// use gcd
// time : O(N + M)
// space : O(N + M)
class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1) {
      return "";
    }

    int gcdLength = gcd(str1.size(), str2.size());
    return str1.substr(0, gcdLength);
  }
};