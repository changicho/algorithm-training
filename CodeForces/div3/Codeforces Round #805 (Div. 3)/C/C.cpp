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

// time : 15min
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N, K;
    cin >> N >> K;
    vector<int> U(N);
    vector<pair<int, int>> queries(K);

    for (int i = 0; i < N; i++) {
      cin >> U[i];
    }

    map<int, vector<int>> indexes;
    for (int i = 0; i < N; i++) {
      int val = U[i];
      if (indexes[val].size() >= 2) indexes[val].pop_back();
      indexes[val].push_back(i);
    }

    for (int i = 0; i < K; i++) {
      cin >> queries[i].first >> queries[i].second;
      int a = queries[i].first, b = queries[i].second;

      if (indexes.count(a) == 0 || indexes.count(b) == 0) {
        cout << "NO\n";
        continue;
      }

      int findAnswer = false;
      findAnswer = indexes[b].back() > indexes[a].front();

      if (findAnswer) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }

  return 0;
}