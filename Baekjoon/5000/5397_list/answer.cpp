#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void solution() {
  vector<char> pass;
  stack<char> temp;
  int index = 0;

  string line;
  cin >> line;

  for (char c : line) {
    switch (c) {
      case '<': {
        if (pass.size() == 0) {
          break;
        }
        temp.push(pass.back());
        pass.pop_back();
      } break;
      case '>': {
        if (temp.size() == 0) {
          break;
        }
        pass.push_back(temp.top());
        temp.pop();
      } break;
      case '-': {
        if (pass.size() == 0) {
          break;
        }
        pass.pop_back();
      } break;
      default:
        pass.push_back(c);
    }
  }

  while (!temp.empty()) {
    pass.push_back(temp.top());
    temp.pop();
  }

  for (char c : pass) {
    cout << c;
  }
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    solution();
  }

  return 0;
}