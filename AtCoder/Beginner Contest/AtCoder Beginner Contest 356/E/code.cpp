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

long long solution(int n, vector<int> &arr) {
  long long sum = accumulate(arr.begin(), arr.end(), 0LL);
  long long maximum = *max_element(arr.begin(), arr.end());

  long long answer = 0;

  int counts[1000001] = {
      0,
  };
  int prefixSums[1000002] = {
      0,
  };
  for (int i = 0; i < n; i++) {
    int num = arr[i];
    counts[num]++;
  }

  for (int i = 1; i <= 1e6; i++) {
    prefixSums[i] = prefixSums[i - 1] + counts[i];
  }

  for (long long num = 1; num <= 1e6; num++) {
    if (counts[num] == 0) continue;

    // num+1 ~ num*2-1
    long long left = num, right = min(num * 2 - 1, (long long)1e6);

    long long count = prefixSums[right] - prefixSums[left];
    answer += count * counts[num];
    answer += (long long)counts[num] * (counts[num] - 1) / 2;

    for (long long multiple = num * 2; multiple <= 1e6; multiple += num) {
      // multiple ~ multiple+num-1
      long long left = multiple,
                right = min(multiple + num - 1, (long long)1e6);
      long long count = prefixSums[right] - prefixSums[left - 1];
      long long curScore = multiple / num;

      answer += count * curScore * counts[num];
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
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  long long answer = solution(N, A);

  cout << answer << endl;

  return 0;
}