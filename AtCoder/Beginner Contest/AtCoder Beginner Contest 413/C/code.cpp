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

vector<long long> solution(int size, vector<vector<int>> &queries) {
  vector<long long> answer;

  deque<pair<int, int>> dq;

  for (vector<int> &query : queries) {
    if (query[0] == 1) {
      int a = query[1];
      int b = query[2];

      dq.push_back({a, b});
    } else {
      long long sum = 0;
      int a = query[1];

      while (!dq.empty() && a > 0) {
        int diff = min(a, dq.front().first);
        a -= diff;

        dq.front().first -= diff;

        sum += (long long) dq.front().second * diff;
        if (dq.front().first == 0) {
          dq.pop_front();
        }
      }

      answer.push_back(sum);
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

  int Q;
  cin >> Q;

  vector<vector<int>> queries(Q);

  for (int i = 0; i < Q; i++) {
    int type;
    cin >> type;
    queries[i].push_back(type);

    if (type == 1) {
      int a, b;
      cin >> a >> b;
      queries[i].push_back(a);
      queries[i].push_back(b);
    } else {
      int a;
      cin >> a;
      queries[i].push_back(a);
    }
  }

  vector<long long> answer = solution(Q, queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << "\n";
  }
  // cout << endl;

  return 0;
}