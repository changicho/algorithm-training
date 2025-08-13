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

auto solution(int size, vector<int> &arr, int qSize,
              vector<long long> &queries) {
  sort(arr.begin(), arr.end());

  vector<long long> answer;

  vector<long long> prefixSum(size + 1, 0);
  for (int i = 1; i < size + 1; i++) {
    prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
  }

  for (long long &query : queries) {
    // impossible case
    if (query > arr.back()) {
      answer.push_back(-1);
      continue;
    }

    int leftSize = lower_bound(arr.begin(), arr.end(), query) - arr.begin();
    int rightSize = size - leftSize;

    long long need =
        prefixSum[leftSize] + rightSize * ((long long)query - 1) + 1LL;
    if (need > prefixSum.back()) {
      answer.push_back(-1);
      continue;
    }
    answer.push_back(need);
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

  vector<long long> B(Q);
  for (int i = 0; i < Q; i++) {
    cin >> B[i];
  }

  auto answer = solution(N, A, Q, B);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << "\n";
  }
  // cout << endl;

  return 0;
}