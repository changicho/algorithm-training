#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use hash map

class Logger {
 private:
  unordered_map<string, int> um;  // last printed

 public:
  Logger() {}

  bool shouldPrintMessage(int timestamp, string message) {
    // not found or over 10 seconds
    if (um[message] == 0 || timestamp - (um[message] - 1) >= 10) {
      um[message] = timestamp + 1;
      return true;
    }

    return false;
  }
};

// use end iterator

class Logger {
 private:
  unordered_map<string, int> um;  // last printed

 public:
  Logger() {}

  bool shouldPrintMessage(int timestamp, string message) {
    // not found or over 10 seconds
    if (um.find(message) == um.end() || timestamp - um[message] >= 10) {
      um[message] = timestamp;
      return true;
    }

    return false;
  }
};