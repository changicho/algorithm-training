#include <algorithm>
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

void solution(int n) {
  vector<bool> visited(n + 1, false);

  vector<int> twoArr, threeArr;
  // check 2 case
  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;
    twoArr.push_back(i);
    visited[i] = true;

    int target = i * 2;
    while (target <= n && !visited[target]) {
      twoArr.push_back(target);
      visited[target] = true;

      target *= 2;
    }
  }

  for (int i = 0; i <= n; i++) {
    visited[i] = false;
  }

  // check 3 case
  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;
    threeArr.push_back(i);
    visited[i] = true;
    int target = i * 3;
    while (target <= n && !visited[target]) {
      threeArr.push_back(target);
      visited[target] = true;

      target *= 3;
    }
  }

  int twoCost = 0, threeCost = 0;
  for (int i = 0; i < n - 1; i++) {
    if (twoArr[i] * 2 == twoArr[i + 1]) twoCost++;
    if (threeArr[i] * 3 == threeArr[i + 1]) threeCost++;
  }

  if (twoCost > threeCost) {
    cout << 2 << "\n";
    for (int &num : twoArr) {
      cout << num << " ";
    }
    cout << "\n";
  } else {
    cout << 3 << "\n";
    for (int &num : threeArr) {
      cout << num << " ";
    }
    cout << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    solution(N);
  }

  return 0;
}