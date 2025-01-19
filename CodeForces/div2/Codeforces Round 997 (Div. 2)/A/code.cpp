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

struct Axis {
  int y, x;
};

int solution(int n, int m, vector<Axis>& axises) {
  Axis cur = {0, 0};

  int answer = 0;
  int beforeY = -m, beforeX = -m;

  for (Axis& axis : axises) {
    cur.y += axis.y;
    cur.x += axis.x;

    answer += 4 * m;
    if (beforeX + m > cur.x) {
      answer -= 2 * (beforeX + m - cur.x);
    }
    if (beforeY + m > cur.y) {
      answer -= 2 * (beforeY + m - cur.y);
    }

    beforeY = cur.y;
    beforeX = cur.x;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N, M;
    cin >> N >> M;

    vector<Axis> axises(N);

    for (int i = 0; i < N; i++) {
      cin >> axises[i].x >> axises[i].y;
    }

    int answer = solution(N, M, axises);

    cout << answer << endl;
  }

  return 0;
}