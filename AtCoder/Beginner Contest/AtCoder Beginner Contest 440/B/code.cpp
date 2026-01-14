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

vector<int> solution(int size, vector<int>& times) {
  vector<int> answer;

  vector<pair<int, int>> indexedTimes;
  for (int i = 0; i < size; i++) {
    indexedTimes.push_back({times[i], i + 1});
  }
  sort(indexedTimes.begin(), indexedTimes.end());

  for (int i = 0; i < 3; i++) {
    answer.push_back(indexedTimes[i].second);
  }

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

  vector<int> T(N);
  for (int i = 0; i < N; i++) {
    cin >> T[i];
  }

  auto answer = solution(N, T);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << " ";
  }
  cout << endl;

  return 0;
}