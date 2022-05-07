#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass & trim
// time : O(N)
// space : O(N)
class Solution {
 private:
  string trim(string &origin) {
    string ret = "";
    int length = origin.length();
    for (int i = length - 1; i >= 0; i--) {
      if (origin[i] != ' ') {
        ret = origin.substr(0, i + 1);

        break;
      }
    }
    return ret;
  }

 public:
  string decodeCiphertext(string encodedText, int rows) {
    string text = "";

    int length = encodedText.length();
    int cols = length / rows;

    for (int x = 0; x < cols; x++) {
      for (int i = 0; i < rows; i++) {
        int nx = x + i;
        int ny = i;

        if (cols <= nx) break;

        text += encodedText[ny * cols + nx];
      }
    }

    return trim(text);
  }
};

// use one pass & trim
// time : O(N)
// space : O(N)
class Solution {
 public:
  string decodeCiphertext(string encodedText, int rows) {
    string text = "";

    int length = encodedText.length();
    int cols = length / rows;

    for (int x = 0; x < cols; x++) {
      for (int i = 0; i < rows && x + i < cols; i++) {
        text += encodedText[i * cols + x + i];
      }
    }

    while (!text.empty() && text.back() == ' ') {
      text.pop_back();
    }

    return text;
  }
};