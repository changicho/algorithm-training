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

struct Query {
  int type;
  int height;
};

vector<int> solution(int size, vector<Query>& queries) {
  vector<int> answer;

  // 1 height : add height
  // 2 height : remove at most height

  priority_queue<int, vector<int>, greater<int>> pq;

  for (Query& q : queries) {
    if (q.type == 1) {
      pq.push(q.height);
    } else {
      while (!pq.empty() && pq.top() <= q.height) {
        pq.pop();
      }
    }

    answer.push_back(pq.size());
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

  vector<Query> queries(Q);

  for (int i = 0; i < Q; i++) {
    cin >> queries[i].type >> queries[i].height;
  }

  auto answer = solution(Q, queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}