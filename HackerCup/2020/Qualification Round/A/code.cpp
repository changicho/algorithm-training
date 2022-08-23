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
struct Edge {
  int from, to, cost;
};

vector<string> solution(int n, string in, string out) {
  vector<string> answer(n, string(n, 'N'));

  for (int i = 0; i < n; i++) {
    answer[i][i] = 'Y';
  }

  for (int from = 0; from < n; from++) {
    for (int to = from + 1; to < n; to++) {
      if (in[to] == 'Y' && out[to - 1] == 'Y') {
        answer[from][to] = 'Y';
      } else {
        break;
      }
    }

    for (int to = from - 1; to >= 0; to--) {
      if (in[to] == 'Y' && out[to + 1] == 'Y') {
        answer[from][to] = 'Y';
      } else {
        break;
      }
    }
  }

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
    int N;
    cin >> N;

    string I, O;
    cin >> I >> O;

    vector<string> answer = solution(N, I, O);

    cout << "Case #" << testCase << ":\n";
    for (string &a : answer) {
      cout << a << "\n";
    }
    // cout << answer << "\n";
  }

  return 0;
}