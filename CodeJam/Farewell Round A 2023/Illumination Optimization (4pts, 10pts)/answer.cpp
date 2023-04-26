#include <algorithm>
#include <climits>
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

int solution(int length, int radius, vector<int> &positions) {
  int answer = 0;

  set<int> axises(positions.begin(), positions.end());
  axises.insert(INT_MAX);
  axises.insert(INT_MIN);

  int boundaryEnd = radius;

  while (boundaryEnd < (length + radius)) {
    // boundaryEnd < target
    auto it = prev(axises.upper_bound(boundaryEnd));

    if (it == axises.begin()) return -1;
    int target = *it;
    axises.erase(target);

    answer++;

    if (target + radius >= length) break;
    int nextBoundaryEnd = target + radius * 2;
    boundaryEnd = nextBoundaryEnd;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int M, R, N;
    cin >> M >> R >> N;

    vector<int> positions(N);
    for (int i = 0; i < N; i++) {
      cin >> positions[i];
    }

    int answer = solution(M, R, positions);

    // cout << "Case #" << testCase << ": " << (answer ? "YES" : "NO") << endl;
    cout << "Case #" << testCase << ": ";

    if (answer == -1) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << answer << endl;
    }
  }

  return 0;
}