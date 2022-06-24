#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use two stack
// time add : O(N)
// time other : O(K)
// space : O(N)
class TextEditor {
 private:
  // cur index : left.top()
  stack<char> left, right;

  string getLast10() {
    string ret = "";
    stack<char> temp;
    for (int i = 0; i < 10 && !left.empty(); i++) {
      ret += left.top();
      temp.push(left.top());
      left.pop();
    }

    while (!temp.empty()) {
      left.push(temp.top());
      temp.pop();
    }

    reverse(ret.begin(), ret.end());
    return ret;
  }

 public:
  void addText(string text) {
    for (char &c : text) {
      left.push(c);
    }
  }

  int deleteText(int k) {
    int count = 0;
    while (count < k && !left.empty()) {
      left.pop();
      count++;
    }
    return count;
  }

  string cursorLeft(int k) {
    int leftCount = min((int)left.size(), k);
    for (int i = 0; i < leftCount; i++) {
      right.push(left.top());
      left.pop();
    }

    return getLast10();
  }

  string cursorRight(int k) {
    int rightCount = min((int)right.size(), k);
    for (int i = 0; i < rightCount; i++) {
      left.push(right.top());
      right.pop();
    }

    return getLast10();
  }
};

// use two string
// time add : O(N)
// time other : O(K)
// space : O(N)
class TextEditor {
 private:
  // cur index : left.back()
  string left, right;

  string getLast10() {
    string ret = "";
    int length = left.length();
    for (int i = max(0, length - 10); i < length; i++) {
      ret += left[i];
    }
    return ret;
  }

 public:
  void addText(string text) {
    for (char &c : text) {
      left.push_back(c);
    }
  }

  int deleteText(int k) {
    int count = 0;
    while (count < k && !left.empty()) {
      left.pop_back();
      count++;
    }
    return count;
  }

  string cursorLeft(int k) {
    int leftCount = min((int)left.size(), k);
    for (int i = 0; i < leftCount; i++) {
      right.push_back(left.back());
      left.pop_back();
    }

    return getLast10();
  }

  string cursorRight(int k) {
    int rightCount = min((int)right.size(), k);
    for (int i = 0; i < rightCount; i++) {
      left.push_back(right.back());
      right.pop_back();
    }

    return getLast10();
  }
};