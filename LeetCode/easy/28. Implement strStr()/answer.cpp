#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    return (int)haystack.find(needle);
  }
};

// 브루트 포스

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.length() == 0) {
      return 0;
    }

    if (haystack.length() < needle.length()) {
      return -1;
    }

    for (int index = 0; index <= haystack.size() - needle.size(); index++) {
      if (haystack[index] != needle[0]) {
        continue;
      }

      int needleIndex = 1;
      for (; needleIndex < needle.size(); needleIndex++) {
        if (haystack[index + needleIndex] != needle[needleIndex]) {
          break;
        }
      }

      if (needleIndex == needle.size()) {
        return index;
      }
    }

    return -1;
  }
};

// kmp 알고리즘

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
      return 0;
    }

    vector<int> patternIndexArray = getPatternIndexArray(needle);

    for (int index = 0, needleIndex = 0; index < haystack.size();) {
      if (haystack[index] == needle[needleIndex]) {
        index++, needleIndex++;
      }

      if (needleIndex == needle.size()) {
        return index - needleIndex;
      }

      if (index < haystack.size() && haystack[index] != needle[needleIndex]) {
        if (needleIndex != 0) {
          needleIndex = patternIndexArray[needleIndex - 1];
        } else {
          index++;
        }
      }
    }
    return -1;
  }

 private:
  vector<int> getPatternIndexArray(string needle) {
    vector<int> patternIndexArray(needle.size(), 0);

    for (int i = 1, len = 0; i < needle.size();) {
      if (needle[i] == needle[len]) {
        len++;
        patternIndexArray[i] = len;
        i++;
      } else if (len) {
        len = patternIndexArray[len - 1];
      } else {
        patternIndexArray[i++] = 0;
      }
    }
    return patternIndexArray;
  }
};