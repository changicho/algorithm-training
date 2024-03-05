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

vector<vector<int>> solution(int n, vector<vector<int>> g) {
  vector<vector<int>> answer;

  for (int from = 0; from < n; from++) {
    vector<int> cur;
    for (int to = 0; to < n; to++) {
      if (g[from][to] == 1) {
        cur.push_back(to + 1);
      }
    }

    answer.push_back(cur);
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

  vector<vector<int>> G(N, vector<int>(N, 0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> G[i][j];
    }
  }

  vector<vector<int>> answer = solution(N, G);

  for (auto a : answer) {
    for (auto b : a) {
      cout << b << " ";
    }
    cout << endl;
  }

  return 0;
}