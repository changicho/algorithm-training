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

vector<int> solution(int n, int m, vector<vector<int>>& x) {
  vector<int> answer;

  unordered_set<int> us;
  for (int i = 1; i <= m; i++) {
    us.insert(i);
  }

  for (vector<int>& fav : x) {
    int target = 0;
    for (int& f : fav) {
      if (us.count(f)) {
        target = f;
        us.erase(f);
        break;
      }
    }

    answer.push_back(target);
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
  vector<vector<int>> X(N);
  for (int i = 0; i < N; i++) {
    int L;
    cin >> L;
    X[i].resize(L);

    for (int j = 0; j < L; j++) {
      cin >> X[i][j];
    }
  }

  auto answer = solution(N, M, X);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << "\n";
  }
  // cout << endl;

  return 0;
}