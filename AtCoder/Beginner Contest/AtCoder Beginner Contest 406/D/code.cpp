#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

vector<int> solution(int rows, int cols, vector<Axis> &trashes,
                     vector<pair<int, int>> &queries) {
  int tSize = trashes.size();
  int qSize = queries.size();

  vector<int> rowErasedTime(rows + 1, INT_MAX);
  vector<int> colErasedTime(cols + 1, INT_MAX);
  for (int i = 0; i < qSize; i++) {
    pair<int, int> &query = queries[i];
    int command = query.first;
    int target = query.second;

    // 1: row, 2: col
    if (command == 1) {
      rowErasedTime[target] = min(i, rowErasedTime[target]);
    } else if (command == 2) {
      colErasedTime[target] = min(i, colErasedTime[target]);
    }
  }

  vector<int> rowCounts(rows + 1, 0);
  vector<int> colCounts(cols + 1, 0);

  vector<vector<Axis>> eraseList(qSize);
  for (Axis &t : trashes) {
    int y = t.y;
    int x = t.x;

    rowCounts[y]++;
    colCounts[x]++;

    int erasedTime = min(rowErasedTime[y], colErasedTime[x]);

    if (erasedTime != INT_MAX) {
      eraseList[erasedTime].push_back(t);
    }
  }

  vector<int> answer;
  for (int i = 0; i < qSize; i++) {
    pair<int, int> &query = queries[i];
    int command = query.first;
    int target = query.second;

    // 1: row, 2: col
    if (command == 1) {
      answer.push_back(rowCounts[target]);
    } else if (command == 2) {
      answer.push_back(colCounts[target]);
    }

    for (Axis &t : eraseList[i]) {
      rowCounts[t.y]--;
      colCounts[t.x]--;
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int H, W, N;
  cin >> H >> W >> N;

  vector<Axis> trashes(N);
  for (int i = 0; i < N; i++) {
    cin >> trashes[i].y >> trashes[i].x;
  }

  int Q;
  cin >> Q;
  vector<pair<int, int>> queries(Q);
  for (int i = 0; i < Q; i++) {
    cin >> queries[i].first >> queries[i].second;
  }

  vector<int> answer = solution(H, W, trashes, queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << "\n";
  }
  // cout << endl;

  return 0;
}