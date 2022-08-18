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

// time : 30min
int solution(string &s, unordered_set<string> &edges) {
  int length = s.length();
  long costs[256][256] = {
      INT_MAX,
  };
  vector<vector<char>> graph(256);
  unordered_map<char, int> counts;

  for (char from = 'A'; from <= 'Z'; from++) {
    for (char to = 'A'; to <= 'Z'; to++) {
      costs[from][to] = from == to ? 0 : INT_MAX;
    }
  }
  for (string edge : edges) {
    char from = edge.front();
    char to = edge.back();

    graph[from].push_back(to);
    costs[from][to] = 1;
  }

  for (char &c : s) {
    counts[c]++;
  }

  for (char through = 'A'; through <= 'Z'; through++) {
    for (int from = 'A'; from <= 'Z'; from++) {
      for (int to = 'A'; to <= 'Z'; to++) {
        costs[from][to] =
            min(costs[from][to], costs[from][through] + costs[through][to]);
      }
    }
  }

  int answer = INT_MAX;
  for (char target = 'A'; target <= 'Z'; target++) {
    int curCost = 0;
    bool canConvert = true;
    for (auto &it : counts) {
      char c = it.first;
      int count = it.second;

      if (c == target) continue;

      if (costs[c][target] == INT_MAX) {
        canConvert = false;
        break;
      }
      curCost += costs[c][target] * count;
    }

    if (!canConvert) continue;
    answer = min(answer, curCost);
  }

  if (answer == INT_MAX) return -1;
  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    string S;
    cin >> S;
    int K;
    cin >> K;

    unordered_set<string> edges;
    for (int i = 0; i < K; i++) {
      string edge;
      cin >> edge;
      edges.insert(edge);
    }

    int answer = solution(S, edges);

    cout << "Case #" << testCase << ": ";
    cout << answer << "\n";
  }

  return 0;
}