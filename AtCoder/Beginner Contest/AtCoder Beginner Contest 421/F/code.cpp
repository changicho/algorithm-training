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

vector<long long> solution(int size, vector<vector<int>> &queries) {
  vector<long long> answer;

  vector<int> nexts(size + 1, -1);

  for (int i = 0; i < size; i++) {
    int cur = i + 1;
    vector<int> &q = queries[i];

    int type = q[0];
    if (type == 1) {
      int x = q[1];

      int next = nexts[x];
      nexts[x] = cur;
      nexts[cur] = next;
    } else {
      int x = q[1], y = q[2];

      // x -> y
      int curX = nexts[x];
      long long sumX = 0;
      // y -> x
      int curY = nexts[y];
      long long sumY = 0;

      while (true) {
        if (curX == y) {
          answer.push_back(sumX);
          nexts[x] = y;
          break;
        }
        if (curY == x) {
          answer.push_back(sumY);
          nexts[y] = x;
          break;
        }

        if (curX != -1) {
          sumX += curX;
          curX = nexts[curX];
        }
        if (curY != -1) {
          sumY += curY;
          curY = nexts[curY];
        }
      }
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

  int Q;
  cin >> Q;
  vector<vector<int>> queries(Q);
  for (int i = 0; i < Q; i++) {
    int type;
    cin >> type;

    if (type == 1) {
      int x;
      cin >> x;
      queries[i] = {type, x};
    } else if (type == 2) {
      int x, y;
      cin >> x >> y;
      queries[i] = {type, x, y};
    }
  }

  vector<long long> answer = solution(Q, queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << "\n";
  }
  // cout << endl;

  return 0;
}