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

struct Storm {
  char type;
  long long A;
  long long B;
};

struct Area {
  long long x1, y1, x2, y2;

  long long size() { return (x2 - x1 + 1) * (y2 - y1 + 1); }
};

auto solution(int n, long long x, long long y, vector<Storm>& storms) {
  vector<Area> areas;
  areas.push_back({0, 0, x - 1, y - 1});

  for (Storm& storm : storms) {
    vector<Area> next_areas;

    if (storm.type == 'X') {
      // x < A : down B
      // x >= A : up B
      for (auto& area : areas) {
        if (area.x2 < storm.A) {
          // down B
          Area newArea = {area.x1, area.y1 - storm.B, area.x2,
                          area.y2 - storm.B};
          next_areas.push_back(newArea);
        } else if (area.x1 >= storm.A) {
          // up B
          Area newArea = {area.x1, area.y1 + storm.B, area.x2,
                          area.y2 + storm.B};
          next_areas.push_back(newArea);
        } else {
          // split
          Area downArea = {area.x1, area.y1 - storm.B, storm.A - 1,
                           area.y2 - storm.B};
          Area upArea = {storm.A, area.y1 + storm.B, area.x2,
                         area.y2 + storm.B};
          next_areas.push_back(downArea);
          next_areas.push_back(upArea);
        }
      }
    } else {
      // y < A : left B
      // y >= A : right B

      for (auto& area : areas) {
        if (area.y2 < storm.A) {
          // left B
          Area newArea = {area.x1 - storm.B, area.y1, area.x2 - storm.B,
                          area.y2};
          next_areas.push_back(newArea);
        } else if (area.y1 >= storm.A) {
          // right B
          Area newArea = {area.x1 + storm.B, area.y1, area.x2 + storm.B,
                          area.y2};
          next_areas.push_back(newArea);
        } else {
          // split
          Area leftArea = {area.x1 - storm.B, area.y1, area.x2 - storm.B,
                           storm.A - 1};
          Area rightArea = {area.x1 + storm.B, storm.A, area.x2 + storm.B,
                            area.y2};
          next_areas.push_back(leftArea);
          next_areas.push_back(rightArea);
        }
      }
    }

    areas = next_areas;
  }

  int areaSize = areas.size();

  vector<int> parents(areaSize, 0);
  for (int i = 0; i < areaSize; i++) {
    parents[i] = i;
  }
  vector<long long> childrens(areaSize, 0);
  for (int i = 0; i < areaSize; i++) {
    childrens[i] = areas[i].size();
  }

  function<int(int)> find = [&](int node) {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  };

  function<void(int, int)> merge = [&](int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    parents[b] = a;
    childrens[a] += childrens[b];
    childrens[b] = 0;
  };

  function<bool(Area, Area)> isConnected = [](Area a, Area b) {
    // check x connected
    if (a.x2 + 1 == b.x1 || b.x2 + 1 == a.x1) {
      if (a.y2 >= b.y1 && b.y2 >= a.y1) {
        return true;
      }
    }

    // check y connected
    if (a.y2 + 1 == b.y1 || b.y2 + 1 == a.y1) {
      if (a.x2 >= b.x1 && b.x2 >= a.x1) {
        return true;
      }
    }

    return false;
  };

  for (int i = 0; i < areaSize; i++) {
    for (int j = i + 1; j < areaSize; j++) {
      if (isConnected(areas[i], areas[j])) {
        merge(i, j);
      }
    }
  }

  vector<long long> answer;

  for (int i = 0; i < areaSize; ++i) {
    if (parents[i] == i && childrens[i] > 0) {
      answer.push_back(childrens[i]);
    }
  }
  sort(answer.begin(), answer.end());
  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  long long X, Y;
  cin >> N >> X >> Y;

  vector<Storm> storms(N);
  for (int i = 0; i < N; ++i) {
    char c;
    long long a, b;
    cin >> c >> a >> b;
    storms[i] = {c, a, b};
  }

  auto answer = solution(N, X, Y, storms);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  cout << answer.size() << "\n";
  for (auto& line : answer) {
    cout << line << " ";
  }
  cout << endl;

  return 0;
}