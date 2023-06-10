#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass & bit compare
// time : O(1)
// space : O(1)
class Solution {
 public:
  int minFlips(int a, int b, int c) {
    int answer = 0;
    for (int i = 0; i < 32; i++) {
      int curA = a % 2, curB = b % 2, curC = c % 2;

      if (curC == 0) {
        answer += curA + curB;
      } else {
        if (curA == 0 && curB == 0) {
          answer++;
        }
      }

      a /= 2, b /= 2, c /= 2;
    }
    return answer;
  }
};