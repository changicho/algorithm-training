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

vector<vector<int>> solution(int n, vector<int> &dist) {
  vector<vector<int>> answer;

  for (int i = 0; i < n - 1; i++) {
    vector<int> cur;

    int d = 0;
    for (int j = i; j < n - 1; j++) {
      d += dist[j];
      cur.push_back(d);
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

  vector<int> D(N - 1);

  for (int i = 0; i < N - 1; i++) {
    cin >> D[i];
  }

  vector<vector<int>> answer = solution(N, D);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (vector<int> &line : answer) {
    for (int &s : line) {
      cout << s << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}