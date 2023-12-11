#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Status {
  Axis axis;
  long long cost;

  bool operator<(const Status &other) const { return cost > other.cost; }
};

long long getMaxDist(vector<string> &board, Axis start, int same, int diff) {
  int size = board.size();
  vector<vector<long long>> dist(size, vector<long long>(size, -1));

  dist[start.y][start.x] = 0;

  priority_queue<Status> pq;
  pq.push({start, 0});

  while (!pq.empty()) {
    Status cur = pq.top();
    pq.pop();

    if (dist[cur.axis.y][cur.axis.x] < cur.cost) {
      continue;
    }

    for (Axis &dir : dirs) {
      Axis next = {cur.axis.y + dir.y, cur.axis.x + dir.x};

      if (next.y < 0 || next.y >= size || next.x < 0 || next.x >= size) {
        continue;
      }

      char curBlock = board[cur.axis.y][cur.axis.x];
      char nextBlock = board[next.y][next.x];

      long long nextCost = cur.cost + (curBlock == nextBlock ? same : diff);

      if (dist[next.y][next.x] == -1 || dist[next.y][next.x] > nextCost) {
        dist[next.y][next.x] = nextCost;
        pq.push({next, nextCost});
      }
    }
  }

  long long ret = 0;
  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      ret = max(ret, dist[y][x]);
    }
  }
  return ret;
}

long long solution(vector<string> &board, int same, int diff) {
  int size = board.size();
  long long answer = 0;

  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      long long cur = getMaxDist(board, {y, x}, same, diff);

      answer = max(answer, cur);
    }
  }
  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("input.txt", "r", stdin);

  int N, A, B;
  cin >> N >> A >> B;

  vector<string> board(N);
  for (int i = 0; i < N; i++) {
    cin >> board[i];
  }

  long long answer = solution(board, A, B);

  cout << answer << endl;

  return 0;
}