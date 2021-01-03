#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string dp[101][101];

string bigNumberAdd(string a, string b) {
  int carry = 0;
  string result = "";

  while (!a.empty() || !b.empty() || carry) {
    if (!a.empty()) {
      carry += a.back() - '0';
      a.pop_back();
    }

    if (!b.empty()) {
      carry += b.back() - '0';
      b.pop_back();
    }

    result += ((carry % 10) + '0');
    carry /= 10;
  }

  reverse(result.begin(), result.end());
  return result;
}

// nCr = n-1Cr + n-1Cr-1
string combination(int n, int r) {
  if (n == r || r == 0) {
    return "1";
  }
  string &result = dp[n][r];

  if (result != "") {
    return result;
  }
  result = bigNumberAdd(combination(n - 1, r - 1), combination(n - 1, r));

  return result;
}

void solution() {
  int N, M;
  cin >> N >> M;

  string answer = combination(N, M);

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}