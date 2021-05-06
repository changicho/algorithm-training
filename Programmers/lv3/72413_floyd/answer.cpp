#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
  int answer;
  s -= 1;
  a -= 1;
  b -= 1;

  vector<vector<int>> costs(n, vector<int>(n, 100000 * 200 + 1));

  for (vector<int> fare : fares) {
    int from = fare[0] - 1;
    int to = fare[1] - 1;
    int cost = fare[2];

    costs[from][to] = cost;
    costs[to][from] = cost;
  }

  for (int i = 0; i < n; i++) {
    costs[i][i] = 0;
  }

  for (int through = 0; through < n; through++) {
    for (int from = 0; from < n; from++) {
      for (int to = 0; to < n; to++) {
        costs[from][to] = min(costs[from][to], costs[from][through] + costs[through][to]);
      }
    }
  }

  answer = costs[s][a] + costs[s][b];

  for (int through = 0; through < n; through++) {
    int aCost = costs[s][through] + costs[through][a];
    int bCost = costs[through][b];

    answer = min(answer, aCost + bCost);
  }

  return answer;
}

struct TestCase {
  int n;
  int s;
  int a;
  int b;
  vector<vector<int>> fares;
  int answer;
};

int main() {
  vector<TestCase> TC{
      {6, 4, 6, 2, {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}}, 82},
      {7, 3, 4, 1, {{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}}, 14},
      {6, 4, 5, 6, {{2, 6, 6}, {6, 3, 7}, {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9}}, 18},

  };

  for (TestCase test : TC) {
    int answer = solution(test.n, test.s, test.a, test.b, test.fares);

    bool isCorrect = answer == test.answer;
    cout << isCorrect << " "
         << "MyAnswer : " << answer << ", RealAnswer : " << test.answer << "\n";
  }

  return 0;
}