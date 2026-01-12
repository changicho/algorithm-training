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

long long solution(int size1, vector<int>& nums1, int size2,
                   vector<int>& nums2) {
  const long long MOD = 998244353;
  long long answer = 0;

  sort(nums2.begin(), nums2.end());

  vector<long long> prefixSum(size2 + 1, 0);
  for (int i = 0; i < size2; i++) {
    prefixSum[i + 1] = prefixSum[i] + nums2[i];
    prefixSum[i + 1] %= MOD;
  }

  for (int i = 0; i < size1; i++) {
    long long curSum = 0;

    long long leftCount =
        lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
    long long rightCount = size2 - leftCount;

    long long leftSum = prefixSum[leftCount];
    long long rightSum = (prefixSum[size2] - prefixSum[leftCount] + MOD) % MOD;

    curSum += ((nums1[i] * leftCount) % MOD - leftSum + MOD) % MOD;
    curSum %= MOD;

    curSum += (rightSum - (nums1[i] * rightCount) % MOD + MOD) % MOD;
    curSum %= MOD;

    answer += curSum;
    answer %= MOD;
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

  vector<int> A(N), B(M);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }

  auto answer = solution(N, A, M, B);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}