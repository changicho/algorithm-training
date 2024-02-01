#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(L^2)
// space : O(L^2)
class Solution {
 public:
  vector<string> generatePossibleNextMoves(string currentState) {
    int size = currentState.size();

    vector<string> answer;
    for (int i = 0; i < size - 1; i++) {
      if (currentState[i] == '+' && currentState[i] == currentState[i + 1]) {
        currentState[i] = currentState[i + 1] = '-';

        answer.push_back(currentState);

        currentState[i] = currentState[i + 1] = '+';
      }
    }

    return answer;
  }
};