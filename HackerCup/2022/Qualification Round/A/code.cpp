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

// time : 30min
bool solution(int n, int k, vector<int>& s) {
  if (n > k * 2) return false;

  unordered_map<int, int> counts;
  for (int& num : s) {
    counts[num]++;

    if (counts[num] > 2) return false;
  }

  return true;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N, K;
    cin >> N >> K;

    vector<int> S(N);
    for (int i = 0; i < N; i++) {
      cin >> S[i];
    }

    bool answer = solution(N, K, S);

    cout << "Case #" << testCase << ": ";
    cout << (answer ? "YES" : "NO") << "\n";
  }

  return 0;
}