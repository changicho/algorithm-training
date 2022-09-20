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

int solution(int n, int q, vector<Axis> &trees, vector<Axis> &waters) {
  long long answer = 0;

  unordered_map<int, int> waterXs, waterYs;
  long long treeXSum = 0, treeYSum = 0;
  long long treeXSquareSum = 0, treeYSquareSum = 0;

  for (Axis &tree : trees) {
    treeXSum += tree.x;
    treeXSum %= MOD;
    treeYSum += tree.y;
    treeYSum %= MOD;

    treeXSquareSum += ((long long)tree.x * tree.x);
    treeXSquareSum %= MOD;
    treeYSquareSum += ((long long)tree.y * tree.y);
    treeYSquareSum %= MOD;
  }

  for (Axis &water : waters) {
    waterXs[water.x]++;
    waterYs[water.y]++;
  }

  // calculate y
  for (auto &it1 : waterYs) {
    long long wy = it1.first;
    int count = it1.second;

    long long wYSquare = wy * wy;
    wYSquare %= MOD;

    long long diffSum = (wYSquare * n) + treeYSquareSum - 2 * wy * treeYSum;
    diffSum %= MOD;
    if (diffSum < 0) diffSum += MOD;
    diffSum *= count;
    diffSum %= MOD;

    answer += diffSum;
    answer %= MOD;
  }

  // calculate x
  for (auto &it1 : waterXs) {
    long long wx = it1.first;
    int count = it1.second;

    long long wXSquare = wx * wx;
    wXSquare %= MOD;

    long long diffSum = (wXSquare * n) + treeXSquareSum - 2 * wx * treeXSum;
    diffSum %= MOD;
    if (diffSum < 0) diffSum += MOD;
    diffSum *= count;
    diffSum %= MOD;

    answer += diffSum;
    answer %= MOD;
  }

  return answer % MOD;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./watering_well_chapter_2_input.txt", "r", stdin);

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