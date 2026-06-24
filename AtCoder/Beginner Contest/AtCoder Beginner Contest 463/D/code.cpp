#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;
using pii = pair<int, int>;

bool check(int d, int k, vector<pii>& arr) {
  int size = arr.size();

  vector<pii> chosen;
  for (int i = 0; i < size; i++) {
    pii& cur = arr[i];

    if (chosen.empty()) {
      chosen.push_back(cur);
      continue;
    }

    if (!chosen.empty() && (cur.first - chosen.back().second) >= d) {
      chosen.push_back(cur);
    } else {
      continue;
    }
  }

  return chosen.size() >= k;
}

int solution(int size, int k, vector<pii>& arr) {
  int answer = -1;
  int left = 1, right = INT_MAX;

  sort(arr.begin(), arr.end(),
       [](auto& a, auto& b) { return a.second < b.second; });

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (check(mid, k, arr)) {
      // pick right
      answer = mid;
      left = mid + 1;
    } else {
      // pick left
      right = mid;
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, K;
  cin >> N >> K;

  vector<pii> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  auto answer = solution(N, K, arr);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}