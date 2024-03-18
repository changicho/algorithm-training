#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &arr, vector<vector<int>> &queries) {
  int size = arr.size();
  unordered_map<int, int> nexts;
  unordered_map<int, int> prevs;

  for (int i = 0; i < arr.size(); i++) {
    nexts[arr[i]] = (i + 1) < size ? arr[i + 1] : -1;
    prevs[arr[i]] = (i - 1) >= 0 ? arr[i - 1] : -1;
  }

  for (vector<int> &q : queries) {
    if (q[0] == 1) {
      int x = q[1], y = q[2];

      int next = nexts[x];

      prevs[y] = x;
      nexts[y] = next;

      nexts[x] = y;
      prevs[next] = y;

    } else {
      int x = q[1];

      int prev = prevs[x];
      int next = nexts[x];

      prevs[next] = prev;
      nexts[prev] = next;

      prevs.erase(x);
      nexts.erase(x);
    }
  }

  int start = -1;
  for (auto &p : prevs) {
    if (p.second == -1) {
      start = p.first;
      break;
    }
  }

  vector<int> answer;
  int cur = start;
  while (cur != -1) {
    answer.push_back(cur);
    cur = nexts[cur];
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int Q;
  cin >> Q;

  vector<vector<int>> queries(Q);
  for (int i = 0; i < Q; i++) {
    int operation;
    cin >> operation;

    if (operation == 1) {
      int x, y;
      cin >> x >> y;

      queries[i] = {operation, x, y};
    } else {
      int x;
      cin >> x;

      queries[i] = {operation, x};
    }
  }

  vector<int> answer = solution(A, queries);

  for (int &a : answer) {
    cout << a << ' ';
  }

  return 0;
}