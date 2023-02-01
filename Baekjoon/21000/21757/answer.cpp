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

long long combiDp[100000 + 1][3 + 1];

long long combination(int n, int r) {
  if (n < r) return 0;
  if (combiDp[n][r] != 0) return combiDp[n][r];
  if (n == r || r == 0)
    return combiDp[n][r] = 1;
  else
    return combiDp[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
}

long long getZeroCaseAnswer(int n, vector<int> &array) {
  int count = 0;
  for (int i = 0, leftSum = 0; i < n; i++) {
    leftSum += array[i];
    if (leftSum == 0) count++;
  }

  return combination(count - 1, 4 - 1);
}

long long solution(int n, vector<int> &array) {
  int sum = 0;
  for (int &num : array) {
    sum += num;
  }

  if (sum % 4 != 0) return 0;
  if (sum == 0) {
    return getZeroCaseAnswer(n, array);
  }

  vector<int> quartersLeft(n), quartersRight(n);
  for (int i = 0, leftSum = 0; i < n; i++) {
    leftSum += array[i];

    quartersLeft[i] = i > 0 ? quartersLeft[i - 1] : 0;

    if (leftSum == (sum / 4)) {
      quartersLeft[i]++;
    }
  }

  for (int i = n - 1, rightSum = 0; i >= 0; i--) {
    rightSum += array[i];

    quartersRight[i] = i < n - 1 ? quartersRight[i + 1] : 0;

    if (rightSum == (sum / 4)) {
      quartersRight[i]++;
    }
  }

  long long answer = 0;
  for (int i = 0, leftSum = 0; i < n - 1; i++) {
    leftSum += array[i];

    if (leftSum == (sum / 2)) {
      answer += (long long)quartersLeft[i] * (long long)quartersRight[i + 1];
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
