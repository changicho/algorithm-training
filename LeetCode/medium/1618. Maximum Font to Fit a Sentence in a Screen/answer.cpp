#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// This is the FontInfo's API interface.
// You should not implement it, or speculate about its implementation
class FontInfo {
 public:
  // Return the width of char ch when fontSize is used.
  int getWidth(int fontSize, char ch);

  // Return Height of any char when fontSize is used.
  int getHeight(int fontSize);
};

// use binary search

class Solution {
 private:
  bool isValid(string& text, int w, int h, int fontSize, FontInfo& fontInfo) {
    int curHeight = fontInfo.getHeight(fontSize);
    if (curHeight > h) return false;

    int curWidth = 0;
    for (char& c : text) {
      curWidth += fontInfo.getWidth(fontSize, c);
    }

    return curWidth <= w;
  }

 public:
  int maxFont(string text, int w, int h, vector<int>& fonts,
              FontInfo fontInfo) {
    int size = fonts.size();

    int answer = -1;
    int left = 0, right = size;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (isValid(text, w, h, fonts[mid], fontInfo)) {
        // pick right part
        answer = fonts[mid];
        left = mid + 1;
      } else {
        // pick left part
        right = mid;
      }
    }

    return answer;
  }
};