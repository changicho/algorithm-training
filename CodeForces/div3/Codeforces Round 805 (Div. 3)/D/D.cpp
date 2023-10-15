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

// time : 10min
string solution(string &w, int p) {
  vector<int> indexes[27];
  vector<bool> isDeleted(w.size(), false);

  int scoreSum = 0;
  for (int i = 0; i < w.size(); i++) {
    char c = w[i];
    indexes[c - 'a'].push_back(i);
    scoreSum += (c - 'a' + 1);
  }

  for (char c = 'z'; c >= 'a'; c--) {
    while (scoreSum > p && indexes[c - 'a'].size() > 0) {
      int target = indexes[c - 'a'].back();
      indexes[c - 'a'].pop_back();

      isDeleted[target] = true;
      scoreSum -= (c - 'a' + 1);
    }
  }

  string ret = "";
  for (int i = 0; i < w.size(); i++) {
    if (isDeleted[i]) continue;
    ret += w[i];
  }
  return ret;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    string W;
    cin >> W;

    int P;
    cin >> P;

    string answer = solution(W, P);
    cout << answer << "\n";
  }

  return 0;
}