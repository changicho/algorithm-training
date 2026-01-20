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

vector<string> solution(int n, string& s, int m, string& t, int q,
                        vector<string>& words) {
  vector<string> answer;

  int takahashiBit = 0;
  int aokiBit = 0;

  for (char& c : s) {
    takahashiBit |= (1 << (c - 'a'));
  }
  for (char& c : t) {
    aokiBit |= (1 << (c - 'a'));
  }

  for (string& word : words) {
    int bit = 0;
    for (char& c : word) {
      bit |= (1 << (c - 'a'));
    }

    bool canTakahashi = (takahashiBit & bit) == bit;
    bool canAoki = (aokiBit & bit) == bit;

    if (canTakahashi == canAoki) {
      answer.push_back("Unknown");
    } else if (canTakahashi) {
      answer.push_back("Takahashi");
    } else if (canAoki) {
      answer.push_back("Aoki");
    } else {
      answer.push_back("Unknown");
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

  int N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;
  int Q;
  cin >> Q;
  vector<string> words(Q);
  for (int i = 0; i < Q; i++) {
    cin >> words[i];
  }

  vector<string> answer = solution(N, S, M, T, Q, words);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}