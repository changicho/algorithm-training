#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> arr;

long long calculateCost(long long length) {
  long long ret = 0;

  for (int i = 0; i < arr.size(); i++) {
    ret += abs(i * length - arr[i]);
  }

  return ret;
}

void solution() {
  int N;
  long long answer = 1e18;
  cin >> N;

  arr.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  long long range_start = 1, range_end = 1e9;

  while (range_start + 3 <= range_end) {
    long long left = (2 * range_start + range_end) / 3;
    long long right = (range_start + 2 * range_end) / 3;

    long long costL = calculateCost(left);
    long long costR = calculateCost(right);

    if (costL < costR) {
      range_end = right;
    } else {
      range_start = left;
    }
  }

  for (long long cur = range_start; cur <= range_end; cur++) {
    answer = min(answer, calculateCost(cur));
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}