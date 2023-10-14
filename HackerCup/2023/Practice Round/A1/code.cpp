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

bool solution(int s, int d, int k) {
  int bun = 0;
  int cheese = 0;
  int patty = 0;

  bun += s * 2;
  bun += d * 2;

  cheese += s;
  cheese += d * 2;

  patty += s;
  patty += d * 2;

  int needB = k + 1, needC = k, needP = k;

  if (bun >= needB && cheese >= needC && patty >= needP) return true;
  return false;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./A1.txt", "r", stdin);
  freopen("./cheeseburger_corollary_1_input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int S, D, K;
    cin >> S >> D >> K;

    bool answer = solution(S, D, K);

    cout << "Case #" << testCase << ": " << (answer ? "YES" : "NO") << "\n";
  }

  return 0;
}