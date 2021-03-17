#include <map>
#include <string>

using namespace std;

class Solution {
 public:
  map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

  int romanToInt(string s) {
    if (s.length() == 0) return 0;

    string left = "", right = "";
    char target;

    int index = 0;
    int length = s.length();

    for (int i = 0; i < length; i++) {
      if (m[s[i]] > m[s[index]]) {
        index = i;
      }
    }

    for (int i = 0; i < index; i++) {
      left += s[i];
    }
    target = s[index];
    for (int i = index + 1; i < length; i++) {
      right += s[i];
    }

    int minusNum = romanToInt(left);
    int targetNum = m[target];
    int plusNum = romanToInt(right);

    return -minusNum + targetNum + plusNum;
  }
};

// map을 안쓴 코드
class Solution {
 public:
  int romanToInt(string s) {
    if (s.length() == 0) return 0;

    string left = "", right = "";
    char target;

    int index = 0;
    int length = s.length();

    for (int i = 0; i < length; i++) {
      if (getNumber(s[i]) > getNumber(s[index])) {
        index = i;
      }
    }

    for (int i = 0; i < index; i++) {
      left += s[i];
    }
    target = s[index];
    for (int i = index + 1; i < length; i++) {
      right += s[i];
    }

    int minusNum = romanToInt(left);
    int targetNum = getNumber(target);
    int plusNum = romanToInt(right);

    return -minusNum + targetNum + plusNum;
  }

  int getNumber(char c) {
    switch (c) {
      case 'I':
        return 1;
      case 'V':
        return 5;
      case 'X':
        return 10;
      case 'L':
        return 50;
      case 'C':
        return 100;
      case 'D':
        return 500;
      case 'M':
        return 1000;
      default:
        return 0;
    }
  }
};