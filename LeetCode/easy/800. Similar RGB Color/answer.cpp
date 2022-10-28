#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(1)
// space : O(1)
class Solution {
 private:
  char convert(int num) {
    if (num < 10) return '0' + num;
    return 'a' + (num - 10);
  }

 public:
  string similarRGB(string color) {
    int red = stoi(color.substr(1, 2), NULL, 16);
    int green = stoi(color.substr(3, 2), NULL, 16);
    int blue = stoi(color.substr(5, 2), NULL, 16);

    string answer = "#000000";
    for (int r = 0, minimum = INT_MAX; r < 16; r++) {
      int diffR = (red - (r * 16 + r));
      diffR *= diffR;

      if (diffR < minimum) {
        minimum = diffR;
        answer[1] = answer[2] = convert(r);
      }
    }
    for (int g = 0, minimum = INT_MAX; g < 16; g++) {
      int diffG = (green - (g * 16 + g));
      diffG *= diffG;

      if (diffG < minimum) {
        minimum = diffG;
        answer[3] = answer[4] = convert(g);
      }
    }
    for (int b = 0, minimum = INT_MAX; b < 16; b++) {
      int diffB = (blue - (b * 16 + b));
      diffB *= diffB;

      if (diffB < minimum) {
        minimum = diffB;
        answer[5] = answer[6] = convert(b);
      }
    }

    return answer;
  }
};

// use round
// time : O(1)
// space : O(1)
class Solution {
 private:
  string findTarget(string colorSection) {
    int num = stoi(colorSection, NULL, 16);

    int target = round(num * 1.0 / 17);

    char hex = (target >= 10 ? 'a' + (target - 10) : target + '0');
    return {hex, hex};
  }

 public:
  string similarRGB(string color) {
    string answer = "#";

    answer += findTarget(color.substr(1, 2));  // R
    answer += findTarget(color.substr(3, 2));  // G
    answer += findTarget(color.substr(5, 2));  // B

    return answer;
  }
};