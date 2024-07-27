#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass with diff before
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minNumberOperations(vector<int>& target) {
    int answer = 0;
    int before = 0;

    for (int& num : target) {
      if (before < num) {
        answer += (num - before);
      }
      before = num;
    }

    return answer;
  }
};