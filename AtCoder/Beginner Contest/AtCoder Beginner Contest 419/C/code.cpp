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

auto solution(int size, vector<Axis> &people) {
  int yMin = INT_MAX, yMax = INT_MIN;
  int xMin = INT_MAX, xMax = INT_MIN;

  for (Axis &p : people) {
    yMin = min(yMin, p.y);
    yMax = max(yMax, p.y);

    xMin = min(xMin, p.x);
    xMax = max(xMax, p.x);
  }

  int yDiff = ceil(((double)yMax - yMin) / 2);
  int xDiff = ceil(((double)xMax - xMin) / 2);
  int answer = max(yDiff, xDiff);

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<Axis> people(N);
  for (int i = 0; i < N; i++) {
    cin >> people[i].y >> people[i].x;
  }

  auto answer = solution(N, people);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}