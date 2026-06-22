#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

bool solution(int size, char x, vector<string>& s) {
  bool answer = false;

  for (int i = 0; i < size; i++) {
    int target = x - 'A';

    if (s[i][target] == 'o') return true;
  }

  return false;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  char X;
  cin >> N >> X;

  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  auto answer = solution(N, X, S);

  // cout << answer << endl;
  cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}