#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void solution() {
  int N, K;
  queue<int> q;
  vector<int> answers;

  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    q.push(i);
  }

  int count;
  while (!q.empty()) {
    count = K % q.size();
    if (count == 0) {
      count = q.size();
    }

    for (int i = 0; i < count - 1; i++) {
      q.push(q.front());
      q.pop();
    }
    answers.push_back(q.front());
    q.pop();
  }

  cout << "<";
  for (int i = 0; i < answers.size(); i++) {
    cout << answers[i];
    if (i == answers.size() - 1) {
      cout << ">\n";
      break;
    }
    cout << ", ";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}