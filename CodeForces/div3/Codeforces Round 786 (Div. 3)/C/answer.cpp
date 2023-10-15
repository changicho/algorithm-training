#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// time : O(T)
// space : O(1)
long long solution(string s, string t) {
  int length = s.length();

  if (t == "a") return 1;

  for (char &c : t) {
    if (c == 'a') return -1;
  }

  long long res = pow(2, length);

  return res;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    string s, t;
    cin >> s >> t;

    long long res = solution(s, t);

    cout << res << "\n";
  }

  return 0;
}