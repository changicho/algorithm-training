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

long long query(int type, int left, int right) {
  long long x;
  cout << type << ' ' << left << ' ' << right << flush << endl;
  cin >> x;
  return x;
}

vector<int> solution(int n) {
  long long oriSum = 1LL * n * (n + 1) / 2;

  long long sum = query(2, 1, n);

  int length = sum - oriSum;

  int left = 1, right = n;

  // 0 ~ last : oriSum == sum
  // (last + 1) ~ (last + 1 + length) : oriSum < sum
  int last = 0;
  while (left < right) {
    int mid = left + (right - left) / 2;

    long long oriSum = query(1, 1, mid);
    long long sum = query(2, 1, mid);

    if (oriSum >= sum) {
      last = mid;
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return {last + 1, last + length};
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    auto answer = solution(N);

    cout << "! " << answer[0] << " " << answer[1] << flush << endl;

    // cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}