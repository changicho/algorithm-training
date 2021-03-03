#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Line {
  int from, to;
  // sort
  bool operator<(const Line &B) const {
    if (from != B.to) {
      return to < B.to;
    }
    return from < B.from;
  }
  // priority queue
  bool operator()(Line &A, Line &B) {
    return A.from > B.from;
  }
};

void solution() {
  int N, D;

  cin >> N;

  vector<Line> lines(N);
  for (int i = 0; i < N; i++) {
    cin >> lines[i].from >> lines[i].to;
    if (lines[i].from > lines[i].to) {
      swap(lines[i].from, lines[i].to);
    }
  }

  cin >> D;

  sort(lines.begin(), lines.end());
  priority_queue<Line, vector<Line>, Line> pq;

  int answer = 0;
  for (Line line : lines) {
    pq.push(line);
    while (!pq.empty() && pq.top().from < line.to - D) {
      pq.pop();
    }
    answer = max(answer, (int)pq.size());
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