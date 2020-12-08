#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int M, number;
  set<int> s;
  string command;
  cin >> M;

  // add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
  // remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
  // check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
  // toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
  // all: S를 {1, 2, ..., 20} 으로 바꾼다.
  // empty: S를 공집합으로 바꾼다.
  while (M--) {
    cin >> command;
    if (command == "add") {
      cin >> number;
      s.insert(number);
    } else if (command == "remove") {
      cin >> number;
      s.erase(number);
    } else if (command == "check") {
      cin >> number;

      if (s.find(number) != s.end()) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }

    } else if (command == "toggle") {
      cin >> number;

      if (s.find(number) != s.end()) {
        s.erase(number);
      } else {
        s.insert(number);
      }
    } else if (command == "all") {
      for (int i = 1; i <= 20; i++) {
        s.insert(i);
      }
    } else if (command == "empty") {
      s.clear();
    }
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}