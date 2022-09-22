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

struct Model {
  int color, changeCount;

  bool operator<(const Model &b) const {
    if (color != b.color) {
      return color < b.color;
    }
    return changeCount > b.changeCount;
  }
};

int solution(int n, int m, vector<int> &s, vector<vector<int>> &p) {
  vector<Model> models(m);
  for (int i = 0; i < m; i++) {
    int color = s[i];
    models[i].color = color;
    models[i].changeCount = 0;
  }

  for (int i = 0; i < n; i++) {
    sort(models.begin(), models.end());

    unordered_map<int, int> colorCount;
    for (int &num : p[i]) {
      colorCount[num]++;
    }

    vector<int> unusedModelIdx;

    for (int i = 0; i < m; i++) {
      Model &model = models[i];
      if (colorCount.count(model.color) > 0) {
        colorCount[model.color]--;
        if (colorCount[model.color] == 0) {
          colorCount.erase(model.color);
        }
        continue;
      }

      unusedModelIdx.push_back(i);
    }

    for (int &idx : unusedModelIdx) {
      int color = colorCount.begin()->first;
      models[idx].color = color;
      models[idx].changeCount++;

      colorCount[color]--;
      if (colorCount[color] == 0) {
        colorCount.erase(color);
      }
    }
  }

  int answer = 0;
  for (Model &model : models) {
    answer += max(model.changeCount - 1, 0);
  }
  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./runway_input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N, M;
    cin >> N >> M;
    vector<int> S(M);
    vector<vector<int>> P(N, vector<int>(M));

    for (int i = 0; i < M; i++) {
      cin >> S[i];
    }

    for (int y = 0; y < N; y++) {
      for (int x = 0; x < M; x++) {
        cin >> P[y][x];
      }
    }

    int answer = solution(N, M, S, P);

    cout << "Case #" << testCase << ": ";
    // cout << (answer ? "YES" : "NO") << "\n";
    cout << answer << "\n";
  }

  return 0;
}