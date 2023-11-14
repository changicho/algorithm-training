#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N^3)
// space : O(1)
class Solution {
 public:
  int distributeCandies(int n, int limit) {
    int answer = 0;
    for (int i = 0; i <= limit; i++) {
      for (int j = 0; j <= limit; j++) {
        for (int k = 0; k <= limit; k++) {
          if (i + j + k != n) continue;
          answer++;
        }
      }
    }
    return answer;
  }
};