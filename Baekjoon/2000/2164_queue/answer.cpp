#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void solution() {
  int N;
  int answer;

  queue<int> q;

  cin >> N;

  for (int i = 1; i <= N; i++) {
    q.push(i);
  }

  while (!q.empty()) {
    if (q.size() == 1) {
      answer = q.front();
      break;
    }

    q.pop();
    q.push(q.front());
    q.pop();
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