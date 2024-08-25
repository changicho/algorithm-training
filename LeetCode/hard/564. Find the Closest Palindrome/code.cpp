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

// use greedy brute force
// time : O(3^(N/2))
// space : O(N)
class Solution {
 private:
  string answer = "";

  long long getDiff(string &a, string &b) { return abs(stoll(a) - stoll(b)); }

  void recursive(int i, string &n, string &temp) {
    int size = temp.size();
    int rI = size - 1 - i;

    if (i > size / 2) {
      long long originDiff = getDiff(answer, n);
      long long diff = getDiff(temp, n);

      if (diff == 0) return;

      if (originDiff > diff) {
        answer = temp;
      } else if (originDiff == diff) {
        if (stoll(answer) > stoll(temp)) {
          answer = temp;
        }
      }

      return;
    }

    int num = temp[i] - '0';

    vector<char> nexts = {char(num + '0'), char((num + 1) % 10 + '0'),
                          char((num - 1 + 10) % 10 + '0')};

    char origin = temp[i];
    for (char &c : nexts) {
      if (i == 0 && c == '0') continue;
      temp[i] = c;
      temp[rI] = c;

      recursive(i + 1, n, temp);
    }
    temp[i] = origin;
  }

 public:
  string nearestPalindromic(string n) {
    int size = n.size();
    answer = string(size, '0');

    string temp = n;
    recursive(0, n, temp);

    temp = string(size - 1, '9');
    if (temp.size() > 0) {
      recursive(0, n, temp);
    }
    temp = string(size + 1, '1');
    if (temp.size() > 0) {
      recursive(0, n, temp);
    }

    return answer;
  }
};

// use greedy mid change
// time : O(N)
// space : O(N)
class Solution {
 private:
  long long makePalindrome(long long number, int size) {
    string ret = to_string(number);

    int retSize = ret.size() - size % 2;
    for (int i = retSize - 1; i >= 0; i--) {
      ret += ret[i];
    }
    return stoll(ret);
  }

 public:
  string nearestPalindromic(string n) {
    int size = n.size();
    long long num = stoll(n);

    long long half = stoll(n.substr(0, (size + 1) / 2));

    long long lengthMinus = pow(10, size - 1) - 1;
    long long lengthPlus = pow(10, size) + 1;
    long long palindrome = makePalindrome(half, size);
    long long palindromePlus = makePalindrome(half + 1, size);
    long long palindromeMinus = makePalindrome(half - 1, size);

    vector<long long> targets = {lengthMinus, lengthPlus, palindrome,
                                 palindromePlus, palindromeMinus};

    long long answer = lengthPlus;

    for (long long &target : targets) {
      long long diff = abs(num - target);
      long long ansDiff = abs(answer - num);

      if (diff == 0) continue;

      if (diff < ansDiff) {
        answer = target;
      } else if (diff == ansDiff) {
        answer = min(answer, target);
      }
    }

    return to_string(answer);
  }
};