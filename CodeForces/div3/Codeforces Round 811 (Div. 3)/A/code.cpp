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

// time : 8min

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N, H, M;
    cin >> N >> H >> M;

    int sleepTime = (H * 60 + M);

    vector<int> times;
    for (int i = 0; i < N; i++) {
      int h, m;
      cin >> h >> m;

      int time = (h * 60 + m);
      times.push_back(time);
    }
    sort(times.begin(), times.end());
    times.push_back(times.front() + (24 * 60));

    int target = *lower_bound(times.begin(), times.end(), sleepTime);

    int diff = target - sleepTime;

    int hour = diff / 60;
    int minute = diff % 60;

    cout << hour << " " << minute << "\n";
  }

  return 0;
}