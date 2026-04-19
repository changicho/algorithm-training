#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

typedef long long ll;

ll solution(int n, int k) {
  const int MOD = 1e9 + 7;
  vector<ll> factorial(n + 1, 1);
  for (int i = 2; i <= n; i++) {
    factorial[i] = (factorial[i - 1] * i) % MOD;
  }

  function<ll(ll, ll)> myPow = [](ll base, ll expo) {
    ll result = 1;

    while (expo > 0) {
      if (expo % 2 == 1) {
        result *= base;
        result %= MOD;
      }
      base = (base * base) % MOD;
      expo /= 2;
    }
    return result;
  };

  function<ll(ll, ll)> combi = [&](ll n, ll k) {
    if (k > n || k < 0) return 0LL;
    if (k == 0 || k == n) return 1LL;

    ll numer = factorial[n] % MOD;
    ll denom = (factorial[k] * factorial[n - k]) % MOD;

    return numer * myPow(denom, MOD - 2) % MOD;
  };

  ll answer = combi(n, k);

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  ll N, K;
  cin >> N >> K;

  ll answer = solution(N, K);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}