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

struct Test {
  vector<int> inserted;
  char result;
};

int solution(int n, int k, vector<Test> &tests) {
  // do something
  int answer = 0;

  for (int bit = 0; bit < (1 << n); bit++) {
    bool isPossible = true;

    for (Test &test : tests) {
      int inserted = 0;

      for (int &key : test.inserted) {
        if (bit & (1 << (key - 1))) {
          inserted++;
        }
      }

      if (inserted >= k && test.result == 'o') {
        continue;
      } else if (inserted < k && test.result == 'x') {
        continue;
      } else {
        isPossible = false;
        break;
      }
    }

    if (isPossible) {
      answer++;
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

  int N, M, K;

  cin >> N >> M >> K;

  vector<Test> tests(M);

  for (int i = 0; i < M; i++) {
    int C;
    cin >> C;

    tests[i].inserted.resize(C);
    for (int j = 0; j < C; j++) {
      cin >> tests[i].inserted[j];
    }
    cin >> tests[i].result;
  }

  int answer = solution(N, K, tests);

  cout << answer << endl;

  return 0;
}