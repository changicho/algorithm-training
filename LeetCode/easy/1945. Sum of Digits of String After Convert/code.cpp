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

// use simulation
// time : O(N * K)
// space : O(N)
class Solution {
 public:
  int getLucky(string s, int k) {
    string sum = "";
    for (char &c : s) {
      sum += to_string(int(c - 'a') + 1);
    }

    while (k--) {
      int newSum = 0;
      for (char &c : sum) {
        newSum += (c - '0');
      }
      sum = to_string(newSum);
    }
    return stoi(sum);
  }
};

// use simulation (int)
// time : O(N * K)
// space : O(1)
class Solution {
 public:
  int getLucky(string s, int k) {
    int sum = 0;
    k--;
    for (char &c : s) {
      int num = c - 'a' + 1;
      sum += (num / 10) + num % 10;
    }

    while (k--) {
      int newSum = 0;
      while (sum > 0) {
        newSum += sum % 10;
        sum /= 10;
      }
      sum = newSum;
    }
    return sum;
  }
};