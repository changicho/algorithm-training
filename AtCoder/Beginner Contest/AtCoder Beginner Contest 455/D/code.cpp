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

vector<long long> solution(int n, int qSize, vector<int>& c, vector<int>& p) {
  vector<int> parents(n + 1);

  // -i is the pile number
  for (int i = 1; i <= n; i++) {
    parents[i] = -i;
  }

  function<int(int)> find = [&](int i) {
    if (i < 0) {
      return i;
    }

    return parents[i] = find(parents[i]);
  };

  for (int i = 0; i < qSize; i++) {
    int card = c[i], to = p[i];

    parents[card] = to;
  }

  vector<long long> answer(n);
  for (int i = 1; i <= n; i++) {
    int target = find(i);

    answer[abs(target) - 1]++;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, Q;
  cin >> N >> Q;

  vector<int> C(Q), P(Q);
  for (int i = 0; i < Q; i++) {
    cin >> C[i] >> P[i];
  }

  auto answer = solution(N, Q, C, P);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << " ";
  }
  cout << endl;

  return 0;
}