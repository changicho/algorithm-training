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

vector<vector<int>> solution(int n, vector<vector<int>>& arr) {
  vector<vector<int>> answer(n);

  for (int i = 0; i < n; i++) {
    for (int& cur : arr[i]) {
      answer[cur - 1].push_back(i + 1);
    }
  }

  for (int i = 0; i < n; i++) {
    answer[i].insert(answer[i].begin(), answer[i].size());
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

  vector<vector<int>> A(N);
  for (int i = 0; i < N; i++) {
    int K;
    cin >> K;

    A[i].resize(K);
    for (int j = 0; j < K; j++) {
      cin >> A[i][j];
    }
  }

  auto answer = solution(N, A);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    for (int& c : line) {
      cout << c << " ";
    }
    cout << "\n";
  }
  // cout << endl;

  return 0;
}