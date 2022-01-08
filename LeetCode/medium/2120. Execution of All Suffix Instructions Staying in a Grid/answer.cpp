#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use simulation

class Solution {
 public:
  vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
    int length = s.length();

    vector<int> answer;
    for (int left = 0; left < length; left++) {
      int y = startPos[0], x = startPos[1];
      int count = 0;

      for (int i = left; i < length; i++) {
        char operation = s[i];

        switch (operation) {
          case 'U': {
            y -= 1;
            break;
          }
          case 'R': {
            x += 1;
            break;
          }
          case 'D': {
            y += 1;
            break;
          }
          case 'L': {
            x -= 1;
            break;
          }
        }

        if (y < 0 || y >= n || x < 0 || x >= n) break;
        count++;
      }

      answer.push_back(count);
    }

    return answer;
  }
};