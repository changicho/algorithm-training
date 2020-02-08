#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는
정수가 없는 경우에는 -1을 출력한다. size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는
경우에는 -1을 출력한다. back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에
들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

void solution() {
  int N;
  string line;
  int num;

  cin >> N;

  queue<int> q;

  for (int i = 0; i < N; i++) {
    cin >> line;

    if (line == "push") {
      cin >> num;
      q.push(num);
    } else if (line == "pop") {
      if (q.empty()) {
        cout << "-1\n";
        continue;
      }
      cout << q.front() << "\n";
      q.pop();
    } else if (line == "size") {
      cout << q.size() << "\n";
    } else if (line == "empty") {
      if (q.empty()) {
        cout << "1\n";
        continue;
      }
      cout << "0\n";
    } else if (line == "front") {
      if (q.empty()) {
        cout << "-1\n";
        continue;
      }
      cout << q.front() << "\n";
    } else if (line == "back") {
      if (q.empty()) {
        cout << "-1\n";
        continue;
      }
      cout << q.back() << "\n";
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