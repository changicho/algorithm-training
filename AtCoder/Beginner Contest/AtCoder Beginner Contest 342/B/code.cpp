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

vector<int> solution(vector<int> &positions, vector<vector<int>> &queries) {
  int size = positions.size();

  vector<int> answer;
  vector<int> orders(size + 1);
  for (int i = 0; i < size; i++) {
    orders[positions[i]] = i + 1;
  }

  for (vector<int> &query : queries) {
    int a = query[0], b = query[1];

    if (orders[a] < orders[b]) {
      answer.push_back(a);
    } else {
      answer.push_back(b);
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

  int N;
  cin >> N;

  vector<int> P(N);
  for (int i = 0; i < N; i++) {
    cin >> P[i];
  }

  int Q;
  cin >> Q;

  vector<vector<int>> queries(Q, vector<int>(2));
  for (int i = 0; i < Q; i++) {
    cin >> queries[i][0] >> queries[i][1];
  }

  vector<int> answer = solution(P, queries);

  for (int &a : answer) {
    cout << a << '\n';
  }
  return 0;
}