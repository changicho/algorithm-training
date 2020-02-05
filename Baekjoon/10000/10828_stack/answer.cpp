#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는
정수가 없는 경우에는 -1을 출력한다. size: 스택에 들어있는 정수의 개수를
출력한다. empty: 스택이 비어있으면 1, 아니면 0을 출력한다. top: 스택의 가장 위에
있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

void solution() {
  int N;
  string line;
  int num;

  cin >> N;

  stack<int> s;

  for (int i = 0; i < N; i++) {
    cin >> line;

    if (line == "push") {
      cin >> num;
      s.push(num);
    } else if (line == "pop") {
      if (s.empty()) {
        cout << "-1\n";
        continue;
      }
      cout << s.top() << "\n";
      s.pop();
    } else if (line == "size") {
      cout << s.size() << "\n";
    } else if (line == "empty") {
      if (s.empty()) {
        cout << "1\n";
        continue;
      }
      cout << "0\n";
    } else if (line == "top") {
      if (s.empty()) {
        cout << "-1\n";
        continue;
      }
      cout << s.top() << "\n";
    }
  }

  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}