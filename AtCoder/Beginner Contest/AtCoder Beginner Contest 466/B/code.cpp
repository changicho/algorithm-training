#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

vector<int> solution(int size, vector<pair<int, int>>& balls, int m) {
  vector<int> answer(m, -1);

  // color, size
  for (pair<int, int>& ball : balls) {
    int c = ball.first, s = ball.second;

    answer[c - 1] = max(answer[c - 1], s);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> balls(N);
  for (int i = 0; i < N; i++) {
    cin >> balls[i].first >> balls[i].second;
  }

  auto answer = solution(N, balls, M);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << " ";
  }
  cout << endl;

  return 0;
}