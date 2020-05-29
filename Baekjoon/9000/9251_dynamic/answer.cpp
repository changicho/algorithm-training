#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lcs[1001][1001];

void solution() {
  string first, second;

  cin >> first >> second;

  for (int i = 1; i <= first.length(); i++) {
    for (int j = 1; j <= second.length(); j++) {
      if (first[i - 1] == second[j - 1]) {
        lcs[i][j] = lcs[i - 1][j - 1] + 1;
      } else {
        lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
      }
    }
  }

  int answer = lcs[first.length()][second.length()];
  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}