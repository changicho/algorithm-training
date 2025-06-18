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

vector<int> solution(int n, int size, vector<int> &queries) {
  vector<int> answer;

  int count[101] = {
      0,
  };
  map<int, set<int>> mp;
  for (int i = 1; i <= n; i++) {
    mp[0].insert(i);
  }

  for (int &q : queries) {
    int ret = 0;
    int target = 0;

    if (q == 0) {
      auto it = mp.begin();
      target = *it->second.begin();
    } else {
      target = q;
    }

    ret = target;

    mp[count[target]].erase(target);
    if (mp[count[target]].empty()) {
      mp.erase(count[target]);
    }
    count[target]++;
    mp[count[target]].insert(target);

    answer.push_back(ret);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, Q;
  cin >> N >> Q;

  vector<int> X(Q);
  for (int i = 0; i < Q; i++) {
    cin >> X[i];
  }

  vector<int> answer = solution(N, Q, X);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << " ";
  }
  cout << endl;

  return 0;
}