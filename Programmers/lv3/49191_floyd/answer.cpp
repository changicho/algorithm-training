#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define INF 1e9

using namespace std;

int graph[101][101];

int solution(int n, vector<vector<int>> results) {
  int answer = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      graph[i][j] = i == j ? 0 : INF;
    }
  }

  for (vector<int> v : results) {
    int first = v[0];
    int second = v[1];

    graph[second][first] = 1;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (graph[i][j] > graph[i][k] + graph[k][j]) {
          graph[i][j] = graph[i][k] + graph[k][j];
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    bool canJudge = 1;

    for (int j = 1; j <= n; j++) {
      if (graph[i][j] == INF && graph[j][i] == INF) {
        canJudge = 0;
        break;
      }
    }
    if (canJudge) answer++;
  }

  return answer;
}