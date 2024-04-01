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

map<long long, long long> solution(long long height, long long width,
                                   int operSize, vector<vector<int>> &opers) {
  unordered_set<int> rows;
  unordered_set<int> cols;

  int size = opers.size();

  map<long long, long long> answer;
  answer[0] = (long long)height * width;

  reverse(opers.begin(), opers.end());

  for (vector<int> &oper : opers) {
    if (oper[0] == 1) {
      int row = oper[1] - 1;
      int color = oper[2];

      if (rows.find(row) != rows.end()) continue;

      int count = width - cols.size();
      if (count == 0) continue;

      answer[color] += count;
      answer[0] -= count;
      rows.insert(row);
    } else {
      int col = oper[1] - 1;
      int color = oper[2];

      if (cols.find(col) != cols.end()) continue;

      int count = height - rows.size();
      if (count == 0) continue;

      answer[color] += count;
      answer[0] -= count;
      cols.insert(col);
    }
  }

  if (answer[0] == 0) answer.erase(0);

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  long long H, W;
  int M;

  cin >> H >> W >> M;

  vector<vector<int>> operations(M, vector<int>(3, 0));
  for (int i = 0; i < M; i++) {
    cin >> operations[i][0] >> operations[i][1] >> operations[i][2];
  }

  map<long long, long long> answer = solution(H, W, M, operations);

  cout << answer.size() << "\n";
  for (auto it : answer) {
    cout << it.first << " " << it.second << "\n";
  }

  return 0;
}