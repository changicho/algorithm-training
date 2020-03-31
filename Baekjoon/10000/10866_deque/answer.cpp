#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, number;
  string command;
  deque<int> dq;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> command;

    if (command == "push_front") {
      cin >> number;

      dq.push_front(number);
    } else if (command == "push_back") {
      cin >> number;

      dq.push_back(number);
    } else if (command == "pop_front") {
      if (dq.empty()) {
        cout << "-1\n";
        continue;
      }

      cout << dq.front() << "\n";
      dq.pop_front();
    } else if (command == "pop_back") {
      if (dq.empty()) {
        cout << "-1\n";
        continue;
      }

      cout << dq.back() << "\n";
      dq.pop_back();
    } else if (command == "size") {
      cout << dq.size() << "\n";
    } else if (command == "front") {
      if (dq.empty()) {
        cout << "-1\n";
        continue;
      }

      cout << dq.front() << "\n";
    } else if (command == "back") {
      if (dq.empty()) {
        cout << "-1\n";
        continue;
      }

      cout << dq.back() << "\n";
    } else if (command == "empty") {
      if (dq.empty()) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    }
  }
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}