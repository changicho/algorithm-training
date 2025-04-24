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

vector<int> solution(vector<vector<int>> &queries) {
  queue<int> q;
  vector<int> answer;
  for (auto &query : queries) {
    if (query[0] == 1) {
      q.push(query[1]);
    } else {
      answer.push_back(q.front());
      q.pop();
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
    int A, B;
    cin >> A;

    if (A == 1) {
      cin >> B;
      queries[i].push_back(A);
      queries[i].push_back(B);
    } else {
      queries[i].push_back(A);
    }
  }

  auto answer = solution(queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << "\n";
  }
  // cout << endl;

  return 0;
}