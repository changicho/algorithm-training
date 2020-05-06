#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, K;
  queue<int> q;
  vector<int> answer;

  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    q.push(i);
  }

  while (!q.empty()) {
    for (int i = 0; i < K - 1; i++) {
      q.push(q.front());
      q.pop();
    }

    answer.push_back(q.front());
    q.pop();
  }

  cout << "<";
  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i];
    if (i != answer.size() - 1) {
      cout << ", ";
    }
  }
  cout << ">";

  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}