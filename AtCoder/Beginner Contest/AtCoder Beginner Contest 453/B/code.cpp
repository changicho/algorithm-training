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

vector<pair<int, int>> solution(int time, int x, vector<int>& nums) {
  vector<pair<int, int>> answer;

  answer.push_back({0, nums[0]});
  for (int i = 1; i <= time; i++) {
    int cur = nums[i];

    if (abs(answer.back().second - cur) >= x) {
      answer.push_back({i, cur});
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

  int T, X;
  cin >> T >> X;

  vector<int> A(T + 1);

  for (int i = 0; i <= T; i++) {
    cin >> A[i];
  }

  auto answer = solution(T, X, A);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line.first << " " << line.second << "\n";
  }
  cout << endl;

  return 0;
}