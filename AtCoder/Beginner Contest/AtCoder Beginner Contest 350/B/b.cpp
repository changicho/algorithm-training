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

int solution(int size, vector<int> &queries) {
  unordered_set<int> erased;

  for (int &q : queries) {
    if (erased.count(q)) {
      erased.erase(q);
    } else {
      erased.insert(q);
    }
  }

  return size - erased.size();
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, Q;
  cin >> N >> Q;

  vector<int> queries(Q);
  for (int i = 0; i < Q; i++) {
    cin >> queries[i];
  }

  int answer = solution(N, queries);

  cout << answer << endl;
  return 0;
}