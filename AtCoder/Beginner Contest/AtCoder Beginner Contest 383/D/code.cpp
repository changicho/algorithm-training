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

bool solution(int size, long long target, vector<int> &nums) {
  long long allSum = accumulate(nums.begin(), nums.end(), 0LL);
  target %= allSum;

  long long prefixSum = 0;
  unordered_set<long long> prefixSums;
  for (int i = 0; i < size * 2; i++) {
    prefixSum += nums[i % size];

    prefixSums.insert(prefixSum);
  }

  for (long long sum : prefixSums) {
    if (prefixSums.find(sum + target) != prefixSums.end()) {
      return true;
    }
  }

  return false;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  long long S;
  cin >> N >> S;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  bool answer = solution(N, S, A);

  // cout << answer << endl;
  cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}