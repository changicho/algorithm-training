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

auto solution(int size, vector<int> &converted) {
  vector<int> arr(size, 0);
  arr[0] = converted[0];
  for (int i = 1; i < size; i++) {
    // converted[i-1] = max(arr[i-1], arr[i]);

    if (converted[i - 1] == arr[i - 1]) {
      arr[i] = 0;
    } else {
      arr[i] = converted[i - 1];
    }
    if (i + 1 < size && converted[i - 1] > converted[i] &&
        arr[i] > arr[i - 1]) {
      swap(arr[i], arr[i - 1]);
    }
  }

  return arr;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<int> B(N - 1);
    for (int i = 0; i < N - 1; i++) {
      cin >> B[i];
    }

    auto answer = solution(N, B);
    for (int num : answer) {
      cout << num << " ";
    }
    cout << "\n";
  }

  return 0;
}