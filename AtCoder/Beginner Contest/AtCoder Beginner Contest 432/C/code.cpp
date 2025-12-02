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

long long solution(int size, vector<long long>& nums, int x, int y) {
  long long minimum = *min_element(nums.begin(), nums.end());

  long long sum = 0;

  // (nums[i] - b[i]) * x + b[i] * y = (nums[0] - b[0]) * x + b[0] * y
  // b[i] = b[0] - (nums[i] - nums[0]) * x / (y - x)

  // b[i] = nums[i] - (nums[i] - nums[0]) * y / (y - x)
  for (int i = 0; i < size; i++) {
    long long vs = (nums[i] - minimum) * y;
    long long vt = (y - x);

    if (vs % vt != 0) {
      return -1;
    }
    long long minor = vs / vt;

    if (minor > nums[i]) {
      return -1;
    }
    long long b = nums[i] - minor;
    sum += b;
  }
  return sum;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, X, Y;
  cin >> N >> X >> Y;
  vector<long long> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  auto answer = solution(N, A, X, Y);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}