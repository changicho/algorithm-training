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
using pii = pair<int, int>;

struct Data {
  int h, l;

  bool operator<(const Data& b) const { return l > b.l; }
};

vector<int> solution(int size, vector<Data>& arr, int qSize,
                     vector<int>& queries) {
  sort(arr.begin(), arr.end(), [](auto& a, auto& b) { return a.l < b.l; });
  priority_queue<Data> pq;
  multiset<int> ms;
  for (Data& cur : arr) {
    pq.push(cur);
    ms.insert(cur.h);
  }

  vector<int> answer(qSize);
  vector<pii> q;
  for (int i = 0; i < qSize; i++) {
    q.push_back({queries[i], i});
  }
  sort(q.begin(), q.end());

  for (int i = 0; i < qSize; i++) {
    int time = q[i].first;
    int target = q[i].second;

    while (!pq.empty() && pq.top().l <= time) {
      ms.erase(pq.top().h);
      pq.pop();
    }

    if (!ms.empty()) {
      answer[target] = *ms.rbegin();
    } else {
      answer[target] = 0;
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

  vector<Data> arr(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i].h >> arr[i].l;
  }

  int Q;
  cin >> Q;

  vector<int> queries(Q);
  for (int i = 0; i < Q; i++) {
    cin >> queries[i];
  }

  auto answer = solution(N, arr, Q, queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}