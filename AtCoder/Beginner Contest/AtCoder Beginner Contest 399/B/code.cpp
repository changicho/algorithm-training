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

vector<int> solution(int size, vector<int> &scores) {
  unordered_map<int, int> count;
  set<int> unique_scores;
  for (int &score : scores) {
    count[score]++;
    unique_scores.insert(score);
  }

  unordered_map<int, int> rank;
  int r = 1;
  for (auto it = unique_scores.rbegin(); it != unique_scores.rend(); it++) {
    rank[*it] = r;
    r += count[*it];
  }

  vector<int> answer;
  for (int &score : scores) {
    answer.push_back(rank[score]);
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

  vector<int> P(N);
  for (int i = 0; i < N; i++) {
    cin >> P[i];
  }

  vector<int> answer = solution(N, P);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}