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

long long solution(int size, vector<pair<int, int>> intervals) {
  // find cross pairs of intervals

  long long answer = 0;
  // sort by end time
  sort(
      intervals.begin(), intervals.end(),
      [](pair<int, int> &a, pair<int, int> &b) { return a.second < b.second; });

  vector<int> rights;
  for (int i = 0; i < size; i++) {
    int left = intervals[i].first;

    // find right count left <= right
    int overCount =
        rights.end() - lower_bound(rights.begin(), rights.end(), left);

    answer += overCount;
    rights.push_back(intervals[i].second);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./temp_input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<pair<int, int>> intervals(N);

  for (int i = 0; i < N; i++) {
    cin >> intervals[i].first >> intervals[i].second;
  }

  long long answer = solution(N, intervals);

  cout << answer << endl;

  return 0;
}