#include <iostream>
#include <stack>
#include <string>

using namespace std;

void solution() {
  int answer = 0;
  int temp_result = 1;
  string line;
  stack<char> s;

  cin >> line;

  for (int i = 0; i < line.length(); i += 1) {
    if (line[i] == '(') {
      s.push('(');
      temp_result *= 2;
    } else if (line[i] == '[') {
      s.push('[');
      temp_result *= 3;
    } else if (line[i] == ')') {
      if (s.empty()) {
        cout << "0\n";
        exit(0);
      }
      if (s.top() != '(') {
        cout << "0\n";
        exit(0);
      }

      if (line[i - 1] == '(') {
        answer += temp_result;
      }
      s.pop();
      temp_result /= 2;
    } else if (line[i] == ']') {
      if (s.empty()) {
        cout << "0\n";
        exit(0);
      }
      if (s.top() != '[') {
        cout << "0\n";
        exit(0);
      }

      if (line[i - 1] == '[') {
        answer += temp_result;
      }
      s.pop();
      temp_result /= 3;
    }
  }

  if (!s.empty()) {
    cout << "0\n";
    return;
  }

  cout << answer << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}