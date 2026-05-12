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

bool check(vector<ll>& nums, ll k, ll target) {
  int size = nums.size();
  ll count = 0;

  for (int i = 0; i < size; i++) {
    ll num = nums[i];

    if (num > target) continue;
    ll diff = target - num;

    ll curCount = (diff + i) / (i + 1);
    count += curCount;
    if (count > k) return false;
  }
  return true;
}

ll solution(int size, ll k, vector<ll>& nums) {
  if (size == 1) {
    return nums[0] + k;
  }

  ll answer = 0;
  ll left = 0, right = LLONG_MAX;

  while (left < right) {
    ll mid = (left) + (right - left) / 2;

    if (check(nums, k, mid)) {
      // pick right
      answer = mid;
      left = mid + 1;
    } else {
      // pick left
      right = mid;
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

  int N;
  long long K;
  cin >> N >> K;

  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  auto answer = solution(N, K, A);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}