#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  bool answer = 1;
  stack<char> bracket;
  string str;

  cin >> str >> str;

  for (char c : str) {
    if (c == '{' || c == '[' || c == '(' || c == '<') {
      bracket.push(c);
      continue;
    }

    if (abs(bracket.top() - c) > 2) {
      answer = 0;
      break;
    } else {
      bracket.pop();
    }
  }

  cout << "#" << test_case << " " << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 10;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}