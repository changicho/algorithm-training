#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;

    string str = to_string(x);
    int length = str.length();
    for (int index = 0; index < length / 2; index++) {
      if (str[index] != str[length - 1 - index]) return false;
    }

    return true;
  }
};

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x == 0) return true;
    if (x % 10 == 0) return false;

    int reversed = 0;
    while (x > reversed) {
      reversed *= 10;
      reversed += x % 10;
      x /= 10;
    }

    return x == reversed || x == reversed / 10;
  }
};