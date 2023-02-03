#include <algorithm>
#include <climits>
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

const int MAX = 1e9 + 1;

long long solution(int n, vector<int> &nums) {
  long long answer = 0;

  vector<long long> prefixLeft(n, 0);
  vector<long long> prefixRight(n, 0);

  for (int i = 0, leftSum = 0; i < n; i++) {
    prefixLeft[i] = i > 0 ? prefixLeft[i - 1] : 0;
    prefixLeft[i] += nums[i];
  }

  for (int i = n - 1, rightSum = 0; i >= 0; i--) {
    prefixRight[i] = i < n - 1 ? prefixRight[i + 1] : 0;
    prefixRight[i] += nums[i];
  }

  // bee ~ bee ~ honey
  for (int i = 1; i < n - 1; i++) {
    long long cur = prefixLeft[n - 1] - nums[0];
    cur -= nums[i];
    cur += prefixRight[i] - nums[i];

    answer = max(answer, cur);
  }

  // honey ~ bee ~ bee
  for (int i = n - 2; i >= 1; i--) {
    long long cur = prefixLeft[n - 1] - nums[n - 1];
    cur -= nums[i];
    cur += prefixLeft[i] - nums[i];

    answer = max(answer, cur);
  }

  // bee ~ honey ~ bee
  for (int i = 1; i < n - 1; i++) {
    long long cur = prefixLeft[i] + prefixRight[i] - nums[0] - nums[n - 1];

    answer = max(answer, cur);
  }

  return answer;
}

void init() {}

void clear() {}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  init();

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<int> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  long long answer = solution(N, A);

  cout << answer << "\n";

  return 0;
}
