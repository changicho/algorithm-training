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

vector<int> solution(int size, int dishSize, vector<vector<int>> &dishes,
                     vector<int> &overcomes) {
  vector<int> answer;
  unordered_map<int, int> overcomeMap;
  for (int i = 0; i < size; i++) {
    overcomeMap[overcomes[i]] = i;
  }

  vector<int> diffs(size, 0);
  for (int i = 0; i < dishSize; i++) {
    int maximum = -1;
    for (int &dish : dishes[i]) {
      maximum = max(maximum, overcomeMap[dish]);
    }

    int endTime = maximum;
    diffs[endTime] += 1;
  }

  int temp = 0;
  for (int i = 0; i < size; i++) {
    temp += diffs[i];
    answer.push_back(temp);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> dishes(M);

  for (int i = 0; i < M; i++) {
    int K;
    cin >> K;

    for (int j = 0; j < K; j++) {
      int dish;
      cin >> dish;
      dishes[i].push_back(dish);
    }
  }

  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }

  vector<int> answer = solution(N, M, dishes, B);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << "\n";
  }
  // cout << endl;

  return 0;
}