#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  bool answer = false;
  bool map[100][100] = {
      0,
  };
  int N;
  queue<int> q;

  cin >> test_case >> N;

  for (int i = 0; i < N; i++) {
    int from, to;
    cin >> from >> to;
    map[from][to] = true;
    if (from == 0) {
      q.push(to);
    }
  }

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    if (current == 99) {
      answer = 1;
      break;
    }

    for (int i = 0; i < 100; i++) {
      if (map[current][i]) {
        q.push(i);
      }
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