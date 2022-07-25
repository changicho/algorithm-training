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

// time : 30min
long long solution(int n, int m, vector<int>& a, vector<int>& b, int k) {
  long long answer = 0;

  vector<long long> prefix1(n + 1, 0);
  vector<long long> dp1(n + 1, 0);  // pick n number, maximum val
  for (int i = 0; i < n; i++) {
    prefix1[i + 1] = prefix1[i] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int left = 0; left <= i; left++) {
      int right = i - left;
      long long cur = prefix1[left] + (prefix1[n] - prefix1[n - (right)]);

      dp1[i] = max(dp1[i], cur);
    }
  }

  vector<long long> prefix2(m + 1, 0);
  vector<long long> dp2(m + 1, 0);  // pick m number, maximum val
  for (int i = 0; i < m; i++) {
    prefix2[i + 1] = prefix2[i] + b[i];
  }
  for (int i = 1; i <= m; i++) {
    for (int left = 0; left <= i; left++) {
      int right = i - left;
      long long cur = prefix2[left] + (prefix2[m] - prefix2[m - (right)]);

      dp2[i] = max(dp2[i], cur);
    }
  }

  for (int i = 0; i <= k; i++) {
    if (i > n) continue;
    if (k - i > m) continue;
    long long cur = dp1[i] + dp2[k - i];

    answer = max(answer, cur);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(6);
  cout << fixed;

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N, M, K;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++) {
      cin >> B[i];
    }
    cin >> K;

    long long answer = solution(N, M, A, B, K);
    cout << "Case #" << testCase << ": " << answer << "\n";
  }

  return 0;
}