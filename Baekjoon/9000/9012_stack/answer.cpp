#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void solution() {
  string line;
  stack<char> s;

  cin >> line;

  for (char c : line) {
    if (c == '(') {
      s.push(c);
    } else {
      if (s.empty()) {
        cout << "NO";

        return;
      }
      if (s.top() == '(') {
        s.pop();
      } else {
        cout << "NO";

        return;
      }
    }
  }

  if (s.empty()) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    solution();
    cout << "\n";
  }

  return 0;
}