#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void solution() {
  deque<int> dq;
  deque<int> dqR, dqL;
  queue<int> orders;
  int N, M, num;
  int answer = 0;
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    dq.push_back(i);
  }

  for (int i = 0; i < M; i++) {
    cin >> num;

    orders.push(num);
  }

  while (!orders.empty()) {
    int target = orders.front();
    orders.pop();
    int temp, countL = 0, countR = 0;

    dqL = dq;
    dqR = dq;

    while (dqL.front() != target) {
      countL += 1;

      temp = dqL.front();
      dqL.pop_front();
      dqL.push_back(temp);
    }

    while (dqR.front() != target) {
      countR += 1;

      temp = dqR.back();
      dqR.pop_back();
      dqR.push_front(temp);
    }

    if (countL < countR) {
      dq = dqL;
      answer += countL;
    } else {
      dq = dqR;
      answer += countR;
    }

    dq.pop_front();
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