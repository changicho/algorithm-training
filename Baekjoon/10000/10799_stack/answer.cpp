#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void solution() {
  string line;
  cin >> line;

  stack<char> s;
  int answer = 0;

  for (int i = 0; i < line.length(); i++) {
    char cur = line[i];

    if (cur == '(') {
      s.push(cur);
    } else {
      s.pop();
      if (line[i - 1] == '(') {
        answer += s.size();
      } else {
        answer += 1;
      }
    }
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}