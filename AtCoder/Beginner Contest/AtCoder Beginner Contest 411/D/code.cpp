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
  int type, p;
  string s;
};

string solution(int size, int qSize, vector<Query> &queries) {
  string answer = "";

  stack<int> wordIndexs;

  int target = 0;
  for (int i = qSize - 1; i >= 0; i--) {
    if (queries[i].type == 1) {
      if (target == queries[i].p) {
        target = 0;
      }
    } else if (queries[i].type == 2) {
      if (queries[i].p == target) {
        wordIndexs.push(i);
      }
    } else if (queries[i].type == 3) {
      if (target == 0) {
        target = queries[i].p;
      }
    }
  }

  while (!wordIndexs.empty()) {
    int index = wordIndexs.top();
    wordIndexs.pop();

    answer += queries[index].s;
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

  vector<Query> queries(Q);

  for (int i = 0; i < Q; i++) {
    int type, p;
    string s;

    cin >> queries[i].type >> queries[i].p;
    if (queries[i].type == 2) {
      cin >> queries[i].s;
    }
  }

  string answer = solution(N, Q, queries);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}