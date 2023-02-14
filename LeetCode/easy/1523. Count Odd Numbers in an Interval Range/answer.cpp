#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use math
// time : O(1)
// space : O(1)
class Solution {
 public:
  int countOdds(int low, int high) {
    int answer = 0;
    if (low % 2 == 1) {
      answer += 1;
      low++;
    }

    int diff = high - low + 1;
    answer += diff / 2;

    return answer;
  }
};