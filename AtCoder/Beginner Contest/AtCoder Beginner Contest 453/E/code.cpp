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

static const int MOD = 998244353;

long long factorial[200001];

long long myPow(long long base, long long expo) {
  long long result = 1;

  while (expo > 0) {
    if (expo % 2 == 1) {
      result *= base;
      result %= MOD;
    }
    base = (base * base) % MOD;
    expo /= 2;
  }
  return result;
}

// nCk
long long myCombi(int n, int k) {
  if (k > n || k < 0) return 0;
  if (k == 0 || k == n) return 1;

  long long numer = factorial[n] % MOD;
  long long denom = (factorial[k] * factorial[n - k]) % MOD;

  return numer * myPow(denom, MOD - 2) % MOD;
};

void init() {
  factorial[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    factorial[i] = (factorial[i - 1] * i) % MOD;
  }
}

long long solve(int size, const vector<int>& lefts, const vector<int>& rights) {
  vector<int> diffA(size + 2);
  vector<int> diffB(size + 2);
  vector<int> diffBoth(size + 2);

  for (int i = 0; i < size; i++) {
    // A
    {
      diffA[lefts[i]]++;
      diffA[rights[i] + 1]--;
    }

    // B
    {
      int l = size - rights[i];
      int r = size - lefts[i];
      if (l <= r) {
        diffB[l]++;
        diffB[r + 1]--;
      }
    }

    // both
    {
      int l = max(lefts[i], size - rights[i]);
      int r = min(rights[i], size - lefts[i]);
      if (l <= r) {
        diffBoth[l]++;
        diffBoth[r + 1]--;
      }
    }
  }

  vector<int> canA(size + 1), canB(size + 1), canBoth(size + 1);

  for (int teamA = 1; teamA <= size - 1; teamA++) {
    canA[teamA] = canA[teamA - 1] + diffA[teamA];
    canB[teamA] = canB[teamA - 1] + diffB[teamA];
    canBoth[teamA] = canBoth[teamA - 1] + diffBoth[teamA];
  }

  long long answer = 0;

  for (int teamA = 1; teamA <= size - 1; teamA++) {
    int teamB = size - teamA;

    int both = canBoth[teamA];
    int onlyA = canA[teamA] - both;
    int onlyB = canB[teamA] - both;
    int neither = size - (onlyA + onlyB + both);

    if (onlyA > teamA) continue;
    if (onlyB > teamB) continue;
    if (neither > 0) continue;

    int need = teamA - onlyA;
    if (need < 0 || need > both) continue;

    answer = (answer + myCombi(both, need)) % MOD;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  init();

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<int> L(N), R(N);
  for (int i = 0; i < N; i++) {
    cin >> L[i] >> R[i];
  }

  auto answer = solve(N, L, R);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}