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

int solution(int size, vector<string> &arr) {
  unordered_set<string> us;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == j) continue;  // Skip if both indices are the same
      string s1 = arr[i];
      string s2 = arr[j];

      string cur = s1 + s2;

      us.insert(cur);
    }
  }

  return us.size();
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<string> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int answer = solution(N, arr);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}