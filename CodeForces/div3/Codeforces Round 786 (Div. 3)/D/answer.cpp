#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>

// 22:04 ~ 22:31
using namespace std;

// time : O(N)
// space : O(N)
bool solution(int n, vector<int> &arr) {
  if (n == 1) return true;

  if (n % 2 == 0) {
    for (int i = 0; i < n; i += 2) {
      if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
    }
  } else {
    for (int i = 1; i < n; i += 2) {
      if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
    }
  }

  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) return false;
  }

  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    bool res = solution(n, arr);

    if (res == true) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}