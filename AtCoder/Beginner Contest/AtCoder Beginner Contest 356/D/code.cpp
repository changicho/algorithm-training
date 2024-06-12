#include <algorithm>
#include <bitset>
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

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int solution(ll n, ll m) {
  const ll MOD = 998244353;

  for (ull i = 0; i < 64; i++) {
    if (m & (1ULL << i) && n < (1ULL << i)) {
      m -= (1ULL << i);
    }
  }

  ll answer = 0;

  for (ull i = 0; i < 64; i++) {
    if (m & (1LL << i)) {
      ll temp, totalLeft, totalRight;
      if (n & (1LL << i)) {
        temp = n;
        totalLeft = ((temp >> (i + 1)) << i);
        totalRight = temp % (1LL << i);
      } else {
        temp = n - (1LL << i);
        totalLeft = ((temp >> (i + 1)) << i);
        totalRight = ((1LL << i) - 1);
      }

      ll totalCase = totalLeft + totalRight;

      answer += totalCase + 1;
      answer %= MOD;
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

  ll N, M;
  cin >> N >> M;

  ll answer = solution(N, M);

  cout << answer << endl;

  return 0;
}