#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<int> lexicalOrder(int n) {
    vector<string> arr;
    for (int i = 1; i <= n; i++) {
      arr.push_back(to_string(i));
    }

    sort(arr.begin(), arr.end());
    vector<int> ret;
    for (string &num : arr) {
      ret.push_back(stoi(num));
    }
    return ret;
  }
};

// use DFS
// time : O(N)
// space : O(log_10(N))
class Solution {
 private:
  vector<int> answer;

  void recursive(int num, int n) {
    answer.push_back(num);

    for (int i = 0; i <= 9; i++) {
      int next = num * 10 + i;
      if (next <= n) recursive(next, n);
    }
  }

 public:
  vector<int> lexicalOrder(int n) {
    for (int i = 1; i <= 9; i++) {
      if (i > n) break;

      recursive(i, n);
    }
    return answer;
  }
};

// use iteration
// time : O(N)
// space : O(1)
class Solution {
 public:
  vector<int> lexicalOrder(int n) {
    vector<int> answer;
    int cur = 1;

    for (int i = 0; i < n; i++) {
      answer.push_back(cur);

      if (cur * 10 <= n) {
        cur *= 10;
      } else {
        while (cur % 10 == 9 || cur >= n) {
          cur /= 10;
        }
        cur += 1;
      }
    }

    return answer;
  }
};