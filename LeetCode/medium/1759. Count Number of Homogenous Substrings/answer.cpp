#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 private:
  const int MOD = 1e9 + 7;

 public:
  int countHomogenous(string s) {
    char before = s.front();
    int count = 0;

    long long answer = 0;
    for (char &c : s) {
      if (c == before) {
        count++;
      } else {
        long long cur = ((long long)count * (count + 1)) / 2;
        answer += cur;
        answer %= MOD;

        before = c;
        count = 1;
      }
    }
    long long cur = ((long long)count * (count + 1)) / 2;
    answer += cur;
    answer %= MOD;

    return (int)answer;
  }
};