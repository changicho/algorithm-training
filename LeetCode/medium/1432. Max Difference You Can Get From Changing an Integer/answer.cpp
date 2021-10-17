#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy algorithm

class Solution {
 private:
  string getMaximum(string number) {
    string maximum = number;
    int length = number.length();
    char target = ' ';

    for (char c : number) {
      if (c != '9') {
        target = c;
        break;
      }
    }
    for (int i = 0; i < length; i++) {
      if (maximum[i] == target) {
        maximum[i] = '9';
      }
    }
    return maximum;
  }

  string getMinimum(string number) {
    string minimumA = number, minimumB = number;
    int length = number.length();

    // change first number to '1'
    char target = minimumA.front();
    for (int i = 0; i < length; i++) {
      if (minimumA[i] == target) {
        minimumA[i] = '1';
      }
    }

    // change second number to '0';
    if (length >= 2) {
      for (char c : minimumB) {
        if (c != minimumB.front() && c != '0') {
          target = c;
          break;
        }
      }

      for (int i = 0; i < length; i++) {
        if (minimumB[i] == target) {
          minimumB[i] = '0';
        }
      }
      if (minimumB.front() == '0') minimumB = number;
    }

    if (stoi(minimumA) < stoi(minimumB)) {
      return minimumA;
    }
    return minimumB;
  }

 public:
  int maxDiff(int num) {
    string numString = to_string(num);

    string minimum = getMinimum(numString);
    string maximum = getMaximum(numString);

    int diff = stoi(maximum) - stoi(minimum);
    return diff;
  }
};

// use brute force

class Solution {
 public:
  int maxDiff(int num) {
    string number = to_string(num);
    int length = number.length();

    string minimum = number;
    string maximum = number;

    for (char from = '0'; from <= '9'; from++) {
      for (char to = '0'; to <= '9'; to++) {
        string current = number;
        if (from == to) continue;

        for (int i = 0; i < length; i++) {
          if (current[i] == from) current[i] = to;
        }

        if (current == number) continue;
        if (current.front() == '0') continue;

        if (stoi(maximum) < stoi(current)) {
          maximum = current;
        }
        if (stoi(minimum) > stoi(current)) {
          minimum = current;
        }
      }
    }

    int answer = stoi(maximum) - stoi(minimum);
    return answer;
  }
};