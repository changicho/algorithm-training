#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

bool check(vector<Axis> &axises) {
  int size = axises.size();

  unordered_set<int> ys;
  unordered_map<int, vector<int>> y2x;
  unordered_map<int, int> counts;

  for (Axis &cur : axises) {
    ys.insert(cur.y);
    y2x[cur.y].push_back(cur.x);
    counts[cur.x]++;
  }

  if (ys.size() <= 3) return true;

  // pick one y line
  for (int y : ys) {
    for (int x : y2x[y]) {
      counts[x]--;
      if (counts[x] == 0) counts.erase(x);
    }

    if (counts.size() <= 2) return true;

    for (int x : y2x[y]) {
      counts[x]++;
    }
  }
  return false;
}

bool solution(vector<Axis> &axises) {
  vector<Axis> reversed;
  for (Axis &cur : axises) {
    reversed.push_back({cur.x, cur.y});
  }

  return check(axises) || check(reversed);
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<Axis> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].y >> A[i].x;
  }

  bool answer = solution(A);
  cout << answer << "\n";

  return 0;
}