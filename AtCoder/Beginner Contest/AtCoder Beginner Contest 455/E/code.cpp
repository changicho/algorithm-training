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

long long countTreeSame(int size, string& s) {
  long long ret = 0;
  int countA = 0, countB = 0, countC = 0;

  function<long long(int, int)> getKey = [](int a, int b) {
    return a * 1e6 + b;
  };

  unordered_map<long long, int> count;
  count[getKey(0, 0)] = 1;

  for (char& c : s) {
    if (c == 'A') {
      countA++;
    } else if (c == 'B') {
      countB++;
    } else if (c == 'C') {
      countC++;
    }

    int AB = countA - countB;
    int BC = countB - countC;

    long long key = getKey(AB, BC);
    ret += count[key];
    count[key]++;
  }
  return ret;
}

long long countTwoSame(int size, string& s, char first, char second) {
  long long ret = 0;
  unordered_map<int, int> count;
  count[0] = 1;
  int countFirst = 0;
  int countSecond = 0;
  for (char& c : s) {
    if (c == first) {
      countFirst++;
    } else if (c == second) {
      countSecond++;
    }

    int diff = countFirst - countSecond;
    ret += count[diff];

    count[diff]++;
  }
  return ret;
}

long long solution(int size, string& s) {
  long long allCase = 1LL * (size) * (size + 1) / 2;
  // A==B || B==C || C==A
  long long sameCase = countTwoSame(size, s, 'A', 'B') +
                       countTwoSame(size, s, 'B', 'C') +
                       countTwoSame(size, s, 'C', 'A');
  long long allSameCase = countTreeSame(size, s);

  return allCase - (sameCase - 2 * allSameCase);
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  string S;
  cin >> S;

  auto answer = solution(N, S);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}