#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(R + L)
// space : O(1)
class Solution {
 public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int answer = 0;
    for (int& l : left) {
      answer = max(answer, l);
    }
    for (int& r : right) {
      answer = max(answer, (n - r));
    }
    return answer;
  }
};