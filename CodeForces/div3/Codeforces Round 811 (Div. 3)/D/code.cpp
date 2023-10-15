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

vector<pair<int, int>> solution(string &t, vector<string> &s) {
  int length = t.length();

  vector<pair<int, int>> answer;

  int left = -1, right = 0, index = 0;
  while (index < length) {
    int tempR = -1, tempL = -1, sIndex = 0;

    for (int from = left + 1; from <= right; from++) {
      for (int i = 0; i < s.size(); i++) {
        if (t.substr(from, s[i].size()) != s[i]) continue;

        int to = from + s[i].size();
        if (tempR < to) {
          tempL = from, tempR = to;
          sIndex = i;
        }
      }
    }
    if (tempR == -1) return {};

    answer.push_back({sIndex, tempL});
    left = tempL, right = tempR;
    index = right;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    string T;
    int N;
    cin >> T >> N;

    vector<string> S(N);
    for (int i = 0; i < N; i++) {
      cin >> S[i];
    }

    vector<pair<int, int>> answer = solution(T, S);

    if (answer.size() == 0) {
      cout << "-1\n";
    } else {
      cout << answer.size() << "\n";
      for (pair<int, int> d : answer) {
        cout << d.first + 1 << " " << d.second + 1 << "\n";
      }
    }
  }

  return 0;
}