#include <algorithm>
#include <cmath>
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

// vector<long long> extended_gcd(long long a, long long b) {
//   if (a == 0) {
//     return {b, 0, 1};
//   }

//   // gcd, x, y
//   vector<long long> ret = extended_gcd(b % a, a);
//   long long gcd = ret[0], x = ret[1], y = ret[2];

//   return {gcd, (y - (b / a) * x), x};
// }

vector<long long> extended_gcd(long long a, long long b) {
  long long x = 1, y = 0;

  if (0 == b) return {a, x, y};

  long long new_x = 0, new_g = 1, new_r = b;
  long long g = a;
  while (new_r) {
    long long quotient = g / new_r;
    long long tmp = g;

    g = new_r;
    new_r = tmp - quotient * new_r;

    tmp = x;
    x = new_x;
    new_x = tmp - quotient * new_x;

    tmp = y;
    y = new_g;
    new_g = tmp - quotient * new_g;
  }
  return {g, x, y};
}

long long getDistance(long long dist, long long limit, long long x1,
                      long long x2) {
  vector<long long> ret = extended_gcd(dist, limit);
  long long diff = x1 - x2;
  long long g = ret[0], x = ret[1], y = ret[2];

  if (diff % g != 0) return -1;

  // dist * x + limit * y = diff
  x *= (diff / g);
  y *= (diff / g);

  long long move = x % (limit / g);

  return min(abs(move), limit / g - abs(move));
}

long long solution(long long size, vector<long long> &nums, long long limit,
                   long long dist) {
  long long answer = 0;
  int left = 0, right = size - 1;

  while (left < right) {
    long long leftVal = nums[left], rightVal = nums[right];

    // minimum movement to make nums[left] == nums[right]
    long long minimumCount = getDistance(dist, limit, leftVal, rightVal);

    if (minimumCount == -1) return -1;
    answer += minimumCount;

    left++, right--;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    long long W, N, D;
    cin >> W >> N >> D;

    vector<long long> X(W);
    for (int i = 0; i < W; i++) {
      cin >> X[i];
      X[i]--;
    }

    auto answer = solution(W, X, N, D);

    cout << "Case #" << testCase << ": ";

    if (answer == -1) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << answer << endl;
    }
  }

  return 0;
}