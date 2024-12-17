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

struct ARC {
  int div, performance;
};

// In ARC Div. 1, 1600 and 2799
// In ARC Div. 2, 1200 and 2399
int solution(int n, int rating, vector<ARC> &arcs) {
  int answer = rating;

  vector<pair<int, int>> divs = {{1600, 2799}, {1200, 2399}};

  for (ARC &arc : arcs) {
    int left = divs[arc.div - 1].first, right = divs[arc.div - 1].second;

    if (left <= answer && answer <= right) {
      answer += arc.performance;
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

  int N, R;
  cin >> N >> R;

  vector<ARC> arcs(N);

  for (int i = 0; i < N; i++) {
    cin >> arcs[i].div >> arcs[i].performance;
  }

  int answer = solution(N, R, arcs);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}