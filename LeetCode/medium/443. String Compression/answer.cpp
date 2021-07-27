#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use replace vector

class Solution {
 public:
  int compress(vector<char>& chars) {
    vector<char> line;

    char before = chars.front();
    int count = 0;
    for (char c : chars) {
      if (c != before) {
        line.emplace_back(before);

        if (count > 1) {
          for (char digit : to_string(count)) {
            line.emplace_back(digit);
          }
        }

        before = c;
        count = 1;
        continue;
      }
      count += 1;
    }
    line.emplace_back(before);
    if (count > 1) {
      for (char digit : to_string(count)) {
        line.emplace_back(digit);
      }
    }

    chars = line;

    return line.size();
  }
};

// use replace chars

class Solution {
 public:
  int compress(vector<char>& chars) {
    int size = chars.size();
    if (size == 1) return size;

    int index = 0, newIndex = 0;

    while (index < size) {
      chars[newIndex] = chars[index];

      int count = 0;
      while (index < size && chars[index] == chars[newIndex]) {
        count++;
        index++;
      }

      if (count > 1) {
        for (char digit : to_string(count)) {
          newIndex++;
          chars[newIndex] = digit;
        }
      }
      newIndex++;
    }

    return newIndex;
  }
};