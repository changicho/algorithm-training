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

auto solution(int size, vector<int> &nums, int qSize,
              vector<vector<int>> &queries) {
  vector<long long> answer;

  vector<long long> sums(size + 1, 0);
  for (int i = 0; i < size; i++) {
    sums[i + 1] = sums[i] + nums[i];
  }

  int index = 0;

  for (vector<int> &query : queries) {
    int type = query[0];

    if (type == 1) {
      int x = query[1];
      index = (index + x) % size;
    } else if (type == 2) {
      int l = (query[1] + index - 1 + size) % size;
      int r = (query[2] + index + 1 - 1 + size) % size;

      long long sum = 0;

      if (l < r) {
        sum = sums[r] - sums[l];
      } else {
        sum = (sums[size] - sums[l]) + (sums[r] - sums[0]);
      }

      answer.push_back(sum);
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

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<vector<int>> queries(Q);

  for (int i = 0; i < Q; i++) {
    int type;
    cin >> type;

    if (type == 1) {
      int x;
      cin >> x;
      queries[i] = {type, x};
    } else if (type == 2) {
      int l, r;
      cin >> l >> r;
      queries[i] = {type, l, r};
    }
  }

  auto answer = solution(N, A, Q, queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}