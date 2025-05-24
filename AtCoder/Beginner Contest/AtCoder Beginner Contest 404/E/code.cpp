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

int solution(int size, vector<int> &dist, vector<int> &arr) {
  int answer = 0;

  for (int i = size - 1; i >= 1; i--) {
    if (arr[i] == 0) continue;

    int c = dist[i];
    int target = max(i - c, 0);
    for (int j = i - 1; j >= max(i - c, 0); j--) {
      int next = j - dist[j];

      if (arr[j] > 0) {
        target = j;
        break;
      }

      if (next < target - dist[target]) {
        target = j;
      }
    }

    answer++;
    arr[target] += arr[i];
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

  vector<int> C(N, 0), A(N, 0);
  for (int i = 1; i < N; i++) {
    cin >> C[i];
  }
  for (int i = 1; i < N; i++) {
    cin >> A[i];
  }

  int answer = solution(N, C, A);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}