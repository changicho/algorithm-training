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

struct Axis {
  int y, x;
};

long long getDist(Axis &a, Axis &b) {
  return (long long)(a.x - b.x) * (a.x - b.x) +
         (long long)(a.y - b.y) * (a.y - b.y);
}

vector<int> solution(int size, vector<Axis> &axises) {
  vector<int> ret;

  for (int i = 0; i < size; i++) {
    long long dist = 0;
    int target = -1;

    for (int j = 0; j < size; j++) {
      if (i == j) continue;

      long long temp = getDist(axises[i], axises[j]);

      if (temp > dist) {
        dist = temp;
        target = j;
      }
    }

    ret.push_back(target + 1);
  }

  return ret;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;
  vector<Axis> axises(N);
  for (int i = 0; i < N; i++) {
    cin >> axises[i].x >> axises[i].y;
  }

  vector<int> answer = solution(N, axises);

  for (int &ans : answer) {
    cout << ans << '\n';
  }

  return 0;
}