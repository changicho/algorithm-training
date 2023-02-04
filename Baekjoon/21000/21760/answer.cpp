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

long long solution(int n, int m, int k, long long d) {
  // 하나의 팀은 같은 지역리그
  // (M-1) * A
  // 다른 지역리그
  // (N-1) * M * B

  // 이게 모든 팀에 포함이니 식은 (중복 제거해야함)
  // (N * M) * ((M-1) * A + (N-1) * M * B) / 2
  // = (N * M) * ((M-1) * (k * B) + (N-1) * M * B) / 2

  long long answer = -1;
  long long left = 1, right = 1000000000 / 4 + 1;

  while (left < right) {
    long long mid = left + (right - left) / 2;

    long long curCost =
        ((long long)(m - 1) * k * mid + (long long)(n - 1) * m * mid);
    curCost *= (long long)(n * m);
    curCost /= 2;

    if (curCost <= d) {
      // pick right
      answer = curCost;
      left = mid + 1;
    } else {
      // pick left
      right = mid;
    }
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

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N, M, K;
    long long D;
    cin >> N >> M >> K >> D;

    long long answer = solution(N, M, K, D);

    cout << answer << "\n";
  }

  return 0;
}
