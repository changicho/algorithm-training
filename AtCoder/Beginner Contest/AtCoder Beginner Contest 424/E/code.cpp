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

struct Number {
  double value;
  long long count;

  bool operator<(const Number &other) const { return value < other.value; }
};

double solution(int size, long long k, long long x, vector<int> &nums) {
  priority_queue<Number> pq;
  for (int &num : nums) {
    pq.push({(double)num, 1});
  }

  while (k > 0) {
    Number top = pq.top();
    pq.pop();

    if (k >= top.count) {
      pq.push({top.value / 2, top.count * 2});
      k -= top.count;
    } else {
      pq.push({top.value / 2, k});
      pq.push({top.value, top.count - k});
      k = 0;

      break;
    }
  }

  double answer = 0;
  while (x > 0) {
    Number top = pq.top();
    pq.pop();

    if (x > top.count) {
      x -= top.count;
    } else {
      answer = top.value;
      break;
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

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; tc++) {
    int N;
    long long K, X;
    cin >> N >> K >> X;

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }

    auto answer = solution(N, K, X, A);

    cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}