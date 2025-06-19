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

vector<int> solution(int n, int size, vector<vector<int>> &queries) {
  vector<int> answer;
  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }
  int diff = 0;
  for (vector<int> &q : queries) {
    int type = q[0];
    if (type == 1) {
      int p = q[1] - 1, x = q[2];

      int index = (p + diff + n) % n;

      arr[index] = x;

    } else if (type == 2) {
      int p = q[1] - 1;

      int index = (p + diff) % n;

      answer.push_back(arr[index]);
    } else {
      int k = q[1];
      diff += k;
      diff %= n;
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

  int N, Q;
  cin >> N >> Q;

  vector<vector<int>> queries(Q);

  for (int i = 0; i < Q; i++) {
    int type, a, b;
    cin >> type;
    if (type == 1) {
      cin >> a >> b;
      queries[i] = {type, a, b};
    } else {
      cin >> a;
      queries[i] = {type, a};
    }
  }

  vector<int> answer = solution(N, Q, queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}