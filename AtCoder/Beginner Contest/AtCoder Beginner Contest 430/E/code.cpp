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

int kmp(string& line, string& pattern) {
  int size = line.size(), pSize = pattern.size();
  vector<int> pIndexes(pSize, 0);

  for (int i = 1, pI = 0; i < pSize; i++) {
    while (pI > 0 && pattern[i] != pattern[pI]) {
      pI = pIndexes[pI - 1];
    }
    if (pattern[i] == pattern[pI]) {
      pI++;
      pIndexes[i] = pI;
    }
  }

  for (int i = 0, pI = 0; i < size; i++) {
    while (pI > 0 && line[i] != pattern[pI]) {
      pI = pIndexes[pI - 1];
    }

    if (line[i] == pattern[pI]) {
      if (pI == pSize - 1) {
        return i - pSize + 1;

        pI = pIndexes[pI];
      } else {
        pI++;
      }
    }
  }

  return -1;
}

auto solution(string& a, string& b) {
  a += a;

  int answer = kmp(a, b);

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    string A, B;
    cin >> A >> B;

    auto answer = solution(A, B);

    cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}