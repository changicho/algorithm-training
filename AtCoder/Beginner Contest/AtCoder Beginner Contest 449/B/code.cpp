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

vector<int> solution(int height, int width, int size,
                     vector<pair<int, int>>& queries) {
  vector<int> answer;

  for (pair<int, int>& q : queries) {
    int type = q.first;
    int index = q.second;

    if (type == 1) {
      // row

      int cur = width * index;
      answer.push_back(cur);

      height -= index;

    } else {
      // col

      int cur = height * index;
      answer.push_back(cur);

      width -= index;
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

  int H, W, Q;
  cin >> H >> W >> Q;

  vector<pair<int, int>> queries(Q);
  for (int i = 0; i < Q; i++) {
    cin >> queries[i].first >> queries[i].second;
  }

  auto answer = solution(H, W, Q, queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}