#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use simulation
// time : O(log_2(N))
// space : O(1)
class Solution {
 public:
  int numberOfMatches(int n) {
    int answer = 0;
    while (n > 1) {
      answer += n / 2;
      n -= n / 2;
    }
    return answer;
  }
};

// use math
// time : O(1)
// space : O(1)
class Solution {
 public:
  int numberOfMatches(int n) { return n - 1; }
};