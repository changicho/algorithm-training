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

int solution(string x, string s) {
  int count = 0;
  while (x.size() < s.size()) {
    x += x;
    count++;
  }

  if (x.find(s) == string::npos) {
    x += x;
    count++;
  }

  if (x.find(s) == string::npos) {
    return -1;
  }

  return count;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N, M;
    cin >> N >> M;

    string X, S;
    cin >> X >> S;

    double answer = solution(X, S);

    // cout << (answer ? "YES" : "NO") << "\n";
    cout << answer << "\n";
  }

  return 0;
}