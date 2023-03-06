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

const int MAX = 1e9 + 1;

struct Axis {
  int x, y;
};

struct Range {
  int from, to;
};

bool isOverlapped(Range &a, Range &b) {
  if (a.to >= b.from && b.to >= a.from) return true;
  return false;
}

int getMaximumOverlapped(vector<Range> &ranges) {
  // min heap of end time
  priority_queue<int, vector<int>, greater<int>> minHeap;

  // sort by begin accending
  sort(ranges.begin(), ranges.end(),
       [](Range &a, Range &b) { return a.from < b.from; });

  int maximum = 0;
  for (Range &i : ranges) {
    int start = i.from, end = i.to;
    while (!minHeap.empty() && minHeap.top() <= start) {
      minHeap.pop();
    }

    minHeap.push(end);
    maximum = max(maximum, (int)minHeap.size());
  }

  return maximum;
}

int solution(int size, vector<Axis> &axises) {
  vector<Range> yRanges, xRanges;
  for (int i = 0; i < size; i++) {
    int next = (i + 1) % size;

    int y = axises[i].y, ny = axises[next].y;
    int x = axises[i].x, nx = axises[next].x;

    if (y == ny) {
      // push x
      xRanges.push_back({min(x, nx), max(x, nx)});
    } else {
      // push y
      yRanges.push_back({min(y, ny), max(y, ny)});
    }
  }

  int yMax = getMaximumOverlapped(yRanges),
      xMax = getMaximumOverlapped(xRanges);

  return max(yMax, xMax);
}

void init() {}

void clear() {}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  init();

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<Axis> axises(N);

  for (int i = 0; i < N; i++) {
    cin >> axises[i].x >> axises[i].y;
  }

  int answer = solution(N, axises);
  cout << answer;
  cout << "\n";

  return 0;
}
