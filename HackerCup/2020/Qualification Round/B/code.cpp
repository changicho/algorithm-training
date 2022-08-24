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

// time : 20min
bool solution(int size, string stones) {
  string curStack = "";

  for (char &c : stones) {
    curStack.push_back(c);

    while (curStack.length() >= 3) {
      map<char, int> counts;
      for (int i = 0; i < 3; i++) {
        counts[curStack[curStack.length() - 1 - i]]++;
      }

      if (counts.size() <= 1) break;
      char next = 'A';
      if (counts['B'] == 2) {
        next = 'B';
      }

      for (int i = 0; i < 3; i++) {
        curStack.pop_back();
      }
      curStack.push_back(next);
    }
  }

  return curStack.length() == 1;
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
    string C;
    cin >> N >> C;

    bool answer = solution(N, C);

    cout << "Case #" << testCase << ": ";
    cout << (answer ? 'Y' : 'N') << "\n";
  }

  return 0;
}