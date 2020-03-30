#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct paper {
  int cost;
  bool target;
};

void solution() {
  int N, M;
  queue<paper> q;
  vector<int> costs;
  queue<int> costs_q;
  int answer = 0;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    paper p;

    cin >> p.cost;
    i == M ? p.target = true : p.target = false;

    costs.push_back(p.cost);
    q.push(p);
  }

  sort(costs.begin(), costs.end(), greater<int>());
  for (int c : costs) {
    costs_q.push(c);
  }

  while (!q.empty()) {
    paper cur = q.front();
    q.pop();

    if (cur.cost == costs_q.front()) {
      costs_q.pop();
      answer += 1;
      if (cur.target) {
        break;
      }
    } else {
      q.push(cur);
    }
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test_case;
  cin >> test_case;

  for (int t = 0; t < test_case; t++) {
    solution();
  }

  return 0;
}