#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void printAnswer(bool isAnswer) {
  if (isAnswer) {
    cout << "yes\n";
  } else {
    cout << "no\n";
  }
}

void solution() {
  string line;

  while (getline(cin, line)) {
    if (line == ".") {
      break;
    }

    stack<char> s;
    bool isAnswer = true;

    // (),[]
    for (char c : line) {
      if (c == '(' || c == '[') {
        s.push(c);
      } else if (c == ')' || c == ']') {
        if (s.empty()) {
          isAnswer = false;
          break;
        }
        if (s.top() == '(' && c == ')') {
          s.pop();
        } else if (s.top() == '[' && c == ']') {
          s.pop();
        } else {
          isAnswer = false;
          break;
        }
      }
    }
    if (!s.empty()) {
      isAnswer = false;
    }

    printAnswer(isAnswer);
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}