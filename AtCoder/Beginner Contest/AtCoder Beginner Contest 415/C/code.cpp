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

struct Status {
  int mixed = 0;
  int canUse = 0;
};

bool solution(int n, string &s) {
  bool answer = false;

  unordered_set<int> dangerous;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      dangerous.insert(i + 1);
    }
  }

  vector<int> chemicals;
  for (int i = 1; i <= n; i++) {
    chemicals.push_back(i);
  }

  queue<Status> q;
  q.push({0, (1 << n) - 1});

  unordered_set<long long> visited;
  visited.insert(0);

  while (!q.empty() && !answer) {
    Status cur = q.front();
    q.pop();

    for (int &chem : chemicals) {
      if (cur.canUse & (1 << (chem - 1)) == 0) continue;
      if (cur.mixed & (1 << (chem - 1))) continue;

      Status next = cur;
      next.canUse -= (1 << (chem - 1));
      next.mixed += (1 << (chem - 1));

      if (visited.count(next.mixed) > 0) continue;
      visited.insert(next.mixed);

      if (dangerous.count(next.mixed)) continue;
      if (next.canUse == 0) {
        answer = true;
        break;
      }
      q.push(next);
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

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int N;
    string S;
    cin >> N >> S;

    bool answer = solution(N, S);

    cout << (answer ? "Yes" : "No") << endl;
  }

  // cout << answer << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}