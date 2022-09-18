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

// time :
const int MOD = 1e9 + 7;

struct Axis {
  int y, x;
};

int getLength(Axis &a, Axis &b) {
  long long yDiff = abs(a.y - b.y);
  long long xDiff = abs(a.x - b.x);

  long long ret = (yDiff * yDiff) % MOD + (xDiff * xDiff) % MOD;
  ret %= MOD;
  return (int)ret;
}

int solution(int n, int q, vector<Axis> &trees, vector<Axis> &waters) {
  long long answer = 0;

  vector<int> treeXs(3001, 0), treeYs(3001, 0), waterXs(3001, 0),
      waterYs(3001, 0);

  for (Axis &tree : trees) {
    treeXs[tree.x]++;
    treeYs[tree.y]++;
  }

  for (Axis &water : waters) {
    waterXs[water.x]++;
    waterYs[water.y]++;
  }

  // calculate y
  for (int wy = 0; wy <= 3000; wy++) {
    if (waterYs[wy] == 0) continue;

    for (int ty = 0; ty <= 3000; ty++) {
      if (treeYs[ty] == 0) continue;

      long long diff = abs(wy - ty);
      long long length = (diff * diff) % MOD;
      long long diffSum = (length * waterYs[wy] * treeYs[ty]) % MOD;

      answer += diffSum;
      answer %= MOD;
    }
  }

  // calculate x
  for (int wx = 0; wx <= 3000; wx++) {
    if (waterXs[wx] == 0) continue;

    for (int tx = 0; tx <= 3000; tx++) {
      if (treeXs[tx] == 0) continue;

      long long diff = abs(wx - tx);
      long long length = (diff * diff) % MOD;
      long long diffSum = (length * waterXs[wx] * treeXs[tx]) % MOD;

      answer += diffSum;
      answer %= MOD;
    }
  }

  return answer % MOD;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./watering_well_chapter_1_input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N, Q;

    cin >> N;
    vector<Axis> trees(N);
    for (int i = 0; i < N; i++) {
      cin >> trees[i].y >> trees[i].x;
    }

    cin >> Q;
    vector<Axis> waters(Q);
    for (int i = 0; i < Q; i++) {
      cin >> waters[i].y >> waters[i].x;
    }

    int answer = solution(N, Q, trees, waters);

    cout << "Case #" << testCase << ": ";
    cout << answer << "\n";
  }

  return 0;
}